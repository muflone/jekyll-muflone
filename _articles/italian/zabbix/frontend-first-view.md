---
layout: article
title: Conoscere Zabbix Frontend Web
slug: frontend-first-view
category: italian
tags:
  - zabbix
keywords: zabbix, configurazione, setup, web, frontend
description: Impariamo a conoscere Zabbix Frontend Web, la parte centrale per
             la configurazione del sistema, degli host, degli avvisi e dei
             valori da monitorare.
order: 408
date: 2018-04-18T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

All'accesso di Zabbix Frontend Web saranno chiesti utente e password prima di
poter visionare l'interfaccia di gestione di Zabbix.

{:.center}
![Zabbix login](/resources/articles/zabbix/login.png)

>>>>>> I dati di accesso predefiniti a Zabbix Frontend Web sono i seguenti:  
**Utente**: Admin  
**Password**: zabbix

{:.center}
[![Dashboard](/resources/articles/zabbix/overview/dashboard-initial-thumb.png)][Dashboard full]

Al primo accesso sarà mostrata la **Dashboard** predefinita, ovvero un cruscotto
di controllo dello stato di salute di tutto il sistema, inclusi anche tutti gli
altri sistemi controllati.

{:.center}
![Sections](/resources/articles/zabbix/overview/sections.png)

L'area superiore di qualsiasi schermata di Zabbix mostra le sezioni di interesse
accessibili, suddivise in più sottosezioni.

Ulteriori informazioni sulle sezioni di interesse del frontend possono trovarsi
[nella documentazione ufficiale][Frontend sections] di Zabbix.

----
# Monitoring

Questa area contiene la visualizzazione degli elementi controllati per il
monitoraggio.

Attraverso di essa è possibile visionare lo stato degli avvisi ed è la sezione
utilizzata da chi si occupa della manutenzione dei sistemi.

All'interno di questa sezione sono presenti le seguenti sottosezioni

1. **Dashboard**: mostrerà i cruscotti configurati, contenenti grafici e valori
   statistici rapidi per la supervisione d'insieme
1. **Problems**: consente di eseguire filtri sui problemi e avvisi attualmente
   esistenti
1. **Overview**: mostra una panoramica generale su tutti gli avvisi rilevati,
   un insieme più generale della sottosezione Problems
1. **Web**: mostra i grafici e le statistiche delle analisi web, un particolare
   tipo di analisi che confronta le prestazioni dei siti web
1. **Latest data**: è la sezione più dettagliata che contiene i valori rilevati
   dalle analisi e mostra i valori come sono stati ricevuti, sia che costituiscano
   o meno un allarme o un avviso
1. **Triggers**: contiene gli allarmi (triggers), quelle condizioni che fanno
   scaturire un avviso, una notifica, un processo o un'altra qualsiasi reazione
   in base ai valori ottenuti dalle rilevazioni
1. **Graphs**: sono mostrati in essa grafici correlati ai dati ottenuti
1. **Screens**: contengono le schermate, ovvero gruppi di grafici e statistiche
1. **Maps**: contengono le mappe e gli schemi disegnati che semplificano la
   comprensione della struttura di rete
1. **Discovery**: mostra lo stato dell'analisi (discovery) di rete, un processo
   atto a esplorare la rete per scoprire la presenza di nuovi sistemi da
   monitorare
1. **Services**: contiene i reparti che possono essere configurati per competenza
   del tipo di avviso o gruppi di sistemi, ciascuno dei quali con il proprio
   livello di SLA basato sul tempo di disservizio

----
# Inventory

L'area dell'inventario contiene un elenco dei sistemi e delle informazioni
proprie di ogni sistema, come numero di serie, marca, modello.

All'interno di questa sezione sono presenti le seguenti sottosezioni

1. **Overview**: mostra il conteggio del numero di host raggruppati per tipologia
1. **Hosts**: mostra l'intentario degli host identificati

----
# Reports

L'area dei report contiene dati più sintetici e generali dello stato di tutto
il sistema e degli host controllati.

All'interno di questa sezione sono presenti le seguenti sottosezioni

1. **Status of Zabbix**: mostra informazioni circa lo stato di salute di Zabbix,
   come il numero di sistemi controllati, il numero di utenti e così via
1. **Availability report**: mostra lo stato di disponibilità dei servizi
   controllati
1. **Triggers top 100**: mostra i primi 100 allarmi scattati, ovvero i primi 100
   avvisi problematici più frequenti
1. **Audit**: mostra le modifiche e le configurazioni effettuate dal frontend
1. **Action log**: mostra gli avvisi inviati in seguito agli allarmi scattati
1. **Notifications**: mostra i totali degli avvisi inviati a ciascun operatore

----
# Configuration

L'area della configurazione contiene le informazioni di configurazione di tutto
il sistema Zabbix, gli host i gruppi, le regole e tutto il resto che fa funzionare
Zabbix Server per monitorare i sistemi.

1. **Host groups**: definisce i gruppi di host, al fine di raggrupparli e
   visionare tutti gli host in raggruppamenti omogenei
1. **Templates**: definisce i modelli che contengono al loro interno i valori
   da controllare, gli allarmi, gli eventi da far scattare, raggruppati in
   maniera logica
1. **Hosts**: definisce i sistemi da controllare, agganciando ad essi i modelli
   e i gruppi di host
1. **Maintenance**: definisce i periodi di manutenzione e controllo dei gruppi
   di host
1. **Actions**: configura le azioni che dovranno scattare allo scattare di
   alcuni eventi, in risposta alla variazione o allo scaturire dei problemi
1. **Event correlation**: consente di correlare gli eventi tra loro in modo da
   far scattare operazioni quando due o più eventi vengono correlati tra loro
1. **Discovery**: definiscono le regole di scoperta, per l'indagine della rete
1. **Services**: definiscono le persone responsabili dei disservizi in maniera
   gerarchica

----
# Administration

La sezione amministrazione definisce le configurazioni proprie del server Zabbix
e non riguardano gli host controllati.

1. **General**: consente di configurare opzioni di carattere generale
1. **Proxies**: consente di definire quali sistemi opereranno come Zabbix Proxy
   per il monitoraggio di altri sistemi e centralizzarne sul server i risultati
1. **Authentication**: definisce il tipo di autenticazione per gli utenti del
   sistema
1. **User groups**: definisce i gruppi di utenti
1. **Users**: definisce gli utenti che avranno accesso al sistema
1. **Media types**: definisce i media che potranno notificare agli operatori gli
   avvisi ricevuti
1. **Scripts**: definisce strumenti aggiuntivi che potranno essere eseguiti su
   richiesta
1. **Queue**: mostra la coda delle richieste in attesa di essere elaborate


{: target="_blank" }
[Dashboard full]: /resources/articles/zabbix/overview/dashboard-initial.png

{: target="_blank" .external }
[Frontend sections]: https://www.zabbix.com/documentation/3.4/manual/web_interface/frontend_sections