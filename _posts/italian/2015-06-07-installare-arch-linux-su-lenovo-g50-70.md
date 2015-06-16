---
title: Installare Arch Linux su Lenovo G50-70
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot
keywords: arch, linux, lenovo, ideapad, g50-70, uefi, secure boot
---

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

La procedura di installazione sarà spiegata in vari passaggi:

> [Preparazione del sistema]({% post_url italian/2015-06-08-installare-arch-linux-su-lenovo-g50-70-1 %}).
{: .big}
> [Configurazione della connessione Wi-Fi]({% post_url italian/2015-06-09-installare-arch-linux-su-lenovo-g50-70-2 %}).
{: .big}
> [Partizionamento del disco]({% post_url italian/2015-06-10-installare-arch-linux-su-lenovo-g50-70-3 %}).
{: .big}
> [Installazione del sistema]({% post_url italian/2015-06-15-installare-arch-linux-su-lenovo-g50-70-4 %}).
{: .big}
> [Installazione del gestore di avvio]({% post_url italian/2015-06-16-installare-arch-linux-su-lenovo-g50-70-5 %}).
{: .big}
> [Funzionamento di rEFInd]({% post_url italian/2015-06-16-installare-arch-linux-su-lenovo-g50-70-6 %}).
{: .big}


[lenovo-ideapad-g50-70.jpg]: /resources/articles/2015-06/lenovo-ideapad-g50-70.jpg
[lenovo-ideapad-g50-70-thumb.png]: /resources/articles/2015-06/lenovo-ideapad-g50-70-thumb.png

[UEFI]: https://en.wikipedia.org/wiki/Unified_Extensible_Firmware_Interface
[Secure Boot]: https://msdn.microsoft.com/it-it/library/hh824987.aspx
