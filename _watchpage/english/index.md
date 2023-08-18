---
layout: index
order: 100
title: Introduction
---
**Watchpage** is a command-line tool to monitor the changes to webpages
groups.
It's designed to ease the software maintainers job and to monitor the
projects' websites changes in order to get the newer versions links.

The configuration is done using files in [YAML] format containing one or more
targets to check. For each target you can define some filters to use to get
the results:

```yaml
NAME: monitor-watchpage
URL: https://github.com/muflone/watchpage/tags
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - STARTS: 'https://github.com/muflone/'
  - ENDS: '.tar.gz'
STATUS: true
---
```

The previous example describes a configuration file contaning a target named
**monitor-watchpage** which will check the webpage
`https://github.com/muflone/watchpage/tags` using the html5lib parser,
getting all the links in the page, making them absolute and it will filter
only those starting with `https://github.com/muflone/` and ending with
`.tar.gz`

All the resulting data from this verification will be compared with the previous
results and the differences will be shown (the newer or the links modified after
the previous check).

>>>>>> A configuration file can include one or more targets to monitor
>>>>>> separated by three dashes at the bottom.

To use the configuration file it's also needed to specify where to save the
results from the checks, in order to be able to get the differences for the next
checks.

```shell
$ watchpage --config watchpage.yaml --result ~/.cache/watchpage
```

The produced result will be similar to the following:

```
Target: monitor-watchpage
URL: https://github.com/muflone/watchpage/tags
Date: 2023-08-17 15:33.21

https://github.com/muflone/watchpage/archive/refs/tags/0.1.0.tar.gz
https://github.com/muflone/watchpage/archive/refs/tags/0.1.1.tar.gz
https://github.com/muflone/watchpage/archive/refs/tags/0.1.2.tar.gz
https://github.com/muflone/watchpage/archive/refs/tags/0.2.0.tar.gz
https://github.com/muflone/watchpage/archive/refs/tags/0.3.0.tar.gz
-------------------------------------------------------------------------------
```

>>>>> The same results will be saved in a results file with the same name
>>>>> of the target in the YAML file, for this example the results will be
>>>>> saved in a file named **monitor-watchpage.txt**.

On the next WatchPage execution with the same configuration file the results
will be compared with the previous file results and only the eventual
differences will be shown.

For example:

```
Target: monitor-watchpage
URL: https://github.com/muflone/watchpage/tags
Date: 2023-08-18 17:45.06

https://github.com/muflone/watchpage/archive/refs/tags/0.4.0.tar.gz
-------------------------------------------------------------------------------
```

For a complete arguments list documentation please refer to the
[Documentation]({% link _watchpage/english/docs/index.md %}) and for some usage
examples please see the
[Examples]({% link _watchpage/english/examples/index.md %}) page.

{: target="_blank" .external }
[YAML]: https://yaml.org/
