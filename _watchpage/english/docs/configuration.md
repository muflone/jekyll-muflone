---
layout: documentation
order: 531
depth: 2
title: Format
nav_prefix: Configuration
---
# Description

A configuration file in [YAML] format is made of one or more targets to check.
It's possible to separate the targets using `---` between them.

Each target defines the webpage to check, the parser to use to analyze the
content, the extraction type to execute, whether to trasform the relative
URLs to absolute URLs (from /address to http://website/address for example),
one or more filters used to extract or transform the results and the target
status, used to enable or disable the target into the
configuration file.

## Targets

Ciascun obiettivo si compone di un indirizzo (URL) da controllare, un parser
usato per analizzare il contenuto dell'URL, un tipo (type) che determina come
interpretare il contenuto della pagina, uno stato (status) che indica se
eseguire le verifiche per l'obiettivo oppure ignorarlo.

Each target has the following definition:

`NAME` a unique name to identify the target

`URL` the page URL to monitor for changes.
You can also specify **github:user/repository** to point to a
GitHub repository

`PARSER` the parser
(see the [Parser page]({% link _watchpage/english/docs/parser.md %}))
to use to process the URL

`TYPE` specify the type of items to extract from the page
(see the [Type page]({% link _watchpage/english/docs/type.md %}))

`ABSOLUTE_URLS` a boolean value (true/false) to make the processed URLs as
absolute by pre-pending the website from the URL

`FILTERS` is a list of filters to apply to find or transform the matched
items
(see the [Filters page]({% link _watchpage/english/docs/filters.md %}))

`HEADERS` a dictionary with the headers to set for the request
(see the [Headers page]({% link _watchpage/english/docs/headers.md %}))

`STATUS` a boolean value (true/false) to enable or disable the target

## Configuration example file

```yaml
NAME: watchpage
URL: https://github.com/muflone/watchpage/tags
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - STARTS: 'https://github.com/muflone/'
  - ENDS: '.tar.gz'
HEADERS:
  User-Agent: 'WatchPage'
  Foo: 'Bar'
STATUS: true
```

{: target="_blank" .external }
[YAML]: https://yaml.org/
