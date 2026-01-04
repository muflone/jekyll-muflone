---
layout: article
title: Installazione di Zabbix Agent
slug: agent-installation
category: italian
tags:
  - zabbix
keywords: zabbix, agent, installation
description: La procedura di installazione di Zabbix Agent dipende dal sistema
             operativo in uso. In questa guida saranno mostrate le procedure
             di installazione dell'agente in vari sistemi operativi.
order: 1413
date: 2018-04-25T00:00:00Z
---

{: .center }
![Zabbix logo](/resources/articles/zabbix/logo.png)

Dalla pagina [Download and install Precompiled Zabbix Agents] è possibile
scaricare e trovare le istruzioni di installazione dell'agente di Zabbix su
vari sistemi operativi.

La procedura generalmente richiede la semplice installazione del software, la
configurazione delle informazioni basilari e l'avvio del servizio.

----
# Installazione di Zabbix Agent su Microsoft Windows

Dopo aver scaricato il file zip corrispondente (ad oggi l'ultima versione è
*zabbix_agents_3.4.6.win.zip*) decomprimerlo nella directory **C:\Zabbix**.

>>>>> In realtà il percorso C:\Zabbix non è obbligatorio, può essere scelta
qualsiasi directory, purché tutti i passaggi successivi facciano riferimento
alla directory scelta.

Spostarsi quindi nella directory **C:\Zabbix\conf** e creare un nuovo file di
testo di nome **zabbix_agent.conf** contenente al suo interno quanto segue:

    LogType=file
    LogFile=C:\Zabbix\zabbix_agentd.log

    Server=zabbix-server.muflone.local
    ServerActive=zabbix-server.muflone.local
    ListenPort=10050
    RefreshActiveChecks=120

Sostituendo **zabbix-server.muflone.local** con l'indirizzo del server Zabbix.


>>>>>> Per una spiegazione dei parametri di questo file di configurazione si può
far riferimento al file di esempio *zabbix_agent.win.conf*.

Per eseguire l'installazione dell'agente di Zabbix come servizio è possibile
avviare un prompt dei comandi **come amministratore** ed eseguire i seguenti
comandi:

{: .center }
![Agent installation](/resources/articles/zabbix/agent-installation/windows-installation.png)

    CD \Zabbix
    bin\win32\zabbix_agentd.exe -c conf\zabbix_agent.conf --install

>>>>>> Nel caso di un sistema operativo a 64 bit è raccomandato installare
l'agente nella versione a 64 bit, sostituendo al comando precedente win32 con
win64.

Subito dopo l'installazione è possibile avviare il servizio con:

    NET START "Zabbix Agent"

{: .center }
![Windows firewall](/resources/articles/zabbix/agent-installation/windows-firewall.png)

Nel caso che il firewall di Windows risultasse attivo, potrebbe essere necessario
sbloccare l'accesso all'agente aggiungendo **zabbix_agentd.exe** alla lista
delle eccezioni.

{: target="_blank" .external }
[Download and install Precompiled Zabbix Agents]: https://www.zabbix.com/download_agents
