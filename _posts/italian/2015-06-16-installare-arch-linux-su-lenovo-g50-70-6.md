---
title: Installare Arch Linux su Lenovo G50-70 (parte 6 - funzionamento di rEFInd)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot (parte 6 - Funzionamento di rEFInd)
keywords: arch, linux, lenovo, ideapad, g50-70, uefi, secure boot, efibootmgr, loader, refind, prebootloader
---

{% include installare-arch-linux-su-lenovo-g50-70-index.inc %}

{: .center}
![refind.png]

Il gestore di avvio rEFInd offre numerose possibilità e con molta semplicità
permette l'avvio di sistemi operativi differenti.

Il suo funzionamento è assai semplice e generalmente basta spostarsi con le
freccette e confermare la scelta premendo Invio. E' anche possibile premere
il tasto corrispondente al numero del sistema da avviare, 1 per la prima icona
visualizzata, 2 per la seconda e così via.

Nella finestra di rEFInd sono visibili varie icone.

## Icone dei sistemi avviabili

La prima fila di icone rappresenta un sistema operativo avviabile.

|**Icona**                  |**Significato**                                  |
|---------------------------|:------------------------------------------------|
|![os_arch.png]             |Indica l'avvio di un sistema Arch Linux          |
|![os_linux.png]            |Indica l'avvio di un generico sistema GNU/Linux  |
|![os_win.png]              |Indica l'avvio di un sistema Microsoft Windows   |
|![os_win8.png]             |Indica l'avvio di un sistema Microsoft Windows 8 |
|![os_unknown.png]          |Indica l'avvio di un sistema operativo generico  |
|![arrow_right.png]         |Scorre l'elenco dei sistemi verso destra         |
|![arrow_left.png]          |Scorre l'elenco dei sistemi verso sinistra       |

L'elenco delle icone dei sistemi operativi non si esaurisce qui ma ne esistono
anche tante altre disponibili nella directory icons di rEFInd.

Premendo **F2** sopra un sistema avviabile saranno mostrate opzioni aggiuntive
riguardo l'avvio, come la modalità single.

Premendo **ESC** in qualsiasi parte viene aggiornato l'elenco dei sistemi rilevati.

## Icone aggiuntive dei sistemi avviabili

Nell'angolo destro di ogni icona di un sistema avviabile è presente un'icona
aggiuntiva che indica dove si trovi il sistema operativo da avviare.

|**Icona**                  |**Significato**                                  |
|---------------------------|:------------------------------------------------|
|![vol_internal.png]        |Indica un sistema avviato da un disco interno    |
|![vol_optical.png]         |Indica un sistema avviato da un'unità ottica     |
|![vol_external.png]        |Indica un sistema avviato da un disco esterno    |
|![vol_net.png]             |Indica un sistema avviato da rete                |

## Icone delle utilità aggiuntive

La fila di icone in basso rappresenta una serie di utilità aggiuntive. Quelle
non supportate o non disponibili non saranno mostrate.

|**Icona**                  |**Significato**                                  |
|---------------------------|:------------------------------------------------|
|![tool_windows_rescue.png] |Avvia la partizione di ripristino di Windows     |
|![tool_mok_tool.png]       |Avvia uno degli strumenti di firma di PreLoader  |
|![tool_memtest.png]        |Avvia l'utilità di controllo della memoria RAM   |
|![tool_shell.png]          |Avvia una shell EFI                              |
|![func_about.png]          |Mostra le informazioni sulla versione di rEFInd  |
|![func_shutdown.png]       |Spegne il computer                               |
|![func_reset.png]          |Riavvia il computer                              |
|![func_exit.png]           |Esce da rEFInd e torna alla Shell EFI            |
|![func_firmware.png]       |Avvia l'utilità di configurazione di UEFI        |


[refind.png]: /resources/articles/2015-06/refind.png
[os_arch.png]: /resources/articles/2015-06/refind/os_arch.png
[os_linux.png]: /resources/articles/2015-06/refind/os_linux.png
[os_win.png]: /resources/articles/2015-06/refind/os_win.png
[os_win8.png]: /resources/articles/2015-06/refind/os_win8.png
[os_unknown.png]: /resources/articles/2015-06/refind/os_unknown.png
[arrow_left.png]: /resources/articles/2015-06/refind/arrow_left.png
[arrow_right.png]: /resources/articles/2015-06/refind/arrow_right.png
[tool_windows_rescue.png]: /resources/articles/2015-06/refind/tool_windows_rescue.png
[tool_mok_tool.png]: /resources/articles/2015-06/refind/tool_mok_tool.png
[tool_memtest.png]: /resources/articles/2015-06/refind/tool_memtest.png
[tool_shell.png]: /resources/articles/2015-06/refind/tool_shell.png
[func_about.png]: /resources/articles/2015-06/refind/func_about.png
[func_shutdown.png]: /resources/articles/2015-06/refind/func_shutdown.png
[func_reset.png]: /resources/articles/2015-06/refind/func_reset.png
[func_exit.png]: /resources/articles/2015-06/refind/func_exit.png
[func_firmware.png]: /resources/articles/2015-06/refind/func_firmware.png
[vol_internal.png]: /resources/articles/2015-06/refind/vol_internal.png
[vol_optical.png]: /resources/articles/2015-06/refind/vol_optical.png
[vol_external.png]: /resources/articles/2015-06/refind/vol_external.png
[vol_net.png]: /resources/articles/2015-06/refind/vol_net.png
