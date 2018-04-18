---
layout: article
title: Configurazione iniziale di Zabbix Frontend Web
slug: frontend-setup
category: italian
tags:
  - zabbix
keywords: zabbix, configurazione, setup, web, frontend
description: La configurazione iniziale di Zabbix Frontend Web richiede
             l'inserimento dei dati di accesso del server di database e di
             Zabbix Server.
order: 407
date: 2018-04-18T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

>>>>>>> Nel caso di utilizzo della Zabbix Appliance questa procedura non è
necessaria in quanto Zabbix Frontend Web risulta già configurato automaticamente
con i dati del database incluso nell'appliance stessa.

Accedendo al server web di Zabbix Frontend Web all'indirizzo
**http://indirizzo/zabbix** (oppure http://indirizzo qualora fosse stato
installato Zabbix sulla radice del server web) verrà mostrata la procedura
guidata di configurazione.

{:.center}
![Welcome to Zabbix](/resources/articles/zabbix/frontend-setup/01.png)

La procedura inizia con una finestra di benvenuti sulla quale si potrà avanzare
cliccando il pulsante **Next step**.

{:.center}
![Check of pre-requisites](/resources/articles/zabbix/frontend-setup/02.png)

Successivamente saranno mostrati i requisiti minimi per il funzionamento e i
valori attuale rilevati. Se non si dovessero riscontrare i requisiti minimi non
sarà possibile procedere con la configurazione di Zabbix Frontend Web. In tal
caso si raccomanda di verificare la procedura di installazione e rimediare prima
di configurare nuovamente Zabbix Frontend Web.

{:.center}
![Configure DB connection](/resources/articles/zabbix/frontend-setup/03.png)

Il passaggio principale della configurazione di Zabbix Frontend Web è la
configurazione della connessione al database e per far ciò è necessario indicare:

1. Il tipo di database utilizzato (in questo esempio **MySQL**)
1. L'indirizzo del server dove si trova il database (in questo esempio
   **localhost**)
1. Il numero di porta da utilizzare per accedere al database (in questo esempio
   è stato lasciato il valore 0 che fa riferimento alla porta 3306 predefinita
   di MySQL)
1. Il nome del database sul server dei database (in questo esempio **zabbix**)
1. Il nome utente valido per accedere al server e al database (in questo esempio
   **zabbix**)
1. La password di accesso correlata all'utente del server e del database

{:.center}
![Zabbix server details](/resources/articles/zabbix/frontend-setup/04.png)

Segue la procedura con l'indicazione dei dati di Zabbix Server:

1. Indicare l'indirizzo del server dove è in esecuzione Zabbix Server (in questo
   esempio **localhost** in quanto Zabbix Frontend Web è in esecuzione sulla
   stessa macchina dove è in esecuzione Zabbix Server)
1. Indicare il numero di porta sulla quale Zabbix Server è in ascolto, la
   porta predefinita di Zabbix Server è 10051
1. Indicare il nome che sarà visualizzato nell'interfaccia web di Zabbix per
   identificare il server controllato (in questo esempio **Zabbix Muflone**)

{:.center}
![Pre-installation summary](/resources/articles/zabbix/frontend-setup/05.png)

Prima di avviare la configurazione di Zabbix Frontend Web sarà data un'ultima
possibilità di visionare i dati immessi.

{:.center}
![Install](/resources/articles/zabbix/frontend-setup/06.png)

Se la procedura è andata a buon fine sarà mostrata una schermata di
congratulazioni che conferma il salvataggio della configurazione nel file
*zabbix.conf.php*.

Terminare la procedura guidata cliccando su **Finish**.

{:.center}
![Zabbix login](/resources/articles/zabbix/login.png)

Successivamente sarà automaticamente mostrata la finestra di accesso a
Zabbix Frontend Web.

La configurazione iniziale è terminata ed è il momento di
[passare ad utilizzare il nostro Zabbix][Frontend first view].

[Frontend first view]: frontend-first-view