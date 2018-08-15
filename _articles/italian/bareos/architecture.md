---
layout: article
title: Architettura
slug: architecture
category: italian
tags:
  - bareos
keywords: bareos, architettura, componenti, server, web, client, webui, console,
          director, storage, daemon, file, catalog
description: L'architettura di Bareos e a cosa serve ciascun componente di Bareos.
order: 502
date: 2018-08-16T00:00:00Z
---

{:.center}
![Bareos logo](/resources/articles/bareos/logo.png)

# Componenti di Bareos

A causa della sua natura modulare e distribuita, Bareos può operare su più
sistemi contemporaneamente. Per meglio comprendere il suo funzionamento è
fondamentale capire la sua architettura generale, composta di varie componenti:

- **Director**: si occupa di coordinare le varie componenti di Bareos e viene
  utilizzata per eseguire backup, ripristini e le attività programmate.
- **File Daemon** (*FD*): questo modulo si installa sui client da controllare e
  dei quali eseguire backup o ripristini. Il servizio si occupa di comunicare
  col Director e di eseguire i suoi ordini, copiando i dati interessati e
  inviandoli al modulo Storage Daemon.
- **Storage Daemon** (*SD*): si occupa di ricevere i dati dal File Daemon e di
  scriverli sugli storage fisici.
- **Catalog**: corrisponde ad un database archivio delle operazioni eseguite,
  dei file che si trovano all'interno dei backup effettuati e dell'esito delle
  operazioni di copia e ripristino già eseguite.
  
Queste quattro componenti sono alla base di ogni installazione di Bareos e sono
tutte richieste per un corretto funzionamento di qualsiasi installazione.

# Configurazione di Bareos

- **Console** (*bconsole*): si occupa di consentire la configurazione del
  Director tramite riga di comando.
- **WebUI**: è un'interfaccia web di gestione del servizio Director, consente
  di verificare lo stato dei backup e dei ripristini e di eseguire le operazioni
  di backup già configurate.  

>>> A differenza di quasi tutte le altre applicazioni web comunemente utilizzate
la WebUI **non consente** la configurazione completa del servizio di Bareos ma
soltanto di avviare e controllare lo stato di avanzamento dei processi.
