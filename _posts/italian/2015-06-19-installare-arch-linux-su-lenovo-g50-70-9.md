---
title: Installare Arch Linux su Lenovo G50-70 (parte 9 - aggiornamento del Microcode)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot (parte 9 - Aggiornamento del microcode)
keywords: arch, linux, lenovo, ideapad, g50-70, microcode, intel
---

Un'operazione preliminare da eseguire è l'installazione del software del
**[Microcode]**{:target="_blank"} del processore, una sorta di aggiornamento
software del codice del firmware del processore.

Il processo di aggiornamento è puramente software e non permanente, ovvero ad
ogni riavvio verrà nuovamente applicato.

## Installazione del Microcode Intel

Per installare l'aggiornamento del Microcode del processore Intel di questo
computer installare il pacchetto **intel-ucode**

    [root@arch-lenovo ~]# pacman -S intel-ucode
    risoluzione delle dipendenze in corso...
    ricerca dei pacchetti in conflitto in corso...

    Pacchetti (1) intel-ucode-20150121-1

    Dimensione totale dei pacchetti da scaricare:   0,50 MiB
    Dimensione totale dei pacchetti da installare:  0,64 MiB

    :: Vuoi procedere con l'installazione? [S/n] 
    :: Download dei pacchetti in corso...
     intel-ucode-20150121-1-any       509,5 KiB   227K/s 00:02 [####################################] 100%
    (1/1) verifica delle chiavi presenti nel portachiavi       [####################################] 100%
    (1/1) verifica dell'integrità dei pacchetti                [####################################] 100%
    (1/1) caricamento dei file dei pacchetti                   [####################################] 100%
    (1/1) controllo dei conflitti in corso                     [####################################] 100%
    (1/1) controllo dello spazio disponibile sul disco         [####################################] 100%
    (1/1) installazione in corso di intel-ucode                [####################################] 100%

## Attivazione del Microcode Intel

Per attivare il nuovo Microcode è necessario modificare il file di avvio del
kernel Linux usato da rEFInd. Si tratta del file **/boot/refind_linux.conf**.

    [root@arch-lenovo ~]# nano /boot/refind_linux.conf
    
Non modificare il valore dopo UUID (qui indicato con xxx), mantenendo quello
proposto automaticamente e modificare soltanto la prima riga aggiungendo al
termine **initrd=intel-ucode.img initrd=initramfs-linux.img** come segue:

    "Boot with standard options"  "ro root=UUID=xxx   initrd=/intel-ucode.img initrd=/initramfs-linux.img"
    "Boot to single-user mode"    "ro root=UUID=xxx   single"
    "Boot with minimal options"   "ro root=UUID=xxx"

Salvare il file premendo **\<Control\>+O**, confermare con invio e **\<Control>+X**
per uscire dall'editor di testo.

## Verifica del Microcode in uso

    [root@arch-lenovo ~]# dmesg | grep microcode
    [    0.419461] microcode: CPU0 sig=0x40651, pf=0x40, revision=0x17
    [    0.419467] microcode: CPU1 sig=0x40651, pf=0x40, revision=0x17
    [    0.419474] microcode: CPU2 sig=0x40651, pf=0x40, revision=0x17
    [    0.419482] microcode: CPU3 sig=0x40651, pf=0x40, revision=0x17
    [    0.419526] microcode: Microcode Update Driver: v2.00 <tigran@aivazian.fsnet.co.uk>, Peter Oruba

Riavviare il sistema con la nuova impostazione

    [root@arch-lenovo ~]# systemctl reboot

Verificare nuovamente la versione di Microcode in uso:
    
    [root@arch-lenovo ~]# dmesg | grep microcode
    [    0.000000] CPU0 microcode updated early to revision 0x1c, date = 2014-07-03
    [    0.143357] CPU2 microcode updated early to revision 0x1c, date = 2014-07-03
    [    0.414865] microcode: CPU0 sig=0x40651, pf=0x40, revision=0x1c
    [    0.414871] microcode: CPU1 sig=0x40651, pf=0x40, revision=0x1c
    [    0.414878] microcode: CPU2 sig=0x40651, pf=0x40, revision=0x1c
    [    0.414886] microcode: CPU3 sig=0x40651, pf=0x40, revision=0x1c
    [    0.414931] microcode: Microcode Update Driver: v2.00 <tigran@aivazian.fsnet.co.uk>, Peter Oruba

Come si può notare la versione del Microcode è stata aggiornata dalla **revisione
0x17** (ovvero 23) alla **revisione 0x1c** (ovvero 28).


[Microcode]: https://wiki.archlinux.org/index.php/Microcode