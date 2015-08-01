---
title: Installare Arch Linux su Lenovo G50-70 (parte 16 - utenti e gruppi)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot (parte 16 - Utenti e gruppi di utenti)
keywords: arch, linux, lenovo, ideapad, g50-70, user, utente, groups, gruppo, getent, limitato, root, permessi
---

{% include installare-arch-linux-su-lenovo-g50-70-index.inc %}

Tutte le operazioni fino ad ora svolte sono state eseguite utilizzando l'utente
principale **root** con tutti i permessi sull'intero sistema.

Tuttavia, per l'utilizzo quotidiano del sistema, è sempre raccomandato l'uso di
un altro utente, di permessi limitati che possa agire esclusivamente nella
propria directory *home*, ovvero nella directory che contiene tutti i dati
personali dell'utente.

Ciascun utente avrà un identificativo di utente (UID = User ID) e un identificativo
di gruppo (GID = Group ID). I gruppi di utenti consentono di raggruppare permessi
a più utenti.

## Gruppi di utenti

Per conoscere l'elenco dei gruppi ai quali aggiungere gli utenti è possibile
utilizzare il comando **getent group**.

    [root@arch-lenovo ~]# getent group
    root:x:0:root
    bin:x:1:root,bin,daemon
    ...

La maggior parte dei gruppi di utenti sono ad uso del sistema mentre alcuni
gruppi aggiuntivi sono specifici per l'aggiunta di permessi agli utenti extra,
come i seguenti:

  * **root** consente ai membri accesso totale a tutte le parti del sistema
  * **adm** fornisce l'accesso a molti strumenti amministrativi
  * **tty** fornisce l'accesso ai dispositivi console come /dev/tty*
  * **disk** fornisce l'accesso alle periferiche disco, come dischi e partizioni
  * **lp** fornisce l'accesso alle periferiche di stampa
  * **wheel** consente agli utenti di diventare utente root col comando sudo
  * **uucp** fornisce l'accesso alle periferiche seriali come /dev/ttyS*
  * **locate** permette l'uso del comando updatedb (dal pacchetto mlocate)
  * **rfkill** permette di comandare l'accensione e lo spegnimento di periferiche
    WiFi o Bluetooth
  * **proc** consente di leggere le informazioni contenute nel file system /proc
  * **network** consente di controllare le connessioni di rete
  * **video** fornisce l'accesso alle periferiche video
  * **audio** fornisce l'accesso alle periferiche audio
  * **optical** fornisce l'accesso alle periferiche ottiche
  * **floppy** fornisce l'accesso alle periferiche floppy
  * **storage** fornisce l'accesso alle periferiche disco rimovibili
  * **scanner** fornisce l'accesso alle periferiche scanner
  * **input** fornisce l'accesso alle periferiche di input
  * **power** permette il controllo dell'alimentazione o della sospensione
  * **users** include i permessi standard per gli utenti limitati
  * **systemd-journal** consente l'accesso ai log di systemd

## Aggiungere un nuovo utente al sistema

Per aggiungere un nuovo utente è possibile utilizzare il comando **useradd** in
questa maniera:

    [root@arch-lenovo ~]# useradd -m -g users muflone

L'ultimo argomento **muflone** rappresenta il nome del nuovo utente da creare,
mentre l'argomento **-m** indica di creare una nuova directory home col nome
/home/muflone, infine l'argomento **-g users** indica il gruppo predefinito cui
l'utente appartiene, in questo caso **users**.

E' possibile specificare gruppi di utenti aggiuntivi con l'argomento **-G**,
ad esempio con:

    [root@arch-lenovo ~]# useradd -m -g users -G rfkill,systemd-journal muflone

L'utente muflone sarà automaticamente membro del gruppo **users** e dei gruppi
aggiuntivi **rfkill** (per l'uso del comando rfkill) e **systemd-journal** (per
la lettura del log di sistema col comando journalctl).

E' anche possibile aggiungere in un secondo momento un utente ad un gruppo
utilizzando il comando **gpasswd \-\-add UTENTE GRUPPO**.

    [root@arch-lenovo ~]# gpasswd --add muflone rfkill
    Aggiunta dell'utente muflone al gruppo rfkill
    
    [root@arch-lenovo ~]# gpasswd --add muflone systemd-journal
    Aggiunta dell'utente muflone al gruppo systemd-journal

Un utente per il sistema viene sempre identificato attraverso il suo UID,
sebbene molti programmi (come gpasswd ad esempio) richiedono l'uso del suo nome.
Alcuni strumenti (come i gestori grafici di login) visualizzano il nome completo
dell'utente, una sorta di descrizione associata a ciascun utente.

Per cambiare il nome completo dell'utente è possibile utilizzare il comando
**chfn \-\-full-name "NOME COMPLETO" UTENTE** come ad esempio.

    [root@arch-lenovo ~]# chfn --full-name "Muflone Ovinis" muflone
    Modifica delle informazioni finger per muflone in corso.
    
    Le informazioni finger sono state modificate.

## Verifica di un utente

Per verificare l'operazione appena eseguita è possibile utilizzare il comando
**id UTENTE**.

    [root@arch-lenovo ~]# id muflone
    uid=1000(muflone) gid=100(users) gruppi=100(users),24(rfkill),190(systemd-journal)

L'utente muflone avrà un identificativo personale (uid) 1000, un identificativo
di gruppo (gid) 100 e sarà presente nei gruppi 100 (users), 24 (rfkill) e 190
(systemd-journal).

Per verificare i gruppi cui un utente appartiene è possibile utilizzare il
comando **groups UTENTE**.

    [root@arch-lenovo ~]# groups muflone
    rfkill systemd-journal users

## Cambiare la password di accesso di un utente

Senza una password di accesso, normalmente non è permesso l'accesso al sistema.

Per assegnare una password di accesso al nuovo utente appena creato si potrà
utilizzare il comando **passwd UTENTE**.

    [root@arch-lenovo ~]# passwd muflone
    Immettere nuova password UNIX: 
    Reimmettere la nuova password UNIX: 
    passwd: password aggiornata correttamente

Quando richiesto, digitare la nuova password da assegnare all'utente. **Non
saranno mostrati asterischi** o altri simboli durante la digitazione per non
lasciare traccia della lunghezza della password. Limitarsi a digitare la
password, confermarla con invio e ridigitarla quando richiesto.

## Eliminazione di un utente

Per completezza di informazione è possibile eliminare un utente preesistente
utilizzando il comando **userdel**.

    [root@arch-lenovo ~]# userdel -r muflone
    userdel: muflone mail spool (/var/spool/mail/muflone) not found

L'argomento **-r** indica l'eliminazione di tutti i dati personali nella
directory home dell'utente da eliminare. Senza l'argomento -r la directory
personale non verrà eliminata.
