---
layout: examples
order: 601
depth: 2
title: Filters
---
# Filters

The following are some examples how to use the
[filters]({% link _watchpage/english/docs/filters.md %})
in the configuration files.

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
STATUS: true
```

For a better understanding you can do the tests using this initial
configuration file:

```shell
watchpage --config test.yaml --result . --dump
```

It will automatically return all the links in the page
https://github.com/muflone/watchpage and the following filters will be
used to get or transform the results until you get what you need.

## STARTS

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - STARTS: 'https://github.com/muflone/watchpage/tree/master/'
STATUS: true
```

Will return only the links starting with
https://github.com/muflone/watchpage/tree/master/ with the following results:

```
https://github.com/muflone/watchpage/tree/master/.circleci
https://github.com/muflone/watchpage/tree/master/icons
https://github.com/muflone/watchpage/tree/master/watchpage
```

---

### NOT STARTS
```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - STARTS: 'https://pypi.org/'
  - NOT STARTS: 'https://pypi.org/project/PyYAML/'
  - NOT STARTS: 'https://pypi.org/project/beautifulsoup4/'
  - NOT STARTS: 'https://pypi.org/project/html5lib/'
  - NOT STARTS: 'https://pypi.org/project/lxml/'
STATUS: true
```

Will return only the links starting with https://pypi.org/
but not starting with the other patterns, with the following results:

```
https://pypi.org/project/WatchPage/
```

---

## ENDS

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - ENDS: '.zip'
STATUS: true
```

Will return only the links ending with .zip
with the following results:

```
https://github.com/muflone/watchpage/archive/refs/heads/master.zip
```

---

## NOT ENDS

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - STARTS: 'https://pypi.org/'
  - NOT ENDS: '/PyYAML/'
  - NOT ENDS: '/beautifulsoup4/'
  - NOT ENDS: '/html5lib/'
  - NOT ENDS: '/lxml/'
STATUS: true
```

Will return only the links starting with https://pypi.org/
but not ending with the other patterns, with the following results:

```
https://pypi.org/project/WatchPage/
```

---

## CONTAINS

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: '/watchpage/tree/master/'
STATUS: true
```

Will return only the links containing the string
/watchpage/tree/master/ with the following results:

```
https://github.com/muflone/watchpage/tree/master/.circleci
https://github.com/muflone/watchpage/tree/master/icons
https://github.com/muflone/watchpage/tree/master/watchpage
```

---

## NOT CONTAINS

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: '/watchpage/'
  - NOT CONTAINS: 'github.com'
STATUS: true
```

Will return only the links containing the string /watchpage/
but not those containing the string github.com with the following results:

```
http://www.muflone.com/watchpage/
```

---

## REGEX

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - REGEX: '^(http|https):\/\/github\.com\/.*/watchpage\/tree\/master\/'
STATUS: true
```

Will return only the links matching the specified regular expression
with the following results:

```
https://github.com/muflone/watchpage/tree/master/.circleci
https://github.com/muflone/watchpage/tree/master/icons
https://github.com/muflone/watchpage/tree/master/watchpage
```

---

## NOT REGEX

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: '/watchpage'
  - NOT REGEX: '(github|circleci)'
STATUS: true
```

Will return only the links containing the string /watchpage but not matching
the specified regular expression with the following results:

```
http://www.muflone.com/watchpage/
```

---

## TRIM

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - TRIM: '/:.watchpge'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will remove the specified characters, both from the start and the
end, with the following results:

```
muflone.com
```

---

## LTRIM

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - LTRIM: ':/htp'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will remove the specified characters, from the text start, with
the following results:

```
www.muflone.com/watchpage/
```

---

## RTRIM

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - RTRIM: '/watchpge'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will remove the specified characters, from the text end, with
the following results:

```
http://www.muflone.com
```

---

## PREPEND

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - LTRIM: ':/htp'
  - PREPEND: 'https://'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will remove the specified characters, from the text start and then
will add the string https:// at the start with the following results:

```
https://www.muflone.com/watchpage
```

---

## APPEND

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - RTRIM: '/watchpge'
  - APPEND: '/watchpage/'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will remove the specified characters, from the text end and then
will add the string /watchpage/ at the end with the following results:

```
http://www.muflone.com/watchpage/
```

---

## REMOVE

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - REMOVE: 'www.'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will remove the specified string with the following results:

```
http://muflone.com/watchpage/
```

---

## REMOVE LEFT

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - REMOVE LEFT: 'http://'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will remove the specified string from the text start
with the following results:

```
www.muflone.com/watchpage/
```

---

## REMOVE RIGHT

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - REMOVE RIGHT: 'watchpage/'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will remove the specified string from the text end
with the following results:

```
http://www.muflone.com/
```

---

## REPLACE

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - REPLACE: '/watchpage/'
    WITH: '/gwakeonlan/'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will replace the string /watchpage/ with /gwakeonlan/
with the following results:

```
http://www.muflone.com/gwakeonlan/
```

---

## REVERSE

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - REVERSE:
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will reverse the text with the following results:

```
/egaphctaw/moc.enolfum.www//:ptth
```

---

## UPPER

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'pypi.org/project/WatchPage'
  - UPPER:
STATUS: true
```

Will return only the links containing the string
pypi.org/project/WatchPage and for each one of them will make the text as
upper case with the following results:

```
HTTPS://PYPI.ORG/PROJECT/WATCHPAGE/
```

---

## LOWER

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'pypi.org/project/WatchPage'
  - LOWER:
STATUS: true
```

Will return only the links containing the string
pypi.org/project/WatchPage and for each one of them will make the text as
lower case with the following results:

```
https://pypi.org/project/watchpage/
```

---

## LEFT

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - LEFT: 23
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will return the first 23 characters with the following results:

```
http://www.muflone.com/
```

---

## RIGHT

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - RIGHT: 26
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will return the latest 26 characters with the following results:

```
www.muflone.com/watchpage/
```

---

## REGEX REPLACE

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - REGEX REPLACE: '[w]{3}\.'
    WITH: ''
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will replace the specified regular expression with the new
value with the following results:

```
http://muflone.com/watchpage/
```

---

## REGEX SEARCH

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - REGEX SEARCH: '(http|https):\/\/[w]{3}\.muflone\.com\/'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will extract the result for the specified regular expression
with the following results:

```
http://www.muflone.com/
```

---

## JSON DICT

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - PREPEND: '{ "name": "Test", "value": "This is a sample dictionary" }'
  - LEFT: 58
  - JSON DICT: 'value'
  - TRIM: '"'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will add the specified JSON text, limiting the results to only the
JSON text, extracting the value and removing the surrounding quotes around it
with the following results:

```
This is a sample dictionary
```

---

## JSON LIST

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
FILTERS:
  - CONTAINS: 'www.muflone.com'
  - PREPEND: '[{ "name": "Data 1" }, { "name": "Data 2" }]'
  - LEFT: 44
  - JSON LIST: 1
  - JSON DICT: 'name'
  - TRIM: '"'
STATUS: true
```

Will return only the links containing the string www.muflone.com and for each
one of them will add the specified JSON text, limiting the results to only the
JSON text, extracting the second value from the list and then extracting the
value and removing the surrounding quotes around it with the following results:

```
Data 2
```

---
