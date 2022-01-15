---
layout: article
title: Installazione
slug: install
category: italian
tags:
  - zabbix
keywords: zabbix, installazione
description: La procedura di installazione di Zabbix è semplice e possibile in
             numerose maniere, in base al tipo di installazione che si desidera
             seguire.
order: 403
date: 2018-04-18T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

L'installazione di **Zabbix** può essere eseguita in numerose modalità. La più
semplice sicuramente è quella di utilizzare la **Zabbix Appliance**, una
macchina virtuale già pronta, da scaricare e importare in un qualsiasi Hypervisor
come VMware, Oracle VirtualBox, QEMU o Microsoft HyperV.
Alla pagina [Download and install Zabbix][Download appliance] è possibile
scaricare una Zabbix Appliance in uno dei tanti formati.

Un'altra maniera molto semplice di installare Zabbix è quella di scaricare un
file immagine ISO, masterizzarlo su CD o DVD e avviare l'installazione su una
macchina reale o virtuale utilizzando l'immagine ISO.
Attraverso l'immagine ISO è possibile installare sia **Zabbix Server** sia
**Zabbix Proxy** in una nuova installazione di sistema operativo.

In alternativa, se non si volesse utilizzare una macchina dedicata (o da
reinstallare), è possibile installare Zabbix tramite pacchetti per GNU/Linux
oppure partendo dai sorgenti.

Alla pagina [Install Zabbix from package] è possibile trovare le istruzioni di
installazione per alcune distribuzioni GNU/Linux.

* [Installazione Appliance da file ISO][Install from ISO]
* [Installazione Appliance su macchina virtuale][Install to VM]
* [Installazione su Arch Linux][Install to Arch Linux]

{: target="_blank" .external }
[Download appliance]: https://www.zabbix.com/download_appliance

{: target="_blank" .external }
[Install Zabbix from package]: https://www.zabbix.com/download

[Install from ISO]: install-from-iso.html

[Install to Arch Linux]: install-to-arch-linux.html

[Install to VM]: install-to-vm.html
