---
title: Installare Arch Linux su Lenovo G50-70 (parte 13 - scorrimento della console)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot (parte 13 - Abilitare lo scorrimento del testo nella console)
keywords: arch, linux, lenovo, ideapad, g50-70, scroll, backward, forward, text, buffer, scrollback, pageup, pagedown, keycode, loadkeys
---

{% include installare-arch-linux-su-lenovo-g50-70-index.inc %}

Questo notebook è dotato di tastierino numerico ma manca dei tasti diretti per
<kbd>Pagina Su</kbd> e <kbd>Pagina Giù</kbd>.

Sebbene questi due tasti esistano integrati nel tastierino numerico, quando il
tastierino numerico è spento dal pulsante **Num Lock**, all'interno della console
locale di GNU/Linux, il normale scorrimento del testo (il cosiddetto 
[Scrollback buffer]{:target="_blank"}) con <kbd>Maiusc</kbd>+<kbd>Pagina Su</kbd> e
<kbd>Maiusc</kbd>+<kbd>Pagina Giù</kbd> non funziona utilizzando il tastierino
numerico, né acceso né spento.

Se si è seguito il passaggio di
[configurazione della tastiera italiana]({% post_url italian/2015-06-15-installare-arch-linux-su-lenovo-g50-70-4 %}#configurazione-della-tastiera-italiana)
e si è configurata la tastiera italiana utilizzando il file vconsole.conf,
basterà decomprimere il file della mappatura italiana, copiare il file da
un'altra parte, aggiungere i due tasti per lo scorrimento del testo nella console
e far puntare il file vconsole.conf al nuovo file.

## Configurazione della nuova mappatura della tastiera

Il primo passaggio consiste nell'estrarre il contenuto dal file della mappatura
utilizzata, nel caso della lingua italiana è possibile eseguire:

    [root@arch-lenovo ~]# gunzip -k -c /usr/share/kbd/keymaps/i386/qwerty/it.map.gz > /etc/keymap

Il file **/etc/keymap** conterrà una copia decompressa della mappatura della
tastiera italiana standard. A questa mappatura andrà aggiunta la mappatura dei
tasti <kbd>Maiusc</kbd>+<kbd>Pagina Su</kbd> e <kbd>Maiusc</kbd>+<kbd>Pagina Giù</kbd>.

Per conoscere i codici dei tasti <kbd>Pagina Su</kbd> e <kbd>Pagina Giù</kbd>
basterà eseguire dalla console il comando **showkey**.

    [root@arch-lenovo ~]# showkey
    kb mode was UNICODE
    [ if you are trying this under X, it might not work
    since the X server is also reading /dev/console ]
    
    press any key (program terminates 10s after last keypress)...
 
Mentre il programma showkey è in esecuzione premere e rilasciare il tasto 9 del
tastierino numerico (corrispondente a <kbd>Pagina Su</kbd>) e verranno stampati i
valori di questo tasto.

    keycode  73 press
    keycode  73 release

Facendo la stessa operazione utilizzando il tasto 3 del tastierino numerico
(corrispondente a <kbd>Pagina Giù</kbd>) verranno stampati del tasto.

    keycode  81 press
    keycode  81 release

Dopo 10 secondi dall'ultima battuta il programma showkey terminerà automaticamente.

Questa operazione mostrerà che i codici (keycode) per i tasti 9 e 3 del tastierino
numerico corrispondono a 73 e 81.

Basterà pertanto aggiunge al file della mappatura della tastiera /etc/keymap
creato in precedenza due nuovi valori per lo scorrimento all'indietro e in
avanti del testo della console.

Per assegnare alla combinazione di tasti la funzione di scorrimento basterà
utilizzare:

    [root@arch-lenovo ~]# echo "shift keycode 73 = Scroll_Backward" >> /etc/keymap
    [root@arch-lenovo ~]# echo "shift keycode 81 = Scroll_Forward" >> /etc/keymap

## Utilizzo della nuova mappatura di tastiera

Per provare subito la nuova mappatura di tastiera è possibile eseguire il comando:

    [root@arch-lenovo ~]# loadkeys /etc/keymap

Mentre per rendere definitiva questa mappatura di tastiera basterà semplicemente
modificare il file /etc/vconsole per puntare al nuovo file:

    [root@arch-lenovo ~]# echo "KEYMAP=/etc/keymap" > /etc/vconsole.conf 

Fatto ciò sarà possibile scorrere il testo della console utilizzando la
combinazione di tasti <kbd>Maiusc</kbd>+<kbd>Pagina Su</kbd> e
<kbd>Maiusc</kbd>+<kbd>Pagina Giù</kbd>.

## Configurare la dimensione del buffer di testo scorrevole

Per impostazione predefinita il buffer di testo scorrevole è di 32 KiB e permette
lo scorrimento di circa 4 pagine di testo. Per estendere a 1 MiB la dimensione del
buffer di scorrimento è necessario aggiungere al file dei parametri da passare
al kernel, ovvero al file /boot/refind_linux.conf il parametro **fbcon=scrollback:1024k**.

Per modificare il file con i parametri di avvio del kernel è possibile utilizzare:

    [root@arch-lenovo ~]# nano /boot/refind_linux.conf

Ad esempio il file conterrà

    "Boot with standard options"  "ro root=UUID=xxx   initrd=/intel-ucode.img initrd=/initramfs-linux.img fbcon=scrollback:1024k"
    "Boot to single-user mode"    "ro root=UUID=xxx   single"
    "Boot with minimal options"   "ro root=UUID=xxx"

Salvare il file premendo <kbd>Control</kbd>+<kbd>O</kbd>, confermare con invio
e <kbd>Control</kbd>+<kbd>X</kbd> per uscire dall'editor di testo. Al termine
riavviare il sistema per ampliare da subito la dimensione del buffer di scorrimento.

Sarà possibile ad esempio eseguire il comando **dmesg** e scorrere l'intero
testo utilizzando i tasti <kbd>Maiusc</kbd>+<kbd>Pagina Su</kbd> e
<kbd>Maiusc</kbd>+<kbd>Pagina Giù</kbd>.

  
[Scrollback buffer]: https://wiki.archlinux.org/index.php/Scrollback_buffer