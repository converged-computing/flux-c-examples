# Flux C Examples

> 🐚️ If you hold me up to your ear, can you hear the C?

This is a small example of interacting with Flux Framework to submit jobs (and other simple tasks)
using c! 

🚧️ Under Development! 🚧️

Read our 🌈️ [Early Documentation](https://converged-computing.github.io/flux-c-examples/) 🌈️ to get started!

## Examples

 - [submit](src/submit.c): Submit a job!

### Adding an Example

You can add your examples anywhere in the codebase here (e.g., typically under [src](src)). We ask that:

 - You add a test for your contribution that will be run in our development environment with Flux. See [test](test) for examples.
 - That you add a new example page in [docs/_examples](docs/_examples).
 
Within each rendered example, we render the content directly from GitHub, meaning you include
the relative path to your file via a Jekyll include:

```
{% include snippet.html language="cpp" id="submit" path="src/submit.c" %}
```

This means that you can largely copy another page and it will show up on the site as a new
example! The table of contents in [docs/_data/toc.yml](docs/_data/toc.yml) also needs to be updated.
With this simple approach, we have example here that are both tested and render live in the
web interface. Thank you!

**Note** for future developers - the highlight syntax requires a special JS import in
the [_layouts/snippet-page.html](_layouts/snippet-page.html). If you add a language you
will need to add a file!

## License

HPCIC DevTools is distributed under the terms of the MIT license.
All new contributions must be made under this license.

See [LICENSE](https://github.com/converged-computing/cloud-select/blob/main/LICENSE),
[COPYRIGHT](https://github.com/converged-computing/cloud-select/blob/main/COPYRIGHT), and
[NOTICE](https://github.com/converged-computing/cloud-select/blob/main/NOTICE) for details.

SPDX-License-Identifier: (MIT)

LLNL-CODE- 842614
