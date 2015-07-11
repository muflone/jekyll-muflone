---
title: Installare Arch Linux su Lenovo G50-70 (parte 11 - systemd)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot (parte 11 - Il sistema di avvio systemd)
keywords: arch, linux, lenovo, ideapad, g50-70, systemd, servizi, avvio, esecuzione
---

{% include installare-arch-linux-su-lenovo-g50-70-index.inc %}

A differenza di tante altre distribuzioni GNU/Linux, Arch Linux ha abbandonato
il consueto sistema di avvio storico (chiamato SysVinit) e ha recentemente
adottato un nuovo sistema di avvio chiamato **[systemd]{:target="_blank"}**.

Il nuovo sistema di avvio è installato col pacchetto di installazione di base e
include gli strumenti per l'avvio, il controllo e l'attivazione automatica dei
servizi.

La quasi totalità degli strumenti su Arch Linux è già predisposto al funzionamento
con systemd. 

Spiegare systemd non è argomento facile, limiterò ad accennare le operazioni di
base, utili per configurare il proprio sistema e per svolgere le attività più comuni.

Per una spiegazione più approfondita consultare le seguenti pagine:

* <https://wiki.freedesktop.org/www/Software/systemd/>{:target="_blank"}
* <http://0pointer.net/blog/archives.html>{:target="_blank"}
* <https://wiki.archlinux.org/index.php/Systemd>{:target="_blank"}
* <https://n0where.net/understanding-systemd/>{:target="_blank"}

-----

# Controllo dei servizi

Il primo degli strumenti di systemd è **systemctl**, un programma che consente
di controllare, avviare, interrompere, verificare lo stato dei vari servizi,
non solo di rete ma anche di parti del sistema che vanno avviate affinché altre
parti possano funzionare, come ad esempio il montaggio delle partizioni, il
caricamento dei moduli, l'impostazione del nome del sistema e tanto altro.

Tutte queste parti del sistema sono configurate in **unit**, ognuna delle quali
si occupa della configurazione e del controllo di ciò che comandano.

Le tipologie di unit disponibili in systemd sono le segenti:

* **service**: riguardano un processo (un programma) controllato da systemd
* **socket**: riguardano socket di rete o file FIFO
* **busname**: controllano bus di tipo D-BUS
* **target**: riguardano gruppi di unit in una maniera simile ai runlevel di SysVinit
* **snapshot**: rappresentano lo stato memorizzato di systemd
* **device**: riguardano dispositivi e periferiche del sistema
* **mount**: riguardano punti di mount
* **automount**: riguardano punti di mount che saranno automaticamente montati
* **swap**: riguardano file o partizioni di swap
* **timer**: riguardano attività da eseguire in maniera temporizzata
* **path**: riguardano attività da eseguire legate alla presenza di percorsi o file
* **slice**: riguardano porzioni di risorse di un gruppo di processi
* **scope**: gestiscono un gruppo di processi di sistema

La quasi totalità delle unit configurabili e attivabili sono di tipo service.
Le unit di tipo target identificano i possibili stati nei quali si trova il
sistema, sia esso in fase di avvio, spegnimento, ambiente grafico, testuale o
solo di emergenza.

## Visualizzare l'elenco delle unit avviate

Per visualizzare l'elenco di tutte le unit in esecuzione, escluse quindi quelle
non avviate e quelli avviate che abbiano terminato la loro esecuzione utilizzare
il comando systemctl.

    [root@arch-lenovo ~]# systemctl
    UNIT                                                 LOAD   ACTIVE SUB       DESCRIPTION
    proc-sys-fs-binfmt_misc.automount                    loaded active waiting   Arbitrary Executable File Formats File System Automount Point
    sys-devices-platform-serial8250-tty-ttyS0.device     loaded active plugged   /sys/devices/platform/serial8250/tty/ttyS0
    sys-devices-platform-serial8250-tty-ttyS1.device     loaded active plugged   /sys/devices/platform/serial8250/tty/ttyS1
    -.mount                                              loaded active mounted   /
    boot.mount                                           loaded active mounted   /boot
    dev-hugepages.mount                                  loaded active mounted   Huge Pages File System
    dev-mqueue.mount                                     loaded active mounted   POSIX Message Queue File System
    home.mount                                           loaded active mounted   /home
    ...

Per visualizzare soltanto le unit di un determinato tipo aggiungere \-\-type=TIPO
come ad esempio:

    [root@arch-lenovo ~]# systemctl --type=service
    UNIT                                                 LOAD   ACTIVE SUB     DESCRIPTION
    dbus.service                                         loaded active running D-Bus System Message Bus
    getty@tty1.service                                   loaded active running Getty on tty1
    kmod-static-nodes.service                            loaded active exited  Create list of required static device nodes for the current kernel
    netctl@wlp2s0\x2dMLWG2\x2d75F4.service               loaded active exited  Automatically generated profile by wifi-menu
    ...

## Visualizzare l'elenco di tutte le unit

Per visualizzare tutte le unit caricate incluse quelle inattive che hanno 
terminato la loro esecuzione utilizzare:

    [root@arch-lenovo ~]# systemctl --all
      UNIT                                               LOAD      ACTIVE   SUB       DESCRIPTION
      proc-sys-fs-binfmt_misc.automount                  loaded    active   waiting   Arbitrary Executable File Formats File System Automount Point
    ● org.freedesktop.login1.busname                     not-found inactive dead      org.freedesktop.login1.busname
      dev-cdrom.device                                   loaded    active   plugged   PLDS_DVD-RW_DA8A5SH
      ...

Per visualizzare tutte le unit configurate utilizzare, incluse quelle non
avviate, quelle terminate, quelle non configurate per l'avvio:

    [root@arch-lenovo ~]# systemctl list-unit-files

    UNIT FILE                                            STATE 
    proc-sys-fs-binfmt_misc.automount                    static
    dev-hugepages.mount                                  static
    dev-mqueue.mount                                     static
    proc-sys-fs-binfmt_misc.mount                        static
    sys-fs-fuse-connections.mount                        static
    sys-kernel-config.mount                              static
    sys-kernel-debug.mount                               static
    tmp.mount                                            static
    ...

## Ricaricare l'elenco delle unit

Per ricaricare in memoria l'elenco delle unit, che possono essere state
cambiate dall'ultimo riavvio, è possibile usare:

    [root@arch-lenovo ~]# systemctl daemon-reload

## Fermare una unit

Se una unit è in esecuzione è possibile interromperne l'esecuzione utilizzando
**systemctl stop NOME**

    [root@arch-lenovo ~]# systemctl stop logrotate.service
    Warning: Stopping logrotate.service, but it can still be activated by:
      logrotate.timer 

Il messaggio avvisa che la unit, sebbene fermata, possa essere nuovamente
attivata dalla unit logrotate.timer che in determinati momenti può avviare
la unit logrotate.service.

## Avviare o riavviare una unit

E' possibile avviare una unit ferma utilizzando la sintassi: **systemctl start NOME**

    [root@arch-lenovo ~]# systemctl start logrotate.service

E' anche possibile eseguire in un'unica operazione il riavvio (ovvero l'interruzione
e il successivo avvio) di una unit utilizzando la sintassi **systemctl restart NOME**

    [root@arch-lenovo ~]# systemctl restart logrotate.service

## Controllare lo stato di una unit

Per controllare lo stato di una unit è possibile utilizzare il comando
**systemctl status NOME**

    [root@arch-lenovo ~]# systemctl status logrotate.service
    ● logrotate.service - Rotate log files
       Loaded: loaded (/usr/lib/systemd/system/logrotate.service; static; vendor preset: disabled)
       Active: inactive (dead) since gio 2015-06-25 00:00:18 CEST; 13min ago
      Process: 511 ExecStart=/usr/bin/logrotate /etc/logrotate.conf (code=exited, status=0/SUCCESS)
     Main PID: 511 (code=exited, status=0/SUCCESS)

    giu 25 00:00:16 arch-lenovo systemd[1]: Starting Rotate log files...
    giu 25 00:00:18 arch-lenovo systemd[1]: Started Rotate log files.

Sarà visualizzato il percorso dove è configurata la unit, lo stato predefinito,
lo stato attuale (loaded inactive), il comando effettivo che la unit controlla,
il suo PID (Process IDentifier) e un breve log dell'attività della unit.

Per visualizzare il log completo della unit interessata aggiungere l'argomento
\-\-full come ad esempio:

    [root@arch-lenovo ~]# systemctl --full status logrotate.service

## Configurare l'avvio automatico di una unit

Le unit generalmente vengono avviate soltanto se siano dipendenze di altre unit
avviate automaticamente (come quelle static) oppure se siano state configurate
esplicitamente per l'avvio automatico.

E' possibile avviare automaticamente una unit utilizzando la sintassi:
**systemctl enable NOME**

    [root@arch-lenovo ~]# systemctl enable iptables.service
    Created symlink from /etc/systemd/system/multi-user.target.wants/iptables.service to /usr/lib/systemd/system/iptables.service.

Questa operazione effettivamente crea semplicemente un link simbolico in
/etc/systemd alla unit interessata, in modo che al prossimo avvio del sistema
possa essere eseguita automaticamente.

Per disattivare una unit configurata per l'avvio automatico è possibile utilizzare
**systemctl disable NOME**

    [root@arch-lenovo ~]# systemctl disable iptables.service 
    Removed symlink /etc/systemd/system/multi-user.target.wants/iptables.service.

L'operazione semplicemente elimina il collegamento simbolico da /etc/systemd

Per controllare se una unit sia in avvio automatico è possibile usare:

    [root@arch-lenovo ~]# systemctl is-enabled iptables.service
    disabled

## Disabilitare e riabilitare una unit

Per disabilitare forzatamente qualsiasi avvio di una unit, sia esso automatico
sia esso manuale è disponibile il comando **systemctl mask NOME**

    [root@arch-lenovo ~]# systemctl mask iptables.service
    Created symlink from /etc/systemd/system/iptables.service to /dev/null.

    [root@arch-lenovo ~]# systemctl start iptables.service
    Failed to start iptables.service: Unit iptables.service is masked.

Per rimuovere la disabilitazione all'avvio la sintassi invece è:
**systemctl unmask NOME**

    [root@arch-lenovo ~]# systemctl unmask iptables.service
    Removed symlink /etc/systemd/system/iptables.service.

-----

# Controllo del sistema

Lo strumento systemctl si occupa anche del controllo dello stato del sistema.

## Riavviare il sistema

Per riavviare immediatamente il sistema operativo utilizzare:

    [root@arch-lenovo ~]# systemctl reboot

## Spegnere il sistema

Per spegnere immediatamente il sistema:

    [root@arch-lenovo ~]# systemctl poweroff

## Mandare il sistema in sospensione (stand-by)

E' possibile mandare il sistema in sospensione senza spegnerlo utilizzando:

    [root@arch-lenovo ~]# systemctl suspend

Sebbene questa caratteristica sia studiata per il risparmio energetico quando
il computer non viene utilizzato, il sistema resterà avviato e basterà premere
un pulsante qualsiasi per farlo riprendere dalla sospensione.

## Ibernare il sistema

L'ibernazione consiste nel salvare su disco (nella partizione swap) tutti i
dati presenti nella RAM e quindi spegnere il computer. Riavviando il sistema
verranno recuperati i dati dalla swap e riposizionati in RAM affinché il sistema
possa riprendere l'esecuzione dove era stato lasciato.

    [root@arch-lenovo ~]# systemctl hibernate

**Nota bene!** Il processo di ibernazione non è esente da errori e determinati
driver possono bloccare la fase di ibernazione e perfino mandare il sistema in
errore durante la fase di chiusura.

-----

# Il registro di sistema

Con systemd è stato centralizzato il registro di sistema e reso consultabile
mediante lo strumento **journalctl**. All'interno del registro si troveranno
informazioni scritte da parte del kernel, dei moduli, di processi, unit e
quant'altro.

## Visualizzare l'intero registro di sistema

Per visualizzare l'intero registro di sistema basterà richiamare il comando
journalctl senza argomenti.

    [root@arch-lenovo ~]# journalctl
    
    -- Logs begin at mar 2015-06-16 21:18:01 CEST, end at gio 2015-06-25 00:57:06 CEST. --
    giu 16 21:18:01 arch-lenovo systemd-journal[159]: Runtime journal is using 8.0M (max allowed 293.2M, trying to leave 439.8M free of 2.8G available → current limit 293.2M).
    giu 16 21:18:02 arch-lenovo systemd-journal[159]: Permanent journal is using 8.0M (max allowed 2.8G, trying to leave 4.0G free of 27.0G available → current limit 2.8G).
    giu 16 21:18:02 arch-lenovo systemd-journal[159]: Time spent on flushing to /var is 560us for 2 entries.
    giu 16 21:18:02 arch-lenovo kernel: Initializing cgroup subsys cpuset
    giu 16 21:18:02 arch-lenovo kernel: Initializing cgroup subsys cpu
    giu 16 21:18:02 arch-lenovo kernel: Initializing cgroup subsys cpuacct

## Visualizzare il registro dall'ultimo avvio

La registrazione mostrerà tutti i messaggi presenti, dall'inizio delle
registrazioni. E' possibile visualizzare il registro a partire dall'ultimo
avvio del sistema utilizzando:

    [root@arch-lenovo ~]# journalctl --boot
    
    -- Logs begin at mar 2015-06-16 21:18:01 CEST, end at gio 2015-06-25 00:58:58 CEST. --
    giu 25 00:44:09 arch-lenovo systemd-journal[142]: Runtime journal is using 8.0M (max allowed 293.2M, trying to leave 439.8M free of 2.8G available → current limit 293.2M).
    giu 25 00:44:09 arch-lenovo systemd-journal[142]: Runtime journal is using 8.0M (max allowed 293.2M, trying to leave 439.8M free of 2.8G available → current limit 293.2M).
    giu 25 00:44:09 arch-lenovo kernel: CPU0 microcode updated early to revision 0x1c, date = 2014-07-03
    giu 25 00:44:09 arch-lenovo kernel: Initializing cgroup subsys cpuset
    giu 25 00:44:09 arch-lenovo kernel: Initializing cgroup subsys cpu
    giu 25 00:44:09 arch-lenovo kernel: Initializing cgroup subsys cpuacct

## Visualizzare il registro di avvii precedenti

E' anche possibile visualizzare la registrazione di un avvio precedente, dapprima
consultando la lista degli avvii con:

    [root@arch-lenovo ~]# journalctl --list-boots
    -16 6e0e879d5b644fc9bde271ab5848095a mar 2015-06-16 21:18:01 CEST—mar 2015-06-16 21:21:38 CEST
    -15 6387b2e33020485a84ead68ccb654d30 mer 2015-06-17 20:22:40 CEST—mer 2015-06-17 20:52:39 CEST
    -14 9ad92a9a4d734844a218829513af7a32 mer 2015-06-17 20:52:55 CEST—mer 2015-06-17 20:59:06 CEST
    -13 5888388f4db7491b9ed329522496eade mer 2015-06-17 20:59:22 CEST—mer 2015-06-17 21:00:05 CEST
    -12 b25f8739a2d5403095c5a7ca195d685d mer 2015-06-17 21:00:40 CEST—mer 2015-06-17 21:01:00 CEST
    -11 d9dc9c60f1e84d18b1dd2c90d90488c6 mer 2015-06-17 21:01:17 CEST—mer 2015-06-17 21:14:09 CEST
    -10 95ad887028574c60b71a71dca71d452b mer 2015-06-17 21:14:32 CEST—mer 2015-06-17 21:26:39 CEST
     -9 39846a5cb4034dd9b61d6f59d2721859 ven 2015-06-19 15:46:07 CEST—ven 2015-06-19 17:57:27 CEST
     -8 77b88b2900e7420096bef597ea09532c ven 2015-06-19 17:57:43 CEST—ven 2015-06-19 18:12:25 CEST
     -7 ac36a8f15ab64bde966f27ae16c5c86d ven 2015-06-19 18:13:37 CEST—ven 2015-06-19 18:27:40 CEST
     -6 3365111753334bd8b0b2706b8a9eb4e5 ven 2015-06-19 18:27:56 CEST—ven 2015-06-19 18:38:59 CEST
     -5 739c23b9cb2d40b78215692133403f17 ven 2015-06-19 18:39:15 CEST—ven 2015-06-19 21:40:03 CEST
     -4 2cd08dcb699b432eaed4e3d5b9cf662f sab 2015-06-20 15:49:11 CEST—sab 2015-06-20 17:00:54 CEST
     -3 e4d540a3e6024683af07e16f3764855e sab 2015-06-20 17:01:17 CEST—sab 2015-06-20 17:34:36 CEST
     -2 b3c8357e2c97497180f404ddaaea065b mer 2015-06-24 23:11:42 CEST—gio 2015-06-25 00:41:56 CEST
     -1 bef9b450a4dc43379d9b7e8ee7f78cfe gio 2015-06-25 00:42:15 CEST—gio 2015-06-25 00:43:11 CEST
      0 54eac59386044cb187dc0b50641c70e8 gio 2015-06-25 00:44:09 CEST—gio 2015-06-25 00:58:58 CEST

Quindi per visualizzare la registrazione di un avvio specifico utilizzare la
sintassi: **journalctl --boot -NUMERO**

    [root@arch-lenovo ~]# journalctl --boot -9
    -- Logs begin at mar 2015-06-16 21:18:01 CEST, end at gio 2015-06-25 00:58:58 CEST. --
    giu 24 23:11:42 arch-lenovo systemd-journal[143]: Runtime journal is using 8.0M (max allowed 293.2M, trying to leave 439.8M free of 2.8G available → current limit 293.2M).
    giu 24 23:11:42 arch-lenovo systemd-journal[143]: Runtime journal is using 8.0M (max allowed 293.2M, trying to leave 439.8M free of 2.8G available → current limit 293.2M).
    giu 24 23:11:42 arch-lenovo kernel: CPU0 microcode updated early to revision 0x1c, date = 2014-07-03

## Visualizzare i messaggi di una unit

Per visualizzare il registro dei messaggi prodotti da una unit specifica è
possibile utilizzare la sintassi: **journalctl --unit NOME**

    [root@arch-lenovo ~]# journalctl --unit logrotate.service
    -- Logs begin at mar 2015-06-16 21:18:01 CEST, end at gio 2015-06-25 00:58:58 CEST. --
    giu 17 20:22:48 arch-lenovo systemd[1]: Starting Rotate log files...
    giu 17 20:22:49 arch-lenovo systemd[1]: Started Rotate log files.
    -- Reboot --
    giu 19 15:46:16 arch-lenovo systemd[1]: Starting Rotate log files...
    giu 19 15:46:16 arch-lenovo systemd[1]: Started Rotate log files.
    ...

## Visualizzare i messaggi del kernel

Per visualizzare i messaggi del kernel e dei moduli del kernel è possibile
utilizzare la sintassi **journalctl --dmesg**

    [root@arch-lenovo ~]# journalctl --dmesg 
    -- Logs begin at mar 2015-06-16 21:18:01 CEST, end at gio 2015-06-25 00:58:58 CEST. --
    giu 25 00:44:09 arch-lenovo kernel: CPU0 microcode updated early to revision 0x1c, date = 2014-07-03
    giu 25 00:44:09 arch-lenovo kernel: Initializing cgroup subsys cpuset
    giu 25 00:44:09 arch-lenovo kernel: Initializing cgroup subsys cpu
    giu 25 00:44:09 arch-lenovo kernel: Initializing cgroup subsys cpuacct


[systemd]: https://wiki.freedesktop.org/www/Software/systemd/