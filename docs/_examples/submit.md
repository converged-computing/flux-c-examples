---
title: Submit
layout: snippet-page
description: How to submit a job to Flux
---

# Submit Example

Here is an example of how to submit a job. Each of the files below is provided in
completion, meaning that they include all of the headers that are necessary
to build with Flux.

## Example

To submit a job, you will first want to create a [jobspec](https://flux-framework.readthedocs.io/projects/flux-rfc/en/latest/spec_25.html).
This is a specification for a job in Flux, and it comes down to a json
object with a series of expected fields describing the job you want to submit
(e.g., command, environment) and then the resources that you need. The example
below shows creating your own `JobSpec` type to interact with from a command,
submitting it, and then interacting with the Flux job to check status and cleanup.

{% include snippet.html language="c" id="submit" path="src/submit.c" %}

After you compile the above (see the included Makefile) you can start a flux instance:

```bash
$ flux start --test-size=4
```

and then run submit, providing your command of interest as arguments.

```bash
$ ./bin/submit echo hello blueberry pancakes
```
```console
8725830041600: OK
```

You can then easily see the job:

```bash
$ flux jobs -a
```
```console
       JOBID USER     NAME       ST NTASKS NNODES     TIME INFO
   ƒ4xDLio1q vscode   echo       CD      1      1   0.020s 12c9a5ea7110
```

And the output!

```bash
$ flux job attach ƒ4xDLio1q
```
```console
hello blueberry pancakes
```

Of course you would likely use this in your own library, and do something more
interesting! More examples coming soon!

