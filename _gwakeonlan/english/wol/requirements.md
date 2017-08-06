---
layout: product_default
order: 7
depth: 2
title: Requirements
---
# Requirements

To allow gWakeOnLAN to turn on a machine **all these requirements** must be met.

Each machine to turn on must:

* have an integrated (or PCI/PCIE) Ethernet network card.
* have the network cable plugged all the time.
* have the power cable plugged all the time.
* support the Wake On LAN with the [Magic Packet]{:target="_blank"}.
* have the Wake On LAN
  [enabled in the BIOS]({% link _gwakeonlan/english/wol/bios.md %}).
* have the Wake On LAN by Magic Packet
  [enabled in the Operating System]({% link _gwakeonlan/italian/wol/os.md %}).
* be powered off from the Operating System.

If one or more of these requirements is not met **all the time**, the
Wake On LAN will not work.

It will fail if a requirement is not met for some time,
**even after the machine was turned off**, 
like to unplug the power cord from the machine and connecting it later.

# Additional requirements for Internet
In the case the command is sent through the Internet (not local broadcast)
additional requirements must be met:

* The machine to turn on must be reachable from the network
* The UDP data sent from  gWakeOnLAN must reach the destination machine
* The router must remember the turned off machines

## The machine to turn on must be reachable from the network

The machine must not be connected with a modem directly connected to the machine,
otherwise the data cannot be received if the network is disconnected.

A connected and **reachable router** is then recommended to be able to receive
the data sent from gWakeOnLAN.

## The UDP data sent from  gWakeOnLAN must reach the destination machine

The router must forward the UDP data from the specified port number to the
destination IP address in its local network.

This is generally done in the router configuration setting up a
**Virtual Server, Port forwarding or Port mapping**. 

Plese refer to your router documentation to know how to setup your router.

## The router must remember the turned off machines

Many consumer routers forget the MAC addresses on their local  network after
2-5 minutes of inactivity, so even if a machine was properly shutdown with all
the above requirements the receiving router may not to be able to remember on
what MAC address to forward the data.

The success key to accomplish this is called
[static ARP cache][ARP Cache]{:target="_blank"}
which statically assigns a MAC address to the IP address to forward.

Plese refer to your router documentation to know how to setup your router.

If this requirement cannot be met because if your router doesn't support a
static ARP cache as an alternative you can setup an always-on computer to act
as a gateway and configure the ARP cache in its operating system.

[Magic Packet]: https://en.wikipedia.org/wiki/Wake-on-LAN#Magic_packet
[ARP Cache]: https://en.wikipedia.org/wiki/Address_Resolution_Protocol