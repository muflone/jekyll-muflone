---
layout: default
order: 503
depth: 2
title: Nel sistema operativo
---
# Introduzione

Dopo aver [attivato il Wake on LAN nel BIOS]({% link _gwakeonlan/italian/wol/bios.md %})
il sistema operativo deve essere informato di abilitarlo prima dello spegnimento
altrimenti la macchina non si riaccenderà anche se tutto il resto è stato fatto
nella maniera corretta.

# GNU/Linux

Per controllare se la scheda di rete supporta il Wake On LAN il seguente comando
può essere utilizzato:
```
# ethtool eth0
Settings for eth0:
        ....
        Supports Wake-on: pumbg
        Wake-on: d
        .....
```

Se il campo **Supports Wake-on** contiene **g** allora il Wake On LAN con
Magic Packet può essere utilizzato:
```
# ethtool -s eth0 wol g
# ethtool eth0
Settings for eth0:
        ....
        Wake-on: g
        .....
```

Il comando deve essere eseguito prima dello spegnimento della macchina.

# Apple OS X

Nei sistemi Apple OS X l'impostazione del Wake On LAN si trova nelle
**Preferenze di sistema** e quindi nella sezione **Risparmio energia**.

[![](/resources/gwakeonlan/wol_os/osx-1-thumb.png)](/resources/gwakeonlan/wol_os/osx-1.png)

# Microsoft Windows

Nei principali sistemi operativi Microsoft Windows il Wake On LAN è abilitato in
maniera predefinita quindi in linea generale non è necessario eseguire nessuna
operazione.
Se la macchina ancora non si accende allora può essere necessario verificare se
il sistema operativo ha il Wake On LAN attivato col **Magic Packet**.

Le specifiche seguenti potrebbero essere differenti in quanto dipendenti dal
driver in uso.

## Microsoft Windows XP

[![](/resources/gwakeonlan/wol_os/windows_xp-1-thumb.jpg)](/resources/gwakeonlan/wol_os/windows_xp-1.jpg)
[![](/resources/gwakeonlan/wol_os/windows_xp-2-thumb.jpg)](/resources/gwakeonlan/wol_os/windows_xp-2.jpg)

## Microsoft Windows 2000/2003 Server

[![](/resources/gwakeonlan/wol_os/windows_2000-1-thumb.jpg)](/resources/gwakeonlan/wol_os/windows_2000-1.jpg)

## Microsoft Windows Vista/7/8/2008/2012 Server

[![](/resources/gwakeonlan/wol_os/windows_vista-1-thumb.png)](/resources/gwakeonlan/wol_os/windows_vista-1.png)
[![](/resources/gwakeonlan/wol_os/windows_vista-2-thumb.png)](/resources/gwakeonlan/wol_os/windows_vista-2.png)

[![](/resources/gwakeonlan/wol_os/windows_vista-3-thumb.png)](/resources/gwakeonlan/wol_os/windows_vista-3.png)
[![](/resources/gwakeonlan/wol_os/windows_vista-4-thumb.png)](/resources/gwakeonlan/wol_os/windows_vista-4.png)

[![](/resources/gwakeonlan/wol_os/windows_vista-5-thumb.png)](/resources/gwakeonlan/wol_os/windows_vista-5.png)
[![](/resources/gwakeonlan/wol_os/windows_vista-6-thumb.jpg)](/resources/gwakeonlan/wol_os/windows_vista-6.jpg)

[![](/resources/gwakeonlan/wol_os/windows_vista-7-thumb.png)](/resources/gwakeonlan/wol_os/windows_vista-7.png)
