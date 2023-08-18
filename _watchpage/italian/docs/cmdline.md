---
layout: documentation
order: 511
depth: 2
title: Opzioni
nav_prefix: Riga di comando
---
# Opzioni di riga di comando

**WatchPage** è un'utilità a riga di comando e richiede alcuni argomenti e
opzioni. Argomenti e opzioni tra parentesi quadre sono opzionali.

Per alcuni esempi di utilizzo vedi la pagina
[Esempi di utilizzo]({% link _watchpage/italian/examples/index.md %}).

## Utilizzo

```shell
$ watchpage --help
```

```shell
watchpage [-h] [-V] --config CONFIG --results RESULTS [--dump] [--agent AGENT]

Watch webpages for changes

options:
  -h, --help         show this help message and exit
  -V, --version      show program's version number and exit

Configuration:
  --config CONFIG    configuration file
  --results RESULTS  directory to store the results
  --dump             dump results and discard changes
  --agent AGENT      default user agent
```

## Opzioni

| Flag       | Descrizione                                       | Obbligatorio |
|:-----------|:--------------------------------------------------|:------------:|
| `--config` | Specifica il file di configurazione YAML da usare |      Sì      |
| `--result` | Specifica dove salvare i risultati                |      Sì      |
| `--dump`   | Mostra soltanto i risultati senza salvarli        |      No      |
| `--agent`  | Specifica lo User-Agent predefinito               |      No      |

## File di configurazione

Il file di configurazione sarà usato per ottenere gli obiettivi da elaborare e
per ciascun obiettivo le opzioni da utilizzare.
Fare riferimento alla pagina
[Formato della configurazione]({% link _watchpage/italian/docs/configuration.md %})
per informazioni dettagliate sul formato del file di configurazione.

## Directory dei risultati

La directory dei risultati è utilizzata per specificare dove salvare i risultati
per ogni obiettivo.
Per ciascun obiettivo sarà creato un file con estensione **.txt** con gli
ultimi risultati salvati.
Ciascun controllo quindi confronterà i risultati con quelli precedenti dalla
directory dei risultati.

Passando l'argomento `--dump` puoi evitare il salvataggio dei risultati e
semplicemente confrontare i risultati con quelli precedenti. Ciò diventa utile
per aiutarti a scrivere il file di configurazione senza salvare i risultati.

## User-Agent

L'opzione `--agent` può essere usata per indicare lo User-Agent predefinito
per le richieste HTTP/HTTPS. Se non specificata sarà usato lo User-Agent
predefinito. È possibile passare `""` per omettere lo User-Agent predefinito.

Lo User-Agent predefinito è **WatchPage** seguito dal numero di versione, ma è
possibile specificare qualsiasi User-Agent predefinito utilizzando
`--agent 'User-Agent'`

È anche possibile sostituire lo User-Agent predefinito per ciascun obiettivo
nel file di configurazione.
