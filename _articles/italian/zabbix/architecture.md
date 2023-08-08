---
layout: article
title: Architettura
slug: architecture
category: italian
tags:
  - zabbix
keywords: zabbix, architettura, componenti, server, web, proxy, agent, client
description: L'architettura di Zabbix e a cosa serve ciascun componente di Zabbix.
order: 1402
date: 2018-04-17T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

**Zabbix** si compone di tante parti, ognuna delle quali con uno scopo preciso e
necessario ad ottenere l'analisi dei valori dei sistemi controllati.

{:.center}
![Components](/resources/articles/zabbix/security_authentication.svg){:height="400px"}

# Zabbix Server

La parte centrale del sistema Zabbix si occupa di contattare i sistemi remoti
controllati, di ricevere i valori, di generare gli avvisi e di notificare agli
amministratori dei sistemi dei problemi emersi.

Dopo che tutti i valori sono stati configurati tramite l'interfaccia Web, è il
server a svolgere il lavoro quotidiano di controllo dei dispositivi e servizi
controllati.

# Zabbix Frontend Web

L'interfaccia web di Zabbix Server che consente di configurare il server di
Zabbix, aggiungere nuovi sistemi da controllare, aggiungere i valori da
controllare, definire quali valori costituiscano un problema

# Zabbix Proxy

Si tratta di un server speciale, minimale, studiato per distribuire il
monitoraggio su più sistemi. Sarà poi il proxy ad informare il server dei
valori e dei problemi rilevati.

La funzione principale del proxy è quella di rendere monitorabili anche risorse
al di fuori della rete controllata e di permettere di portare il carico di rete
anziché dal server ai client, dal proxy ai client, che vivranno nello stesso
segmento di rete.

# Zabbix Agent

L'agente è un'applicazione che si installa sui computer da controllare e si
occupa di informare periodicamente il server o il proxy dei valori rilevati sul
sistema operativo sul quale è in esecuzione.

L'agente [è disponibile][Download agents] per i principali sistemi operativi:

- Microsoft Windows
- GNU/Linux
- Apple OS X
- FreeBSD
- OpenBSD
- AIX
- HP-UX
- Solaris

>>>>> Purtroppo al momento non sono disponibili agenti ufficiali per dispositivi
mobili come Android e iPhone. E' possibile sponsorizzare lo sviluppo di un
agente ufficiale per Android
[dalla pagina dedicata][Agent and Proxy for Android devices].

# Moduli di terze parti

Trattandosi di un prodotto [Open Source], sono stati sviluppati numerosi moduli
aggiuntivi che estendono le funzionalità iniziali di Zabbix e permettono anche
l'integrazione con servizi di terze parti (ad esempio dispositivi o applicazioni
proprietarie).

Attraverso questo tipo di moduli sono stati sviluppati anche applicazioni per
dispositivi mobili in modo da permettere l'accesso immediato ai valori di un
server Zabbix senza utilizzare l'interfaccia Web.


{: target="_blank" .external }
[Download agents]: https://www.zabbix.com/download_agents

{: target="_blank" .external }
[Agent and Proxy for Android devices]: https://www.zabbix.com/development_services

{: target="_blank" .external }
[Open Source]: https://www.zabbix.com/download_sources
