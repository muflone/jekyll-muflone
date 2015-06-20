---
title: Installare Arch Linux su Lenovo G50-70 (parte 7 - primo avvio del sistema)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot (parte 7 - Primo avvio del sistema)
keywords: arch, linux, lenovo, ideapad, g50-70, uefi, secure boot, hashtool, enroll, hash, mok, utility, refind, validation
---

{: .center}
![refind.png]

Avviando per la prima volta Arch Linux dal menu di rEFInd sarà mostrato un
avviso riguardo un errore di Secure Boot per il kernel **vmlinux-linux**.

{: .center}
![refind-secure-boot-failed.png]

{: .center}
**Secure Boot validation failure loading vmlinuz-linux!**

Il messaggio di errore fornisce anche la soluzione, utilizzare l'utilità MOK per
registrare il file vmlinuz-linux. Premendo un tasto qualsiasi si tornerà a rEFInd.

{: .center}
![tool_mok_tool.png] **Start MOK utility at EFI\refind\HashTool.efi on SYSTEM_DRV**

Dalla seconda riga utilizzare l'icona per aggiungere un file al database MOK.

{: .center}
![hashtool-2.png]

Sarà mostrato nuovamente il menu di **HashTool**, già visto durante la fase di
[preparazione]({% post_url italian/2015-06-08-installare-arch-linux-su-lenovo-g50-70-1 %}).
Scegliere quindi la voce dal menu **Enroll Hash** e selezionare il file
**vmlinuz-linux** posto sulla radice della partizione. Quando richiesto 
(**Enroll this hash into MOK database?**) rispondere confermando su **Yes** e al
termine uscire dall'utilità scegliendo **Exit**.

Ritornati al menu di rEFInd sarà adesso possibile avviare Arch Linux normalmente.


[refind.png]: /resources/articles/2015-06/refind.png
[refind-secure-boot-failed.png]: /resources/articles/2015-06/refind-secure-boot-failed.png
[tool_mok_tool.png]: /resources/articles/2015-06/refind/tool_mok_tool.png
[hashtool-2.png]: /resources/articles/2015-06/hashtool-2.png
