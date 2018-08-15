---
layout: article
title: Tipologie dei processi di backup
slug: backup-level
category: italian
tags:
  - bareos
keywords: bareos, backup, level, completo, full, differenziale, differential,
          incrementale, incremental, differences
description: 'Le tipologie dei processi di backup: Completo, Differenziale, Incrementale'
order: 503
date: 2018-08-16T00:00:00Z
---

{:.center}
![Bareos logo](/resources/articles/bareos/logo.png)

# Tipologie dei processi di backup

Esistono tre tipologie differenti di backup, dette anche **Backup Level**:

## Completo/Full

Si tratta di un backup completo e totale di tutti i file interessati, ovvero
una copia completa di tutti i dati.

## Differenziale

Si tratta di un backup composto soltanto dai file modificati in seguito
all'ultimo backup Full.
Per semplificare il concetto, ipotizzando un backup eseguito una volta al
giorno, avremmo un backup così composto:

  - lunedì avremmo un backup Full
  - martedì un backup dei file modificati tra lunedì e martedì
  - mercoledì un backup dei file modificati tra lunedì e mercoledì
  - giovedì un backup dei file modificati tra lunedì e giovedì
  - venerdì un backup dei file modificati tra lunedì e venerdì
  - sabato un backup dei file modificati tra lunedì e sabato.

## Incrementale

Si tratta di un backup composto soltanto dai file modificati in seguito
all'ultimo backup, sia esso Full sia Incrementale, sia Differenziale.  
Ipotizzando un backup eseguito una volta al giorno, avremmo un processo così
organizzato:

  - martedì un backup dei file modificati tra lunedì e martedì
  - mercoledì un backup dei file modificati tra martedì e mercoledì
  - giovedì un backup dei file modificati tra mercoledì e giovedì
  - venerdì un backup dei file modificati tra giovedì e venerdì
  - sabato un backup dei file modificati tra venerdì e sabato

E' così implicito che i backup Full sono quelli che occuperanno più spazio,
quelli Differenziali inizieranno piccoli e diverranno ogni giorno più grandi
fino al prossimo backup Full, infine i backup Incrementali sono i più piccoli
poiché copiano soltanto i dati modificati dopo il precedente backup.

>>>>> I backup Differenziali e Incrementali senza i backup Full precedenti non
sono utilizzabili, i dati non modificati negli ultimi giorni potrebbero non
essere affatto presenti all'interno dell'ultimo backup e dovranno essere
ricercati nei backup precedenti. Per questo motivo questi due tipi di backup
necessitano i backup precedenti per ottenere l'elenco completo di tutti i dati.
