---
title: Makefile
layout: snippet-page
description: A Makefile example for your project
---

# Makefile Example

Your Makefile will want to have the correct flags that point to the include
and library directories for where you've installed Flux. We found the simple
Makefile, below, to work well in a standard [Flux container](https://hub.docker.com/r/fluxrm/flux-sched/tags) 
that installs everything to `/usr`

{% include snippet.html language="makefile" id="makefile" path="Makefile" %}

