---
title: Getting Started
tags: 
 - environment
---

# Getting Started

<img src="{{ site.baseurl }}/assets/img/Flux-logo-full.png" alt="{{ site.baseurl }}/assets/img/Flux-logo-full.png" width="50%">


Welcome to the Flux C Examples documentation! This project demonstrates
how to create your own interfaces to interact with Flux for use in your packages!

## Development Environment

We recommended that you use the provided (VSCode) DevContainers environment.
This will provide Flux Core and Security already installed, so you can jump right in
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
edit the [.devcontainer/Dockerfile](https://github.com/converged-computing/flux-go/blob/main/.devcontainer/Dockerfile) 
to be your user and group id. This will ensure
changes written inside the container are owned by your user. It's recommended that you commit on your system
(not inside the container) because if you need to sign your commits, the container doesn't
have access and won't be able to. If you find that you accidentally muck up permissions
and need to fix, you can run this from your terminal outside of VSCode:

```bash
$ sudo chown -R $USER .git/
# and then commit
```

## Building Bindings

You can build the examples using the [Makefile](https://github.com/converged-computing/flux-c-examples/blob/main/Makefile). You can inspect it 
to see how simple it is - we target the Flux install in the container (and you
would want to customize this based on your install of Flux).

```bash
$ make
```

This will create a `bin` in the root directory, and each executable demonstrates 
an example that you can match to a command file in `src`.  For any of the examples
below, since the container starts running a flux instance, you won't need to start
one. If you are developing (and an instance isn't started) you can do:

```bash
$ flux start --test-size=4
```
