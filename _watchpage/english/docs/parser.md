---
layout: documentation
order: 532
depth: 2
title: Parser
---
# Parser

The allowed parsers for the option `PARSER` are the following:

| Name        | Description                                                 |
|:------------|:------------------------------------------------------------|
| html.parser | The default Python parser, moderate speed and compatibility |
| html5lib    | The html5lib library parser, the most compatible but slower |
| lxml        | The lxml library parser for HTML, the faster                |
| xml         | The lxml library parser for XML, the faster                 |

As general rule to check HTML pages the usage of lxml is recommended as it
results to be the faster between them. In case of incompatibilities you can
fallback to html5lib or html.parser.

To check XML pages the usage of xml is recommended.
