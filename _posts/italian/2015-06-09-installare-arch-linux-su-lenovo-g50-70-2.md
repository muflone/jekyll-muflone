---
title: Installare Arch Linux su Lenovo G50-70 (parte 2 - connessione Wi-Fi)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot
keywords: arch, linux, lenovo, ideapad, g50-70, rete, wifi, wlan, rfkill
---

{: .center}
![arch-linux-prompt.png]

Prima di procedere all'installazione del sistema operativo è necessario
configurare la rete affinché possano essere scaricati i pacchetti di installazione,
non presenti nell'immagine di installazione del sistema operativo.

-----

#Attivazione del controller Wi-Fi

Inizialmente il controller Wi-Fi risulterà essere disattivato come confermato
dal comando **rfkill list wlan**

    root@archiso ~ # rfkill list wlan
    1: phy0: Wireless LAN
      Soft blocked: yes
      Hard blocked: no
    2: ideapad_wlan: Wireless LAN
      Soft blocked: yes
      Hard blocked: no

Prima di poter utilizzare l'interfaccia di rete sarà necessario sbloccarla col
comando **rfkill unblock wlan**

    root@archiso ~ # rfkill unblock wlan

-----

#Configurazione della connessione Wi-Fi

Sarà quindi possibile eseguire la configurazione della rete Wi-Fi attraverso
il comando **wifi-menu**

    root@archiso ~ # wifi-menu
    Scanning for networks... done

{: .center}
![wifi-menu-1.png]

Utilizzando le freccette scegliere la connessione Wi-Fi desiderata e confermare
premendo invio.

{: .center}
![wifi-menu-2.png]

Quando richiesto, specificare la password (WEP o WPA) per la connessione scelta
e confermare con invio.

{: .center}
![wifi-menu-3.png]

Salvare il profilo di rete appena configurato confermando con invio.

La connessione sarà automaticamente avviata e si riceverà l'indirizzo IP di
rete attraverso DHCP.


[arch-linux-prompt.png]: /resources/articles/2015-06/arch-linux-prompt.png
[wifi-menu-1.png]: /resources/articles/2015-06/wifi-menu-1.png
[wifi-menu-2.png]: /resources/articles/2015-06/wifi-menu-2.png
[wifi-menu-3.png]: /resources/articles/2015-06/wifi-menu-3.png
