---
layout: page
title: Flux C Examples
permalink: /
---

# Welcome to Flux C Examples!

<img src="assets/img/Flux-logo-full.png" alt="assets/img/Flux-logo-full.png" width="50%">

## Purpose

This is a starting point if you want to learn to interact with Flux in your own
C or C++ code! Flux Framework's [core](https://github.com/flux-framework/flux-core)
is written in primarily C (with little bits of Python) so the examples here are provided
to show explicit use cases that you might be interested in. This repository provides
an example project for achieving this [in the root]({{ site.repo }})
and the examples are also shared in these pages.

See the {% include doc.html name="Getting Started" path="getting-started" %} guide for
setting up your development environment and basic interactions. If you'd like 
to request a feature or contribute? [Open an issue]({{ site.repo }}/issues)

## Examples

<ul>
{% for ex in site.examples %}
<li><a href="{{ site.baseurl }}/{{ ex.url }}">{{ ex.title }}</a>: {{ ex.description }}</li>
{% endfor %}
<ul>
