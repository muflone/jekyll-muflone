---
layout: documentation
order: 503
depth: 2
title: In the operating system
---
# Introduction

After [enabling the Wake on LAN in the BIOS]({% link _gwakeonlan/english/wol/bios.md %})
the operating system must be informed to enable it before the shutdown otherwise
the machine will not turn on even if everything else is done properly.

# GNU/Linux

To check if the network card supports the Wake On LAN then the following command
can be used:
```
# ethtool eth0
Settings for eth0:
        ....
        Supports Wake-on: pumbg
        Wake-on: d
        .....
```

If the **Supports Wake-on** field contains **g** then the Wake On LAN by
magic-packet can be used:
```
# ethtool -s eth0 wol g
# ethtool eth0
Settings for eth0:
        ....
        Wake-on: g
        .....
```

The command must be performed before the machine shutdown.

# Apple OS X
In the Apple OS X systems the Wake On LAN setting can be found in the
**System Preferences** under the section **Energy Saver**.

[![](/resources/gwakeonlan/wol_os/osx-1-thumb.png)](/resources/gwakeonlan/wol_os/osx-1.png)

# Microsoft Windows

On major Microsoft Windows OS the Wake On LAN is enabled by default so generally
nothing to be done is needed.
If the machine still doesn't turn itself on then you should check if the
operating system has the Wake On LAN enabled with the **Magic Packet**.

The following specifications can be different, they depends from the used driver.

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
