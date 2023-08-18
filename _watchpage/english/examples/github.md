---
layout: examples
order: 602
depth: 2
title: GitHub
---
# Get all tags from a GitHub repository (version 1)

```yaml
NAME: watchpage
URL: https://github.com/muflone/watchpage/tags
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: '/archive/refs/tags/'
STATUS: true
```

---
# Get all tags from a GitHub repository (version 2)

```yaml
NAME: watchpage
URL: github:muflone/watchpage/tags
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: '/archive/refs/tags/'
STATUS: true
```

---
# Get all tags from a GitHub repository (version 3)

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: github-tags
ABSOLUTE_URLS: true
STATUS: true
```

---
# Get all tags from a GitHub repository in .zip format

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: github-tags-zip
ABSOLUTE_URLS: true
STATUS: true
```

---
# Get all tags from a GitHub repository in .tar.gz format

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: github-tags-tgz
ABSOLUTE_URLS: true
STATUS: true
```

---
# Get the latest release from a GitHub repository

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: github-tags-tgz
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: '/releases/tag/'
STATUS: true
```

---
# Get all the files for a release on GitHub repository

```yaml
NAME: watchpage
URL: github:muflone/watchpage/releases/expanded_assets/0.4.1
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
STATUS: true
```

---
