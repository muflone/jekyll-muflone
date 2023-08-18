---
layout: examples
order: 603
depth: 2
title: SourceForge
---
# Get all downloads from a SourceForge repository

```yaml
NAME: gscan2pdf
URL: https://sourceforge.net/projects/gscan2pdf/rss
PARSER: xml
TYPE: rss
ABSOLUTE_URLS: true
FILTERS:
  - ENDS: '/download'
  - REGEX REPLACE: '/download$'
    WITH: ''
STATUS: true
```

---
# Get all downloads for a specific version from a SourceForge repository

```yaml
NAME: gscan2pdf
URL: https://sourceforge.net/projects/gscan2pdf/rss?path=/gscan2pdf/2.13.2
PARSER: xml
TYPE: rss
ABSOLUTE_URLS: true
FILTERS:
  - ENDS: '/download'
  - REGEX REPLACE: '/download$'
    WITH: ''
STATUS: true
```

---
