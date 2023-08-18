---
layout: documentation
order: 531
depth: 2
title: Formato
nav_prefix: Configurazione
---
# Descrizione

Un file di configurazione in formato [YAML] si compone di uno o più obiettivi
(target) da controllare. È possibile separare gli obiettivi con `---` tra di loro.

Ciascun obiettivo definisce la pagina web da controllare, il parser utilizzato
per l'analisi dei contenuti, il tipo di estrazione da eseguire, se trasformare
i collegamenti in assoluti (da /indirizzo a http://sito/indirizzo per esempio),
uno o più filtri utilizzati per estrarre o trasformare i risultati e lo stato
dell'obiettivo, usato per abilitare o disabilitare l'obiettivo all'interno del
file di configurazione.

## Obiettivi

Ciascun obiettivo si compone di un indirizzo (URL) da controllare, un parser
usato per analizzare il contenuto dell'URL, un tipo (type) che determina come
interpretare il contenuto della pagina, uno stato (status) che indica se
eseguire le verifiche per l'obiettivo oppure ignorarlo.

La definizione di ciascun obiettivo è la seguente:

`NAME` è un nome univoco che identifica l'obiettivo

`URL` l'indirizzo della pagina da controllare per cambiamenti.
È anche possibile specificare **github:utente/repository** per puntare a un
repository di GitHub

`PARSER` il parser
(vedi la [pagina Parser]({% link _watchpage/italian/docs/parser.md %}))
da utilizzare per elaborare l'URL

`TYPE` specifica il tipo di elementi da estrarre dalla pagina
(vedi la [pagina Type]({% link _watchpage/italian/docs/type.md %}))

`ABSOLUTE_URLS` un valore booleano (true/false) per rendere assoluti gli
indirizzi elaborati aggiungendo il sito web all'indirizzo

`FILTERS` una lista di filtri da applicare per trovare o trasformare gli
elementi corrispondenti
(vedi la [pagina Filters]({% link _watchpage/italian/docs/filters.md %}))

`HEADERS` un dizionario con le intestazioni da assegnare alla richiesta
(vedi la [pagina Headers]({% link _watchpage/italian/docs/headers.md %}))

`STATUS` un valore booleano (true/false) per abilitare o disabilitare l'obiettivo

## File di configurazione di esempio

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
