# Flux Go Bindings

![img/flux-go-banner.png](img/flux-go-banner.png)

Flux provides a Go interface for use in your packages!
This repository provide an example setup for you to build your own tools (in Go!)
against a Flux installation. If you'd like to request a specific example,
please [let us know](https://github.com/flux-framework/flux-go/issues)

## Development Environment

We recommended that you use the provided (VSCode) DevContainers environment.
This will provide Flux and Go already installed, so you can jump right in
to development! You can follow the [tutorial](https://code.visualstudio.com/docs/remote/containers-tutorial) where you'll basically
need to:

1. Install Docker, or compatible engine
2. Install the [Development Containers](vscode:extension/ms-vscode-remote.remote-containers) extension

Then you can go to the command palette (View -> Command Palette) and select `Dev Containers: Open Workspace in Container.`
This will build a development environment from [fluxrm/flux-sched](https://hub.docker.com/r/fluxrm/flux-sched/tags).

You are free to change the base image and rebuild if you need to test on another operating system!
When your container is built, when you open `Terminal -> New Terminal`, surprise! You're
in the container! 

**Important** the development container assumes you are on a system with uid 1000 and gid 1000. If this isn't the case,
edit the [.devcontainer/Dockerfile](../.devcontainer/Dockerfile) to be your user and group id. This will ensure
changes written inside the container are owned by your user. It's recommended that you commit on your system
(not inside the container) because if you need to sign your commits, the container doesn't
have access and won't be able to. If you find that you accidentally muck up permissions
and need to fix, you can run this from your terminal outside of VSCode:

```bash
$ sudo chown -R $USER .git/
# and then commit
```

## Building Bindings

You can build the examples using the [Makefile](../Makefile). You can inspect it 
to see how simple it is - we target the Flux install in the container (and you
would want to customize this based on your install of Flux).

```bash
$ make
```

This will create a `bin` in the root directory, and each executable demonstrates 
an example that you can match to a command file in `cmd`.  For any of the examples
below, since the container starts running a flux instance, you won't need to start
one. If you are developing (and an instance isn't started) you can do:

```bash
$ flux start --test-size=4
```

### Submit Example

Here is an example of running submit. You will need to start a flux instance,
as shown above. You can target this executable:

```bash
$ ./bin/fluxgo-submit 
```
```console
⭐️ Testing flux submit in Go! ⭐️
Submitting a Sleep Job: sleep 10
Flux Future: &{{{}}}
```

And see it running!

```bash
$ flux jobs -a
```
```console
       JOBID USER     NAME       ST NTASKS NNODES     TIME INFO
    ƒdcsg8Nj vscode   sleep       R      1      1   2.728s 5e3ccb811e04
```

We likely will add more output from the job (e.g., the identifier) and metadata,
but for now you can use `flux jobs` to see that the job ran (above) and completed:

```bash
$ flux jobs -a
       JOBID USER     NAME       ST NTASKS NNODES     TIME INFO
   ƒ3Mop5847 vscode   sleep      CD      1      1   10.04s 3da6fb865c22
```

Of course you would likely use this in your own library, and do something more
interesting! More examples coming soon!

### KeyGen Example

The keygen example doesn't require a flux instance to be running! 
You can generate a local `curve.cert` as follows:

```bash
$ ./bin/fluxgo-keygen 
```
```console
⭐️ Testing flux keygen in Go! ⭐️
Saving to ./curve.cert
Generated certificate!
```

And view the certificate:

```bash
$ cat ./curve.cert 
```
```console
#   ****  Generated on 2023-04-25 22:04:45 by CZMQ  ****
#   ZeroMQ CURVE **Secret** Certificate
#   DO NOT PROVIDE THIS FILE TO OTHER USERS nor change its permissions.

metadata
    name = "curve-cert"
    keygen.hostname = "5e3ccb811e04"
curve
    public-key = "S%XP&s=}d*EQDZ!Vef-Q6OCjW+>I+cR.s*gzqwkl"
    secret-key = "17P&8}*hoc-sTHk6m}i3mL{OG=9j!o*9:8nmuJEM"
```
