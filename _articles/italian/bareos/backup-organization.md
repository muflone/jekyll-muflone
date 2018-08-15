---
layout: article
title: Organizzazione di un processo di backup
slug: backup-organization
category: italian
tags:
  - bareos
keywords: bareos, organizzazione, processo, backup, job, type, level, client,
          fileset, storage, device
description: L'organizzazione di un processo di backup.
order: 504
date: 2018-08-16T00:00:00Z
---

{:.center}
![Bareos logo](/resources/articles/bareos/logo.png)

# Organizzazione di un processo di backup

Premesso che tutte le quattro componenti di base di Bareos devono essere attive,
la procedura di backup di un sistema è composto dalle seguenti parti:

Un client chiamato **File Daemon** viene registrato presso il Director

Sul Director viene configurato un processo di backup chiamato **Job** che
contiene al suo interno varie parti:

- **Type**: il tipo di operazione da eseguire (backup, ripristino)
- **Level**: il tipo di backup (Full, Differenziale, Incrementale)
- **Client**: dove si trovano i file da copiare, ovvero il nome del File Daemon
  già registrato presso il Director
- **FileSet**: l'elenco di file/cartelle da includere o escludere dal backup
- **Storage**: dove inviare i dati copiati
- **Pool**: l'organizzazione dei backup all'interno dello storage
- **Schedule**: quando eseguire l'operazione pianificata di copia


Lo Storage a sua volta contiene:

- **Address**: l'indirizzo dello Storage Daemon, potrebbe essere un sistema
  differente dal Director che coordina il tutto
- **Password**: una parola d'ordine che conferma l'accesso tra lo Storage
  Daemon e il Director per l'accesso allo storage
- **Device**: il dispositivo sul quale copiare i dati
- **Media Type**: il tipo di dispositivo da utilizzare, normalmente *File*
  ma potrebbe essere un'altra tipologia come un nastro oppure un cloud AWS o
  un altro tipo di dispositivo
