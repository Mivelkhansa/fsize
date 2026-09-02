# fsize

A simple command-line utility for displaying file sizes.

## Features

* Display file sizes
* Recursively process directories
* Human-readable size output
* Command-line help and version information

## Usage

```text
fsize [OPTION]... [FILE]...
```

### Options

```text
-h, --help       display this help and exit
-r, --recursive  recursively process directories
-H, --human      print sizes in human-readable form
-v, --version    display version and exit
```

## Building

Requirements:

* A C compiler such as GCC or Clang
* GNU Make

Build the release version:

```bash
make
```

Build the debug version:

```bash
make debug
```

The compiled binaries are placed in:

```text
build/bin/
```

## Installation

Install `fsize` system-wide:

```bash
sudo make install
```

By default, it is installed to:

```text
/usr/local/bin/fsize
```

You can change the installation prefix:

```bash
make install PREFIX=/usr
```

## Uninstallation

```bash
sudo make uninstall
```

## Cleaning

Remove build files:

```bash
make clean
```

## Version

The program version is stored in the `.VERSION` file and is embedded into the binary during compilation.

## License

See `LICENSE` for license information.
