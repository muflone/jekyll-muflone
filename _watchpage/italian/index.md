---
layout: index
order: 100
title: Introduzione
---
**Watchpage** è uno strumento a riga di comando per tenere sotto controllo i
cambiamenti apportati a gruppi di pagine web. È studiato per semplificare il
lavoro dei manutentori di software e monitorare i cambiamenti ai siti dei
progetti e ottenere i collegamenti alle nuove versioni.

La configurazione avviene mediante file in formato [YAML] contenenti all'interno
uno o più obiettivi da controllare. Per ogni obiettivo è possibile definire alcuni
filtri che verranno utilizzati per ottenere i risultati:

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

L'esempio precedente mostra un file di configurazione contenente un obiettivo
di nome **monitor-watchpage** che controllerà la pagina
`https://github.com/muflone/watchpage/tags` utilizzando il parser html5lib,
otterrà tutti i collegamenti della pagina, li renderà assoluti e filtrerà
soltanto quelli che iniziano per `https://github.com/muflone/` e che
terminano in `.tar.gz`

Tutti i dati risultanti da questa verifica verranno confrontati con quelli
precedenti e saranno mostrate le eventuali differenze (quindi i link nuovi o
modificati dopo la verifica precedente).

>>>>>> Un file di configurazione può contenere uno o più obiettivi da
>>>>>> controllare separati da tre trattini in fondo.

Per utilizzare il file di configurazione è necessario anche indicare dove salvare
i risultati del controllo, affinché le successive richieste possano rilevare le
differenze.

```shell
$ watchpage --config watchpage.yaml --result ~/.cache/watchpage
```

Il risultato prodotto sarà simile al seguente:

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

>>>>> Gli stessi risultati verranno salvati in un file di risultati
>>>>> corrispondente al nome dell'obiettivo nel file YAML, in questo
>>>>> esempio i risultati verranno salvati nel file **monitor-watchpage.txt**.

A una successiva esecuzione di WatchPage con lo stesso file di configurazione
verranno confrontati i risultati con quelli presenti nel precedente file di
risultati e saranno mostrate le eventuali differenze.

Ad esempio:

```
Target: monitor-watchpage
URL: https://github.com/muflone/watchpage/tags
Date: 2023-08-18 17:45.06

https://github.com/muflone/watchpage/archive/refs/tags/0.4.0.tar.gz
-------------------------------------------------------------------------------
```

Per una documentazione completa sull'elenco degli argomenti fare riferimento
alla [Documentazione]({% link _watchpage/italian/docs/index.md %}) e per alcuni
esempi di utilizzo vedi la pagina
[Esempi]({% link _watchpage/italian/examples/index.md %}).

{: target="_blank" .external }
[YAML]: https://yaml.org/
