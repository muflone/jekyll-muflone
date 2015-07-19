---
title: Installare Arch Linux su Lenovo G50-70
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot
keywords: arch, linux, lenovo, ideapad, g50-70, uefi, secure boot
---

{% include installare-arch-linux-su-lenovo-g50-70-index.inc %}

{: .center}
[![Lenovo IdeaPad G50-70][lenovo-ideapad-g50-70-thumb.png]][lenovo-ideapad-g50-70.jpg]

Ho recentemente acquistato un Lenovo IdeaPad G50-70, un computer portatile che
includeva Microsoft Windows 8.1 preinstallato. Installare **Arch Linux** su
questo computer è possibile ma non così immediato e richiede varie operazioni.

Questo computer è dotato di **[UEFI]{:target="_blank"}** e tramite il suo firmware
consente di emulare il classico BIOS, più lento in fase di avvio. Oltre UEFI,
supporta anche il **[Secure Boot]{:target="_blank"}** un sistema atto ad impedire
l'uso di sistemi operativi non autorizzati dall'EFI.

Questa guida spiegherà l'installazione di Arch Linux affiancato a Windows 8.1
che quindi verrà lasciato al suo posto, dopo la naturale riduzione della partizione
operativo, mantenendo Secure Boot e UEFI attivi.

Il ridimensionamento della partizione di Windows per far posto alle nuove
partizioni per Arch Linux non viene trattato in questa guida.

La procedura di installazione sarà spiegata in vari parti:

{: .big}
>
* [Preparazione del sistema]({% post_url italian/2015-06-08-installare-arch-linux-su-lenovo-g50-70-1 %}).
* [Configurazione della connessione Wi-Fi]({% post_url italian/2015-06-09-installare-arch-linux-su-lenovo-g50-70-2 %}).
* [Partizionamento del disco]({% post_url italian/2015-06-10-installare-arch-linux-su-lenovo-g50-70-3 %}).
* [Installazione del sistema]({% post_url italian/2015-06-15-installare-arch-linux-su-lenovo-g50-70-4 %}).
* [Installazione del gestore di avvio]({% post_url italian/2015-06-16-installare-arch-linux-su-lenovo-g50-70-5 %}).
* [Funzionamento di rEFInd]({% post_url italian/2015-06-16-installare-arch-linux-su-lenovo-g50-70-6 %}).
* [Primo avvio del sistema]({% post_url italian/2015-06-16-installare-arch-linux-su-lenovo-g50-70-7 %}).
* [Riconfigurazione della connessione Wi-Fi]({% post_url italian/2015-06-17-installare-arch-linux-su-lenovo-g50-70-8 %}).
* [Aggiornamento del microcode]({% post_url italian/2015-06-19-installare-arch-linux-su-lenovo-g50-70-9 %}).
* [Il gestore di pacchetti pacman]({% post_url italian/2015-06-20-installare-arch-linux-su-lenovo-g50-70-10 %}).
* [Il sistema di avvio systemd]({% post_url italian/2015-06-24-installare-arch-linux-su-lenovo-g50-70-11 %}).
* [Accesso tramite SSH]({% post_url italian/2015-07-10-installare-arch-linux-su-lenovo-g50-70-12 %}).
* [Abilitare lo scorrimento del testo nella console]({% post_url italian/2015-07-11-installare-arch-linux-su-lenovo-g50-70-13 %}).
* [Installare l'ambiente grafico]({% post_url italian/2015-07-18-installare-arch-linux-su-lenovo-g50-70-14 %}).
* [Installazione di GNOME]({% post_url italian/2015-07-19-installare-arch-linux-su-lenovo-g50-70-15 %}).


[lenovo-ideapad-g50-70.jpg]: /resources/articles/2015-06/lenovo-ideapad-g50-70.jpg
[lenovo-ideapad-g50-70-thumb.png]: /resources/articles/2015-06/lenovo-ideapad-g50-70-thumb.png

[UEFI]: https://en.wikipedia.org/wiki/Unified_Extensible_Firmware_Interface
[Secure Boot]: https://msdn.microsoft.com/it-it/library/hh824987.aspx
