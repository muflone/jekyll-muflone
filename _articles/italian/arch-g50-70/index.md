---
layout: articles
title: Installare Arch Linux su Lenovo G50-70
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot
keywords: arch, linux, lenovo, ideapad, g50-70, uefi, secure boot
order: 200
content_after: false
---

{: .center }
![Lenovo IdeaPad G50-70](/resources/articles/arch-g50-70/lenovo-ideapad-g50-70-thumb.png)

Ho recentemente acquistato un Lenovo IdeaPad G50-70, un computer portatile che
includeva Microsoft Windows 8.1 preinstallato. Installare **Arch Linux** su
questo computer è possibile ma non così immediato e richiede varie operazioni.

Questo computer è dotato di **[UEFI]** e tramite il suo firmware consente di
emulare il classico BIOS, più lento in fase di avvio. Oltre UEFI, supporta anche
il **[Secure Boot]** un sistema atto ad impedire l'uso di sistemi operativi non
autorizzati dall'EFI.

Questa guida spiegherà l'installazione di Arch Linux affiancato a Windows 8.1
che quindi verrà lasciato al suo posto, dopo la naturale riduzione della partizione
operativo, mantenendo Secure Boot e UEFI attivi.

Il ridimensionamento della partizione di Windows per far posto alle nuove
partizioni per Arch Linux non viene trattato in questa guida.

La procedura di installazione sarà spiegata in vari parti:

{: target="_blank" .external }
[UEFI]: https://en.wikipedia.org/wiki/Unified_Extensible_Firmware_Interface

{: target="_blank" .external }
[Secure Boot]: https://msdn.microsoft.com/it-it/library/hh824987.aspx