#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <flux/core.h>

extern char **environ;

int main (int argc, char *argv[])
{
    flux_jobspec1_t *jobspec;
    flux_future_t *f;
    flux_t *h;
    flux_jobid_t id;
    char *spec;
    int ntasks = 1;
    int cores_per_task = 1;
    int gpus_per_task = 0;
    int nnodes = 0;         /* unset nnodes, let scheduler pick */
    double duration = 0.0;  /* unlimited duration               */
    bool success;
    const char *errstr;

    if (!(jobspec = flux_jobspec1_from_command (argc-1,
                                                argv+1,
                                                environ,
                                                ntasks,
                                                cores_per_task,
                                                gpus_per_task,
                                                nnodes,
                                                duration))) {
        fprintf (stderr, "flux_jobspec1_from_command failed\n");
        exit (1);
    }
    if (!(spec = flux_jobspec1_encode (jobspec, 0))) {
        fprintf (stderr, "flux_jobspec1_encode failed\n");
        exit (1);
    }
    flux_jobspec1_destroy (jobspec);

    if (!(h = flux_open (NULL, 0))) {
        fprintf (stderr, "flux_open: %s\n", strerror (errno));
        exit (1);
    }
    if (!(f = flux_job_submit (h, spec, 16, FLUX_JOB_WAITABLE))) {
        fprintf (stderr, "flux_job_submit: %s\n", strerror (errno));
        exit (1);
    }
    free (spec);

    if (flux_job_submit_get_id (f, &id) < 0) {
        fprintf (stderr, "job submission failed: %s\n",
                 future_strerror (f, errno));
        exit (1);
    }
    flux_future_destroy (f);

    if (!(f = flux_job_wait (h, id))) {
        fprintf (stderr, "flux_job_wait: %s\n", strerror (errno));
        exit (1);
    }
    if (flux_job_wait_get_status (f, &success, &errstr) < 0) {
        fprintf (stderr, "flux_job_wait_get_status: %s\n",
                 future_strerror (f, errno));
        exit (1);
    }
    if (success)
        fprintf (stdout, "%ju: OK\n", (uintmax_t) id);
    else {
        fprintf (stderr, "%ju: %s\n", (uintmax_t) id, errstr);
        exit (1);
    }
    flux_future_destroy (f);
    flux_close (h);
    return 0;
}
