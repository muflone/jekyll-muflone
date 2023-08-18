---
layout: documentation
order: 511
depth: 2
title: Options
nav_prefix: Command-line
---
# Command-line options

**WatchPage** is a command-line utility and requires some arguments and
options. The arguments and options between square brackets are optional.

For some usage examples please see the
[Examples]({% link _watchpage/english/examples/index.md %}) page.

## Usage

```shell
$ watchpage --help
```

```shell
watchpage [-h] [-V] --config CONFIG --results RESULTS [--dump] [--agent AGENT]

Watch webpages for changes

options:
  -h, --help         show this help message and exit
  -V, --version      show program's version number and exit

Configuration:
  --config CONFIG    configuration file
  --results RESULTS  directory to store the results
  --dump             dump results and discard changes
  --agent AGENT      default user agent
```

## Options

| Flag       | Description                                       | Required |
|:-----------|:--------------------------------------------------|:--------:|
| `--config` | Specifies the YAML configuration file to use      |   Yes    |
| `--result` | Specifies the directory where to save the results |   Yes    |
| `--dump`   | Only show the results without saving them         |    No    |
| `--agent`  | Specifies the default User-Agent                  |    No    |

## Configuration file

The configuration file will be used to get the targets to process and for each
target the options to use.
You can refer to the
[Configuration format]({% link _watchpage/english/docs/configuration.md %})
for detailed information about the configuration file format.

## Results directory

The results directory is used to specify where to save the results for each
target.
For each target will be created a file with extension **.txt**  with the
latest saved results.
Each check will then compare the results with the previous results from the
results directory.

Passing the `--dump` argument you can avoid to save the new results and simply
compare the results with the previous results. This is useful to help you write
the configuration file without saving the results.

## User-Agent

The argument `--agent` will be used as default User-Agent for the HTTP/HTTPS
requests. If not specified it will use the default WatchPage User-Agent.
You can also pass `""` to omit the default User-Agent.

The default User-Agent is **WatchPage** followed by the version number, but you
can specify any desired default User-Agent using
`--agent 'User-Agent'`

You can also override the default User-Agent for each target in the
configuration file.
