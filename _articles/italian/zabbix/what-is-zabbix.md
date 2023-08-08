---
layout: article
title: Introduzione
slug: what-is-zabbix
category: italian
tags:
  - zabbix
keywords: zabbix, introduzione, avvisi, monitoraggio, sistemi, web, snmp, ipmi
description: Cosa è Zabbix? Introduzione al sistema di monitoraggio più avanzato
             e più usato al mondo.
order: 1401
date: 2018-04-17T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

# Cosa è Zabbix?

[Zabbix] è il più avanzato e completo sistema di monitoraggio di sistemi
informatici, utilizzando da migliaia di aziende in tutto il mondo.
[Open Source al 100%][Open Source] e [rilasciato gratuitamente][Download] a
chiunque voglia utilizzarlo.

Zabbix è altamente scalabile e permette il controllo anche di migliaia di
dispositivi contemporaneamente, affidandosi ad una infrastruttura client-server
mista. Gli avvisi possono arrivare direttamente dalle macchine controllate
oppure possono essere il risultato di controlli eseguiti direttamente dal server.

Sono già numerosissime le aziende che adoperano Zabbix per il controllo dei
propri sistemi, della rete e delle applicazioni.

----
# Cosa può fare Zabbix?

{:.center}
![Metrics](/resources/articles/zabbix/metric_collection.svg){:height="400px"}

Zabbix può controllare:

- **Sistemi operativi**&nbsp;come Microsoft Windows, GNU/Linux, Apple OS X, Solaris,
  BSD, AIX
- **Hardware**&nbsp;come server, UPS, NAS, router, switch attraverso SNMP e IPMI
- Sistemi raggiungibili&nbsp;**via rete**&nbsp;attraverso ICMP, SSH, Telnet e connessioni TCP
- **Macchine virtuali**&nbsp;e&nbsp;**Hypervisor**
- **Database**
- **Applicazioni**&nbsp;e&nbsp;**servizi Web**

----
# Come funziona Zabbix?

Zabbix supporta numerose modalità di controllo delle risorse.

- Per il controllo dei sistemi operativi è possibile installare un software
  chiamato&nbsp; **agente Zabbix**, disponibile per i principali sistemi operativi
- Per il controllo dei dispositivi hardware è possibile leggere i valori 
  tramite interfaccia SNMP o IPMI e recuperare i valori interessati, come ad
  esempio temperature, livelli di consumabili, carica delle batterie, stato di
  salute (naturalmente l'interfaccia SNMP o IPMI deve fornitore questi valori)
- Controlli via rete come PING o accesso ai servizi di rete possono consentire
  la verifica dello stato di attività
- Il controllo dei siti internet può basarsi ad esempio sulla velocità di
  risposta o di trasferimento dei dati
- Ulteriori controlli ad hoc possono essere sviluppati per assicurare il corretto
  funzionamento di un servizio o di un'applicazione


{: target="_blank" .external }
[Zabbix]: https://www.zabbix.com/

{: target="_blank" .external }
[Open Source]: https://www.zabbix.com/download_sources

{: target="_blank" .external }
[Download]: https://www.zabbix.com/download
