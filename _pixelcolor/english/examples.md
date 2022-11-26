---
layout: default
order: 5
title: Usage examples
---

### Get the pixel color at coordinate 100x300

```shell
$ pixelcolor --x 100 --y 300

13269033
```

### Get the pixel color at coordinate 100x300 as triplets

```shell
$ pixelcolor --x 100 --y 300 --triplets

202 120 41
```

### Get the pixel color at coordinate 100x300 as hexadecimal

```shell
$ pixelcolor --x 100 --y 300 --hex

CA7829
```

### Get the pixel color at coordinate 100x300 as uppercase hexadecimal triplets

```shell
$ pixelcolor --x 100 --y 300 --triplets --hex --upper

CA 78 29
```
