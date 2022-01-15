---
layout: article
title: Installazione su Arch Linux
slug: install-to-arch-linux
category: italian
tags:
  - zabbix
keywords: zabbix, installazione, arch, linux, pacman, pacchetti
description: L'installazione di Zabbix Server su Arch Linux richiede un minimo
             di configurazione delle varie componenti. Questa guida spiega i
             passaggi fino all'avvio di Zabbix Frontend Web.
order: 406
date: 2018-04-18T00:00:00Z
---

{:.center}
![Zabbix logo](/resources/articles/zabbix/logo.png)

L'installazione di Zabbix Server e Zabbix Frontend Web su Arch Linux non viene
documentata sul sito ufficiale. Sul [Wiki di Arch Linux] la procedura di
installazione è spiegata molto bene e ad oggi risulta correttamente funzionante.

# Installazione dei pacchetti necessari

Installare innanzitutto i pacchetti **zabbix-server** e **zabbix-frontend-php**.

    # pacman -S zabbix-server
    # pacman -S zabbix-frontend-php

# Configurazione del database MariaDB/MySQL

Sono poi necessari un database a scelta tra PostgreSQL e MySQL/MariaDB. Nel caso
di MariaDB è possibile installare e configurare il database con i comandi seguenti:

    # pacman -S mariadb
    # mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
    # systemctl enable mariadb
    # systemctl start mariadb
    # mysql_secure_installation
    Enter current password for root (enter for none): (premere invio)
    Set root password? [Y/n] Y
    New password: (inserire la password per l'utente root di MySQL)
    Re-enter new password: (reinserire la stessa password)
    Remove anonymous users? [Y/n] Y
    Disallow root login remotely? [Y/n] Y
    Remove test database and access to it? [Y/n] Y
    Reload privilege tables now? [Y/n] Y

Serve creare anche un nuovo utente dedicato a Zabbix e il relativo database.

>>>>>> La password scelta per l'utente **zabbix** è **zabxpassword**, modificare
la scelta a proprio piacimento.

    mysql -u root -p -e "create database zabbix character set utf8"
    mysql -u root -p -e "grant all on zabbix.* to zabbix@localhost identified by 'zabxpassword'"

Quando richiesto, inserire la password **dell'utente root** configurata in
precedenza col comando *mysql_secure_installation*.

Per procedere con la creazione del database di Zabbix utilizzare la password
**dell'utente zabbix** appena configurato.

    mysql -u zabbix -p zabbix < /usr/share/zabbix-server/mysql/schema.sql
    mysql -u zabbix -p zabbix < /usr/share/zabbix-server/mysql/images.sql
    mysql -u zabbix -p zabbix < /usr/share/zabbix-server/mysql/data.sql

# Configurare il database di Zabbix

Serve comunicare a Zabbix i dati di accesso per il database appena configurato.
Tutto ciò è fattibile modificando i valori seguenti dal file
/etc/zabbix/zabbix_server.conf (tenere presente che le righe che iniziano con #
sono commenti e non vengono utilizzate).

    DBHost=localhost
    DBName=zabbix
    DBUser=zabbix
    DBPassword=zabxpassword

# Configurazione del server web

Oltre il database è necessario installare anche il server web, in questo esempio
Apache.

    # pacman -S apache
    # systemctl enable httpd

A questo punto resta da configurare il server web Apache. Il Wiki ufficiale di
Arch Linux suggerisce la soluzione per avere Zabbix installato in una directory
della radice del server web (ad esempio *http://indirizzo/zabbix*):

    # ln -s /usr/share/webapps/zabbix/ /srv/http/zabbix

Nel caso che si volesse invece installare Zabbix sulla radice del server web
(ad esempio *http://indirizzo/*) è possibile rimuovere la directory /srv/http e
rifare il collegamento su /srv/http:

    # rm /srv/http
    # ln -s /usr/share/webapps/zabbix/ /srv/http

# Configurazione dell'interprete PHP

Installare l'interprete PHP per il server web Apache:

    # pacman -S php-apache

Abilitare l'interprete PHP nella configurazione di Apache, modificando il file
/etc/httpd/conf/httpd.conf

Modificare le righe:

    #LoadModule mpm_event_module modules/mod_mpm_event.so
    LoadModule mpm_prefork_module modules/mod_mpm_prefork.so

Quindi aggiungere in fondo al file:

    LoadModule php7_module modules/libphp7.so
    AddHandler php7-script .php
    Include conf/extra/php7_module.conf

Configurare quindi PHP con i valori seguenti, andando a modificare il file
/etc/php/php.ini:

    extension=bcmath
    extension=gd
    extension=sockets
    extension=mysqli
    extension=gettext
    post_max_size = 16M
    max_execution_time = 300
    max_input_time = 300
    date.timezone = "UTC"

# Avvio di Zabbix Server

E' giunto il momento di avviare il server web e Zabbix Server

    # systemctl enable zabbix-server-mysql
    # systemctl start zabbix-server-mysql
    # systemctl start httpd

# Configurazione di Zabbix Frontend Web

Per la configurazione del frontend web è possibile consultare la pagina
[Configurazione iniziale di Zabbix Frontend Web][Frontend setup].


{: target="_blank" .external }
[Wiki di Arch Linux]: https://wiki.archlinux.org/index.php/Zabbix

[Frontend setup]: frontend-setup.html
