---
layout: article
title: Zabbix Agent
slug: agent
category: italian
tags:
  - zabbix
keywords: zabbix, agent
description: L'agente di Zabbix è un software da installare sul sistema operativo
             da controllare che permette ai server di effettuare monitoraggio
             periodico e ricevere gli avvisi in caso di problemi riscontrati
             sul sistema operativo controllato.
order: 412
date: 2018-04-25T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

**Zabbix Agent** rappresenta uno dei software fondamentali per il monitoraggio
di sistemi operativi (Microsoft Windows, GNU/Linux, Mac OS X, Solaris e altri).

Si tratta di un software di dimensioni molto ridotte, non invasivo, che ad
intervalli regolari effettua controlli e restituisce ai server le informazioni
ottenute.

----
# Modalità di funzionamento

## Modalità passiva

In questa modalità l'agente non esegue nessuna operazione di propria iniziativa,
quindi resta sempre in attesa che il server di Zabbix effettui una richiesta,
l'agente la riceve, la processa e rimanda al server la risposta ottenuta.

Questa modalità è più onerosa per il server Zabbix in quanto dovrà periodicamente
chiedere ai sistemi controllati i valori desiderati.

L'operazione può essere sintetizzata come segue:

1. Zabbix Server effettua una richiesta a Zabbix agent
1. Zabbix Agent riceve la richiesta e la interpreta, se valida
1. Zabbix Agent elabora la richiesta ricevuta
1. Zabbix Agent invia la risposta a Zabbix Server

## Modalità attiva

In questa modalità l'agente richiede autonomamente al server quali controlli
eseguire e con quali tempi e periodicamente li effettua autonomamente e invia
le risposte al server.

Questa modalità è più onerosa per Zabbix Agent e scarica il server dell'onere di
inviare le richieste a tutti gli agenti controllati.

1. Zabbix Agent richiede al server quali controlli eseguire
1. Zabbix Server riceve la richiesta e restituisce a Zabbix Agent l'elenco dei
   controlli da eseguire e gli intervalli tra ogni richiesta
1. Zabbix Agent tiene l'elenco dei compiti da eseguire e periodicamente elabora
   i compiti e invia le risposte al server
1. Zabbix Server riceve le risposte da Zabbix Agent

----
# Installazione di Zabbix Agent

Prima che un sistema possa essere controllato da Zabbix Server è necessario che
venga in esso installato l'agente e configurato in modo che possa inviare le
risposte al server.

L'installazione dell'agente dipende dal sistema operativo in uso ma generalmente
richiede la semplice installazione del software, la configurazione del file
zabbix_agentd.conf e l'avvio del servizio.

L'agente dopo il suo avvio resta in ascolto sulla porta predefinita TCP 10050 ma
può essere modificata dalla configurazione dell'agente.

Per informazioni dettagliate sulla procedura di installazione dell'agente sui
vari sistemi operativi vedere la pagina dedicata all'[installazione dell'agente
di Zabbix][Zabbix Agent installation].

----
# Test di funzionamento dell'agente

Per verificare il funzionamento dell'agente installato su un sistema controllato
è possibile eseguire delle semplici verifiche.

La prima verifica riguarda la raggiungibilità del servizio dell'agente:

    telnet INDIRIZZO 10050

Se la connessione non viene stabilita oppure viene immediatamente rifiutata
allora il servizio dell'agente non è in ascolto sulla porta 10050 oppure
l'indirizzo indicato è errato oppure un firewall sta impedendo la connessione
alla porta di rete.

Se la connessione con telnet viene stabilita è possibile effettuare la verifica
del funzionamento dell'agente dalla macchina Zabbix Server eseguendo:

    zabbix_get -s INDIRIZZO -k agent.ping

Se venisse risposto un messaggio come il seguente:

    zabbix_get [3330]: Get value error: ZBX_TCP_READ() failed: [104] Connection reset by peer
    zabbix_get [3330]: Check access restrictions in Zabbix agent configuration

Allora c'è un problema di configurazione dell'agente, non è stato configurato
correttamente il server che deve ricevere le risposte, ovvero le opzioni
**Server** e **ServerActive** del file zabbix_agentd.conf non puntano all'indirizzo
del server Zabbix, quindi le richieste sono rifiutate.

Se venisse risposto con **1** allora l'agente è in esecuzione e pronto a
ricevere comandi.

[Zabbix Agent installation]: agent-installation
