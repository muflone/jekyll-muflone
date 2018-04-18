---
layout: article
title: Installazione appliance da file ISO
slug: install-from-iso
category: italian
tags:
  - zabbix
keywords: zabbix, installazione, appliance, iso, download, ubuntu, server
description: Installare Zabbix Appliance da file ISO significa installare un
             nuovo sistema operativo, basato su Ubuntu Server, già pronto e
             configurato per accogliere Zabbix Server.
order: 404
date: 2018-04-18T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

Alla pagina [Download and install Zabbix][Download appliance] è possibile
scaricare una Zabbix Appliance in uno dei tanti formati.

Il file di installazione ISO è una vera e propria immagine di installazione di
**Ubuntu Server** con inclusi i pacchetti di Zabbix.
E' possibile utilizzare questo file per installare una nuova macchina, che verrà
quindi formattata e preparata per accogliere Ubuntu e Zabbix.

>>> L'installazione di Zabbix Appliance comporta la cancellazione, **senza
alcuna conferma**, di tutti i dati presenti nei dischi rilevati.

{:.center}
![Avvio dell'installazione di Zabbix Appliance](/resources/articles/zabbix/install-from-iso/01.png)

All'avvio del sistema dal disco di installazione verrà richiesto se installare:

* Ubuntu Server con Zabbix Server e database MySQL
* Ubuntu Server con Zabbix Server e database PostgreSQL
* Ubuntu Server con Zabbix Proxy e database MySQL
* Ubuntu Server con Zabbix Proxy e database SQLite3

Effettuare la scelta con una delle prime due opzioni, il database scelto non
cambia il funzionamento del sistema.

{:.center}
![Installazione di Ubuntu Server](/resources/articles/zabbix/install-from-iso/02.png)

La procedura proseguirà automaticamente con la reinstallazione del sistema
operativo Ubuntu Server e con esso dei pacchetti necessari a Zabbix.

>>>>> L'operazione richiede la presenza di una connessione internet, in caso
contrario non proseguirà correttamente e non installerà i pacchetti necessari.

Al termine dell'installazione il sistema si riavvierà automaticamente. Col
riavvio saranno automaticamente avviati tutti i servizi necessari.

>>>>>> Normalmente non è necessario accedere al sistema operativo Ubuntu Server
ma qualora divenisse necessario i dati di accesso al sistema Ubuntu sono i
seguenti:  
**Utente**: appliance  
**Password**: zabbix

{:.center}
![Accesso al server locale](/resources/articles/zabbix/install-from-iso/03.png)

L'indirizzo IP alla macchina appena installata sarà fornito automaticamente via
DHCP ma nel caso non fosse noto è possibile accedere alla console del server
ed eseguire il comando ```ip a```, nell'esempio l'indirizzo è 192.168.1.67.

Per accedere al sistema basterà quindi avviare un browser da un'altra postazione
e puntare alla pagina http://INDIRIZZO_SERVER/zabbix

{:.center}
![Zabbix login](/resources/articles/zabbix/login.png)

La configurazione iniziale è terminata ed è il momento di
[passare ad utilizzare il nostro Zabbix][Frontend first view].

{: target="_blank" .external }
[Download appliance]: https://www.zabbix.com/download_appliance

[Frontend first view]: frontend-first-view