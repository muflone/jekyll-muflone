---
layout: examples
order: 603
depth: 2
title: SourceForge
---
# Estrarre tutti i download da un repository di SourceForge

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
# Estrarre i download di una versione da un repository di SourceForge

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
