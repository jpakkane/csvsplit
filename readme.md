# Demo program for splitting CSV files

A simple program to parse CSV files using the [psplit
library](https://github.com/jpakkane/psplit). The code does not really
do much, this is more of an example of how you'd use Meson's automatic
dependency manager to use a dependency directly from upstream's Git
repository.

## To build and run

```
meson build
meson compile -C build
build/csvsplit data.csv
```

When building with Visual Studio the above commands must be run in the
developer tools command prompt.
