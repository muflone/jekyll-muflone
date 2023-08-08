---
layout: article
title: Termini e definizioni
slug: definitions
category: italian
tags:
  - zabbix
keywords: zabbix, termini, definizioni
description: I termini e le definizioni utilizzati su Zabbix, fondamentali per
             capire Zabbix e il suo funzionamento.
order: 1409
date: 2018-04-18T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

Su Zabbix sono utilizzati numerosi termini tecnici che è fondamentale conoscere
per configurare e capire Zabbix.

Ulteriori informazioni possono trovarsi [nella documentazione ufficiale][Definitions]
di Zabbix.

# Host

Un host (o sistema) è un dispositivo da monitorare, generalmente un computer o
un altro apparato di rete.

# Host group

Un gruppo di host è un raggruppamento logico di uno o più host, la loro
organizzazione consente di tenere sotto controllo più host in un unico gruppo.

Un singolo host può appartenere contemporaneamente a più host, ad esempio il
firewall della sede 1 può appartenere contemporaneamente al gruppo Firewall e
al gruppo Sede 1, in modo da legare gli avvisi ai responsabili della sicurezza
e il controllo allo staff della sede 1.

>>> Ad oggi non è possibile associare effettivamente template a gruppi di host,
la loro funzione è meramente descrittiva e **non applica** automaticamente il
modello a tutti gli host all'interno del gruppo.

# Item

Un item è un elemento di dati da ricevere dagli host controllati, ad esempio
il tempo di latenza, la quantità di RAM libera sono item.

# Application

Un raggruppamento logico di uno o più item.

# Trigger

Un trigger è un allarme, una condizione che si verifica quando i valori di una
o più item fanno scattare un allarme.

Il termine allarme non rappresenta necessariamente un avviso (e-mail o telefonata)
che deve mettere in guardia lo staff che se ne occupa. Un allarme è solo lo
scaturire di una condizione che può essere normale o anomala.

# Event

Un evento è lo scattare di una condizione, ovvero il cambio di stato di un
allarme (trigger).

# Problem

Un problema è lo stato che un allarme può avere, uno stato specifico che
identifica il trigger come problematico e da segnalare.

# Action

La conseguenza di un evento può far scattare un'azione, si tratta di un'operazione
(come una notifica) correlata ad una condizione di un evento.

# Escalation

La sequenza delle azioni da eseguire al verificarsi di un problema.

# Media

Un mezzo di notifica, ad esempio la mail, l'avviso sui log, l'SMS o una
telefonata sono tutti media di notifica.

# Notification

Un messaggio preconfigurato che viene inoltrato allo staff coi media configurati.

# Remote command

Un comando remoto è un'azione che il server può avviare allo scattare di un
evento.

# Grafici

Un grafico è la rappresentazione grafica dello storico di un valore, ad esempio
i singoli tempi di risposta, posti in un piano cartesiano rappresentano il
grafico dei tempi di risposta.

# Discovery

La scoperta è un meccanismo di analisi di alcune informazioni, partendo da un
generico per arrivare al dettaglio presente sul singolo host.

Ad esempio la regola di discovery delle interfacce di rete fa sì che si possano
sviluppare operazioni su tutte le interfacce disponibili su un host.

# Template

I modelli sono contenitori degli elementi precedenti, ad esempio il modello per
i sistemi operativi GNU/Linux contiene:

* Item di memoria, CPU, tempi e altro
* Applicazioni memoria, CPU, file system che raggruppano le item precedenti
* Triggers che scattano quando i tempi di risposta al ping sono elevati oppure
  quando la quantità di memoria libera è inferiore ad una certe percentuale
* Grafici che uniscono i valori dei tempi di risposta
* Regole di discovery per file system e per interfacce di rete
* Collegamenti ad altri template

I template consentono di definire le regole di analisi in maniera raggruppata,
da applicare ad un singolo host.

# Web scenario

Gli scenari web si compongono di richieste HTTP atte a indagare lo stato di
salute di un servizio web. L'unione di queste richieste HTTP svilupperà poi un
grafico.


{: target="_blank" .external }
[Definitions]: https://www.zabbix.com/documentation/3.4/manual/definitions
