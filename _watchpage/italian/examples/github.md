---
layout: examples
order: 602
depth: 2
title: GitHub
---
# Estrarre tutti i tag da un repository di GitHub (versione 1)

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
# Estrarre tutti i tag da un repository di GitHub (versione 2)

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
# Estrarre tutti i tag da un repository di GitHub (versione 3)

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: github-tags
ABSOLUTE_URLS: true
STATUS: true
```

---
# Estrarre tutti i tag da un repository di GitHub in formato .zip

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: github-tags-zip
ABSOLUTE_URLS: true
STATUS: true
```

---
# Estrarre tutti i tag da un repositorys di GitHub in formato .tar.gz

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: github-tags-tgz
ABSOLUTE_URLS: true
STATUS: true
```

---
# Estrarre l'ultimo rilascio da un repository di GitHub

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: '/releases/tag/'
STATUS: true
```

---
# Estrarre tutti i file di un rilascio da un repository di GitHub

```yaml
NAME: watchpage
URL: github:muflone/watchpage/releases/expanded_assets/0.4.1
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
STATUS: true
```

---
