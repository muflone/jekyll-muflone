---
title: Installare Arch Linux su Lenovo G50-70 (parte 1 - preparazione)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot (parte 1 - Preparazione del sistema)
keywords: arch, linux, lenovo, ideapad, g50-70, uefi, secure boot, hybrid, boot, hashtool
---

{% include installare-arch-linux-su-lenovo-g50-70-index.inc %}

# Disattivazione di Avvio rapido / Hybrid Boot

Prima di procedere all'installazione di Arch Linux è importante che si disabiliti
la funzione di avvio rapido (Hybrid Boot) di Windows 8.1 altrimenti i dati del
sistema Windows potrebbero venire corrotti.

{: .center}
![comportamento-pulsante-spegnimento.png]

Accedendo al Pannello di controllo di Windows e ricercando **comportamento
pulsanti** è possibile raggiungere la schermata di configurazione delle
impostazioni di spegnimento del sistema.

{: .center}
![disattivazione-avvio-rapido.png]

Basterà togliere la spunta in fondo su **Attiva avvio rapido (scelta consigliata)**.
Se l'impostazione dovesse risultare bloccata cliccare il collemento in alto
**Modifica le impostazioni attualmente non disponibili**.

-----

# Preparazione di Arch Linux su USB

Per installare Arch Linux è necessario utilizzare un pendrive USB da almeno 1 GiB
opportunamento preparato. **Attenzione** poiché tutti i dati nel dispositivo USB
verranno irrimediabilmente cancellati.

Scaricare innanzitutto l'immagine ISO di installazione di Arch Linux dal sito
<https://www.archlinux.org/download/>{:target="_blank"} (ad oggi si tratta del
file archlinux-2015.06.01-dual.iso).
Scaricare anche lo strumento Rufus dal sito <https://rufus.akeo.ie/>{:target="_blank"}.
Va bene anche la versione portable (ad oggi si tratta di rufus-2.2p.exe), che
funziona su Windows anche senza installazione.

{: .center}
![rufus.png]

Inserire un dispositivo USB da almeno 1 GiB, avviare quindi Rufus, cliccare
l'icona del lettore CD, scegliere il file ISO di Arch Linux scaricato in
precedenza e avviare la scrittura del file ISO nel pendrive cliccando su **Avvia**.

{: .center}
![rufus-conferma.png]

Confermare la totale cancellazione di tutti i dati nel dispositivo USB e
attendere il completamento della scrittura.

-----

# Avviare il sistema tramite USB

{: .center}
![lenovo-laptop-g50-70-sx.png]

Spegnere (non riavviare) il sistema e una volta spento premere il pulsante
**OneKey** posto sul lato sinistro del computer.

{: .center}
![novo-button-menu.png]

Dal menu che sarà mostrato scegliere la voce **Boot Menu**, confermare con invio,
nella schermata del Boot Manager scegliere l'avvio da **EFI USB Device (Generic
USB Storage)** o una voce similare che parli di USB e confermare con invio.

-----

# Firmare i kernel con HashTool

Poiché in questa configurazione è attivo il [Secure Boot]{:target="_blank"} è
necessario firmare tutti i sistemi operativi che si desidera eseguire,

{: .center}
![hashtool-1.png]

Verrà immediatamente presentato un messaggio di errore riguardo il file
**loader.efi** che non risulta firmato. Confermare con OK per accedere a
**HashTool**, lo strumento che consente di firmare i sistemi operativi da avviare.

La procedura è semplice e richiede la firma dei file **loader.efi** (il programma
di avvio da USB di Arch Linux) e **vmlinuz** (il kernel Linux avviato da USB
per l'installazione di Arch Linux).

Questa procedura di firma è detta **Enrolling** e tramite HashTool consente di
calcolare un valore detto Hash ed aggiungerlo al database delle chiavi macchina
(MOK = Machine Owner Keys) autorizzate.

{: .center}
![hashtool-2.png]

Selezionando **Enroll Hash** si procede a firmare i due file necessari.

{: .center}
![hashtool-3.png]

Scegliere inizialmente il file **loader.efi** nella directory \EFI.

{: .center}
![hashtool-4.png]

Confermare con Yes la firma del file selezionato.

{: .center}
![hashtool-5.png]

Firmare successivamente il file **vmlinuz** nella directory \arch\boot\x86_64

{: .center}
![hashtool-6.png]

Confermare la firma di questo secondo file e al termine uscire da HashTool
scegliendo l'opzione **Exit**.

{: .center}
![arch-linux-efi-menu.png]

Dopo alcuni secondi sarà mostrato il menu di avvio dell'immagine di installazione
di Arch Linux, scegliere la prima voce **Arch Linux archiso x86_64 UEFI USB** e
avviare con invio.

Se venissero mostrati errori riguardo software non firmati, assicurarsi di
aver firmato entrambi i file loader.efi e vmlinuz.

Effettuata questa operazione sarà avviata la procedura di installazione di
Arch Linux, consultare la guida [Beginner's guide]{:target="_blank"} per
ulteriori informazioni sul processo di installazione.

Sin dal primo avvio dell'installazione di Arch Linux sarà automaticamente
utilizzata la tastiera in lingua americana (<kbd>Maiusc</kbd>+<kbd>2</kbd>
rappresenterà la @ anziché le virgolette "). Se si desidera impostare sin da
subito la tastiera italiana eseguire il comando **loadkeys it** .

    root@archiso ~ # loadkeys it


[lenovo-ideapad-g50-70.jpg]: /resources/articles/2015-06/lenovo-ideapad-g50-70.jpg
[lenovo-ideapad-g50-70-thumb.png]: /resources/articles/2015-06/lenovo-ideapad-g50-70-thumb.png
[comportamento-pulsante-spegnimento.png]: /resources/articles/2015-06/comportamento-pulsante-spegnimento.png
[disattivazione-avvio-rapido.png]: /resources/articles/2015-06/disattivazione-avvio-rapido.png
[rufus.png]: /resources/articles/2015-06/rufus.png
[rufus-conferma.png]: /resources/articles/2015-06/rufus-conferma.png
[lenovo-laptop-g50-70-sx.png]: /resources/articles/2015-06/lenovo-laptop-g50-70-sx.png
[novo-button-menu.png]: /resources/articles/2015-06/novo-button-menu.png
[hashtool-1.png]: /resources/articles/2015-06/hashtool-1.png
[hashtool-2.png]: /resources/articles/2015-06/hashtool-2.png
[hashtool-3.png]: /resources/articles/2015-06/hashtool-3.png
[hashtool-4.png]: /resources/articles/2015-06/hashtool-4.png
[hashtool-5.png]: /resources/articles/2015-06/hashtool-5.png
[hashtool-6.png]: /resources/articles/2015-06/hashtool-6.png
[arch-linux-efi-menu.png]: /resources/articles/2015-06/arch-linux-efi-menu.png

[UEFI]: https://en.wikipedia.org/wiki/Unified_Extensible_Firmware_Interface
[Secure Boot]: https://msdn.microsoft.com/it-it/library/hh824987.aspx
[Beginner's guide]: https://wiki.archlinux.org/index.php/Beginners%27_guide
