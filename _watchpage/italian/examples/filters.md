---
layout: examples
order: 601
depth: 2
title: Filters
---
# Filters

Quelli seguenti sono alcuni esempi di come utilizzare i
[Filters]({% link _watchpage/italian/docs/filters.md %})
nei file di configurazione.

```yaml
NAME: watchpage
URL: github:muflone/watchpage
PARSER: html5lib
TYPE: links
ABSOLUTE_URLS: true
STATUS: true
```

Per una migliore comprensione puoi effettuare i test utilizzando questo
file di configurazione iniziale:

```shell
watchpage --config test.yaml --result . --dump
```

Questo restituirà automaticamente tutti i collegamenti nella pagina
https://github.com/muflone/watchpage e i Filters seguenti saranno usati
per ottenere o trasformare i risultati fino a ottenere quanto necessario.

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

Restituirà soltanto i collegamenti che iniziano con
https://github.com/muflone/watchpage/tree/master/ con i risultati seguenti:

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

Restituirà soltanto i collegamenti che iniziano con https://pypi.org/
ma che non iniziano con gli altri pattern, con i risultati seguenti:

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

Restituirà soltanto i collegamenti che terminano con .zip
con i risultati seguenti:

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

Restituirà soltanto i collegamenti che inziano con https://pypi.org/
ma che non terminano con gli altri pattern, con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa
/watchpage/tree/master/ con i risultati seguenti:

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

Restituirà soltanto i collegamenti contenenti la stringa /watchpage/
ma non quelli contenenti la stringa github.com con i seguenti risultati:

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

Restituirà soltanto i collegamenti che corrispondono all'espressione
regolare indicata, con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa /watchpage tranne
quelli corrispondenti all'espressione regolare indicata, con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com
e per ciascuno di essi rimuoverà i caratteri specificati, sia dall'inizio che
dalla fine, con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com
e per ciascuno di essi rimuoverà i caratteri specificati, dall'inizio del
testo, con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi rimuoverà i caratteri specificati, dalla fine del testo,
con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi rimuoverà i caratteri specificati dall'inizio del testo e
quindi aggiungerà la stringa https:// all'inizio con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi rimuoverà i caratteri specificati dalla fine del testo e
quindi aggiungerà la stringa /watchpage/ alla fine con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi rimuoverà la stringa specificata con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi rimuoverà la stringa specificata all'inizio del testo
con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi rimuoverà la stringa specificata dalla fine del testo
con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi sostituirà la stringa /watchpage/ con /gwakeonlan/
con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi restituirà il testo invertito con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa
pypi.org/project/WatchPage e per ciascuno di essi restituirà il testo
in maiuscolo con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa
pypi.org/project/WatchPage e per ciascuno di essi restituirà il testo
in minuscolo con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi restituirà i primi 23 caratteri con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi restituirà gli ultimi 26 caratteri con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi sostituirà l'espressione regolare specificata col nuovo
valore con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi estrarrà il risultato dell'espressione regolare specificata
con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi aggiungerà il testo JSON specificato, limitando i risultati
al solo testo JSON, estraendo il valore ed eliminando le virgolette intorno
con i risultati seguenti:

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

Restituirà soltanto i collegamenti che contengono la stringa www.muflone.com e
per ciascuno di essi aggiungerà il testo JSON specificato, limitando i risultati
al solo testo JSON, estraendo il secondo valore della lista e quindi da esso
estraendo il valore ed eliminando le virgolette intorno con i risultati seguenti:

```
Data 2
```

---
