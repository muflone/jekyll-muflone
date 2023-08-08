---
layout: article
title: Installazione appliance su macchina virtuale
slug: install-to-vm
category: italian
tags:
  - zabbix
keywords: zabbix, installazione, appliance, virtual, machine, vm, download, ovf
description: Installare Zabbix Appliance su macchina virtuale è possibile
             utilizzando un modello già pronto da scaricare e semplicemente
             importare nel virtualizzatore preferito.
order: 1405
date: 2018-04-18T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

Alla pagina [Download and install Zabbix][Download appliance] è possibile
scaricare una Zabbix Appliance in uno dei tanti formati.

Per installare Zabbix Appliance in una macchina virtuale si può utilizzare un
file immagine pronto da scaricare, nel formato che più si adatta all'Hypervisor
in uso. I formati disponibili sono:

* KVM, QEMU (.qcow2)
* KVM, Parallels, QEMU, USB stick, VirtualBox, Xen (.raw)
* Open virtualization format (.ovf)
* Microsoft Azure
* Microsoft Hyper-V 2008
* Microsoft Hyper-V 2012
* VirtualBox, VMWare (.vmdk)

I formati **.qcow2, .raw e .vmdk** contengono soltanto i dischi della
Zabbix Appliance, per cui è necessario configurare/creare la macchina virtuale
manuale e aggiungere i dischi scaricati.

Il formato **.ovf** è quello da me preferito sia per Oracle VirtualBox sia per
VMware ESXi in quanto in entrambi i sistemi la procedura di importazione
supporta questo specifico formato.

Dopo aver decompresso il file *zabbix_appliance_X.Y.Z_x86_64.ovf.tar.gz* si
otterrà una cartella contenente due file:

* **zabbix_appliance_X.Y.Z.ovf**
* **zabbix_appliance_X.Y.Z-disk1.vmdk**

Il primo di questi file rappresenta la macchina virtuale da importare in Oracle
VirtualBox oppure VMware, il secondo rappresenta il disco contenente i dati
della macchina virtuale.

# Importazione su Oracle VirtualBox

{:.center}
![Importa applicazione virtuale](/resources/articles/zabbix/install-to-virtualbox/01.png)

Su Oracle VirtualBox, aprendo il menu **File** scegliere l'opzione
**Importa applicazione virtuale**.

{:.center}
![Applicazione virtuale da importare](/resources/articles/zabbix/install-to-virtualbox/02.png)

La finestra guidata di importazione chiederà semplicemente il percorso del file
.ovf da importare.

{:.center}
![Impostazioni applicazione virtuale](/resources/articles/zabbix/install-to-virtualbox/03.png)

Al secondo passaggio dell'importazione della macchina virtuale sarà possibile
effettuare lievi modifiche alla macchina virtuale, come il cambio del nome della
macchina virtuale da importare, il sistema operativo utilizzato, la quantità
di CPU e di memoria RAM da impiegare.

In generale è meglio non effettuare variazioni, eccetto il nome della macchina
virtuale che è modificabile liberamente, in questo esempio **Zabbix Appliance**.

{:.center}
![Importazione applicazione virtuale](/resources/articles/zabbix/install-to-virtualbox/04.png)

La procedura di importazione richiederà qualche minuto e si concluderà
automaticamente non appena raggiunto il 100%.

{:.center}
![Configurazione rete virtuale](/resources/articles/zabbix/install-to-virtualbox/05.png)

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
[Download appliance]: https://www.zabbix.com/download_appliance

[Frontend first view]: frontend-first-view.html
