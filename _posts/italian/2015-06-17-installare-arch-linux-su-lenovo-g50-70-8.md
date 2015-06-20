---
title: Installare Arch Linux su Lenovo G50-70 (parte 8 - riconfigurazione della Wi-Fi)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot
keywords: arch, linux, lenovo, ideapad, g50-70, rete, wifi, wlan, rfkill
---

Al primo avvio di Arch Linux sarà mostrato soltanto un prompt di accesso:

    Arch Linux 4.0.5-1-ARCH (tty1)
    
    arch-lenovo login:

Accedere al proprio sistema utilizzando il nome utente **root** e la password
impostata durante l'[installazione del sistema]({% post_url italian/2015-06-15-installare-arch-linux-su-lenovo-g50-70-4 %}#impostazione-della-password-di-root).

La prima operazione da eseguire è la
[riconfigurazione della connessione Wi-Fi]({% post_url italian/2015-06-09-installare-arch-linux-su-lenovo-g50-70-2 %})
come si è fatto durante la fase di installazione.

    [root@arch-lenovo ~]# rfkill list wlan
    1: ideapad_wlan: Wireless LAN
      Soft blocked: yes
      Hard blocked: no
    2: phy0: Wireless LAN
      Soft blocked: yes
      Hard blocked: no

    [root@arch-lenovo ~]# rfkill unblock wlan

    [root@arch-lenovo ~]# wifi-menu
    Scanning for networks... done

Seguire la procedura guidata come fatto in precedenza e riconfigurare la rete.
Al termine eseguire una semplice verifica di navigazione.

    [root@arch-lenovo ~]# ping -c 4 www.muflone.com
    PING muflone.com (198.38.82.4) 56(84) bytes of data.
    64 bytes from mocha3006.mochahost.com (198.38.82.4): icmp_seq=1 ttl=49 time=141 ms
    64 bytes from mocha3006.mochahost.com (198.38.82.4): icmp_seq=2 ttl=49 time=141 ms
    64 bytes from mocha3006.mochahost.com (198.38.82.4): icmp_seq=3 ttl=49 time=143 ms
    64 bytes from mocha3006.mochahost.com (198.38.82.4): icmp_seq=4 ttl=49 time=141 ms

    --- muflone.com ping statistics ---
    4 packets transmitted, 4 received, 0% packet loss, time 3003ms
    rtt min/avg/max/mdev = 141.060/141.618/143.047/0.829 ms

Se venisse risposto **unknown host** oppure **no route to host** c'è un problema
con la connessione Wi-Fi, riprovare la configurazione o verificare i parametri
di configurazione.

Dopo aver verificato il buon funzionamento della rete Wi-Fi è raccomandato
attivare automaticamente il nuovo profilo di rete creato con wifi-menu in modo
che ad ogni avvio non sia necessario riconfigurare la rete.

Il comando **netctl list** mostrerà il nome del profilo di rete che è stato
configurato in precedenza.

    [root@arch-lenovo ~]# netctl list
      wlp2s0-MLWG2-75F4

Per attivarlo automaticamente all'avvio del sistema eseguire **netctl enable NOME**.

    [root@arch-lenovo ~]# netctl enable wlp2s0-MLWG2-75F4
    ln -s '/etc/systemd/system/netctl@wlp2s0\x2dMLWG2\x2d75F4.service' '/etc/systemd/system/multi-user.target.wants/netctl@wlp2s0\x2dMLWG2\x2d75F4.service'

Riavviare quindi il sistema con **reboot** o **systemctl reboot** per verificare
la corretta riconfigurazione della rete Wi-Fi.

    [root@arch-lenovo ~]# systemctl reboot
