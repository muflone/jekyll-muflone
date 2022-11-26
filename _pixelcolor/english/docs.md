---
layout: default
order: 4
title: Documentation
---

# Command-line options

**PixelColor** is a command-line utility and requires some arguments and
options. The arguments and options between square brackets are optional.

For some usage examples please see the
[Examples]({% link _pixelcolor/english/examples.md %}) page.

## Usage

```shell
pixelcolor [-h] [-V] [--display DISPLAY] [--triplets] [--hex] [--upper] --x X --y Y

options:
  -h, --help         show this help message and exit
  -V, --version      show program's version number and exit

Screen:
  --display DISPLAY  display to grab the pixel
  --x X, -x X        X coordinate to get the pixel color
  --y Y, -y Y        Y coordinate to get the pixel color

Output:
  --triplets, -T     return the color in triplets
  --hex, -H          return the color in hexadecimal format
  --upper, -U        return the result in uppercase
```
