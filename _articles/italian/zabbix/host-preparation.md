---
layout: article
title: Preparare il sistema da controllare
slug: host-preparation
category: italian
tags:
  - zabbix
keywords: zabbix, configurazione, host, group, server, protocolli, monitoraggio,
          snmp, ipmi, agent
description: Prima di passare alla configurazione effettiva del primo sistema
             controllato da Zabbix è necessario conoscere il principio di
             funzionamento dei protocolli di monitoraggio, dei gruppi di host
             e degli host.
order: 410
date: 2018-04-25T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

Il processo di configurazione di un host controllato passa da tre semplici
passaggi (vedi anche la pagina [come funziona Zabbix?][How Zabbix works]):

1. La scelta del **protocollo di monitoraggio** e quindi la configurazione del
   protocollo scelto sul sistema da controllare
1. La configurazione di un **gruppo di host** sul server di Zabbix
1. La configurazione dell'**host** sul server di Zabbix

----
# Scelta del protocollo di monitoraggio

Zabbix può controllare vari dispositivi ma le principali tipologie sono:

* Sistemi operativi, attraverso un applicativo da installare chiamato
  **Zabbix Agent** o agente
* Dispositivi di rete tramite protocollo **SNMP**
* Server e altri hardware tramite protocollo **IPMI**

L'elenco non è completo, Zabbix infatti è estendibile in mille maniere e
possono essere sviluppati altri controlli con altri protocolli.

La scelta del protocollo di monitoraggio è naturalmente soggetta a ciò che
il sistema da controllare supporta. Ad esempio se una stampante supporta
unicamente il protocollo SNMP, la scelta sarà obbligata a quest'ultimo. Se si
desidera controllare un sistema operativo, la scelta di Zabbix Agent è sempre
la preferibile.


## Zabbix Agent

L'agente di Zabbix è un piccolo software da installare nei sistemi operativi da
controllare e si occupa di effettuare la verifica dei valori e li comunica
al server di Zabbix che li raccoglie e li trasforma in avvisi e notifiche
all'occorrenza.

Le funzionalità che l'agente fornisce sono tante e sono estendibili, ovvero
l'amministratore di sistema può definire domande aggiuntive che diventeranno
comandi da eseguire sul sistema operativo per ottenere le risposte e quindi
restituirle a Zabbix Server.

Per l'installazione dell'agente di Zabbix sui vari sistemi operativi si veda
la pagina dedicata a [Zabbix Agent].

## Protocollo SNMP

Il [protocollo SNMP][SNMP protocol] (acronimo di *Simple Network Management Protocol*)
è un protocollo di rete utilizzato da quasi tutti i produttori di hardware ed in
taluni casi è applicabile anche ai sistemi operativi.

La configurazione del protocollo SNMP sui dispositivi da controllare dipende
dai dispositivi stessi, generalmente si trovano le sezioni SNMP su router,
switch gestiti, stampanti, telecamere di rete, UPS e altri dispositivi.

Del protocollo SNMP attualmente esistono tre versioni principali:

* La versione 1 (**SNMPv1**) che fa uso di una semplice password (chiamata
  *Community string*), passata in chiaro durante la richiesta
* La versione 2c (**SNMPv2c**) che estende le funzioni della versione SNMPv1 e
  fa uso della stessa Community string
* La versione 3 (**SNMPv3**) permette l'uso di coppie utente e password e la
  crittografia delle richieste e delle risposte

>>> I protocolli **SNMPv1** e **SNMPv2c** a causa della loro natura sono insicuri
e se possibile vanno sostituiti dalla versione 3. Attraverso SNMPv1 e SNMPv2
non si dovrebbero mai trasmettere informazioni riservate perché potrebbero
essere facilmente intercettate o peggio modificate da un attaccante.

La quasi totalità dei dispositivi economici forniscono soltanto i protocolli
v1 e v2c e per far l'utilizzo necessitano della sola stringa di comunità.

## Protocollo IPMI

Il [protocollo IPMI][IPMI protocol] (acronimo di
*Intelligent Platform Management Interface*) è un protocollo di rete che permette
il controllo di dispositivi hardware di vario genere.

Generalmente si trova disponibile unicamente su sistemi di un certo costo, come
ad esempio sistemi server IBM, Lenovo, Dell e HP.

Le sue funzionalità sono quelle relative al monitoraggio dei valori vitali
dell'hardware come lo stato di funzionamento delle parti, le temperature,
eventuali crash del sistema operativo in essi eseguito.

Il protocollo in alcune implementazioni permette anche il controllo totale della
macchina, incluse accensione e spegnimento e accesso allo schermo del sistema ma
tutto ciò esula da Zabbix che non svolge queste operazioni.

----
# Configurazione di un gruppo host

I [gruppi di host][host group] su Zabbix consentono di aggregare più host sotto
un'unica voce. Ogni sistema controllato può appartenere a più gruppi di host
contemporaneamente. Ad esempio una stampante oltre al gruppo *Printers* può
appartenere anche al gruppo *Network piano terra*.

----
# Configurazione di un host

La configurazione dell'host definisce il nome, l'indirizzo del sistema,
l'interfaccia (ovvero l'indirizzo e la porta) utilizzata per effettuare le
analisi secondo i protocolli di monitoraggio indicati sopra.

Oltre questi dati di configurazione dell'host è possibile associare uno o più
[modelli (Template)][template] di regole di controllo. Saranno questi modelli
a determinare i controlli che saranno effettuati sul sistema configurato.

>>>>> Non è possibile associare modelli (template) a gruppi di host.
La configurazione dei gruppi host permette soltanto di posizionare i modelli
all'interno del gruppo di host ma non saranno efficaci e non svolgeranno alcuna
funzione rispetto gli host nel gruppo.


[How Zabbix works]: what-is-zabbix.html#come-funziona-zabbix

[host group]: definitions.html#host-group

[Zabbix Agent]: agent.html

{: target="_blank" .external }
[SNMP protocol]: https://en.wikipedia.org/wiki/Simple_Network_Management_Protocol

{: target="_blank" .external }
[IPMI protocol]: https://en.wikipedia.org/wiki/Intelligent_Platform_Management_Interface

[template]: definitions.html#template
