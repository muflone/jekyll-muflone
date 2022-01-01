---
layout: article
title: Installazione appliance su macchina virtuale
slug: install-to-vm
category: italian
tags:
  - bareos
keywords: bareos, installazione, appliance, virtual, machine, vm, download, ovf
description: Installare Bareos su macchina virtuale è possibile utilizzando
             un modello già pronto da scaricare e semplicemente importare nel
             virtualizzatore preferito.
order: 505
date: 2018-08-16T00:00:00Z
---

{:.center}
![Bareos logo](/resources/articles/bareos/logo.png)

Alla pagina [Download Bareos] è possibile scaricare un'apppliance in formato OVF
per VirtualBox oppure VMware, pronta da importare e utilizzare senza particolari
configurazioni.

Dopo aver scaricato e decompresso il file
*bareos_XX.Y_64_bit.x86_64-XX.Y.Z.ovf.tar.gz* si otterrà una cartella contenente
tre file:

* **bareos_XX.Y_64_bit.x86_64-XX.Y.Z.mf**
* **bareos_XX.Y_64_bit.x86_64-XX.Y.Z.ovf**
* **bareos_XX.Y_64_bit.x86_64-XX.Y.Z-disk1.vmdk**

Il secondo di questi file rappresenta la macchina virtuale da importare in Oracle
VirtualBox oppure VMware, il secondo rappresenta il disco contenente i dati
della macchina virtuale.

# Importazione su Oracle VirtualBox

{:.center}
![Importa applicazione virtuale](/resources/articles/zabbix/install-on-virtualbox/01.png)

Su Oracle VirtualBox, aprendo il menu **File** scegliere l'opzione
**Importa applicazione virtuale**.

{:.center}
![Applicazione virtuale da importare](/resources/articles/zabbix/install-on-virtualbox/02.png)

La finestra guidata di importazione chiederà semplicemente il percorso del file
.ovf da importare.

{:.center}
![Impostazioni applicazione virtuale](/resources/articles/zabbix/install-on-virtualbox/03.png)

Al secondo passaggio dell'importazione della macchina virtuale sarà possibile
effettuare lievi modifiche alla macchina virtuale, come il cambio del nome della
macchina virtuale da importare, il sistema operativo utilizzato, la quantità
di CPU e di memoria RAM da impiegare.

In generale è meglio non effettuare variazioni, eccetto il nome della macchina
virtuale che è modificabile liberamente, in questo esempio **Zabbix Appliance**.

{:.center}
![Importazione applicazione virtuale](/resources/articles/zabbix/install-on-virtualbox/04.png)

La procedura di importazione richiederà qualche minuto e si concluderà
automaticamente non appena raggiunto il 100%.

{:.center}
![Configurazione rete virtuale](/resources/articles/zabbix/install-on-virtualbox/05.png)

Prima di avviare la macchina virtuale si raccomanda di configurare la scheda di
rete virtuale dalla modalità **NAT** alla modalità **Scheda con bridge**,
altrimenti non sarà possibile raggiungere dall'esterno la rete della macchina
virtuale. Questa configurazione è possibile cliccando il pulsante **Impostazioni**
e spostandosi nella sezione **Rete**.

Terminata questa configurazione basterà avviare la macchina virtuale appena
importata cliccando sul pulsante **Avvia**. Qualche secondo dopo la macchina
sarà avviata e sarà possibile iniziare ad utilizzarla.

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
[Download Bareos]: https://www.bareos.org/en/download.html
