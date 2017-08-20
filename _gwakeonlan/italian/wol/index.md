---
layout: default
order: 6
depth: 1
title: Wake On LAN
---
# Wake On LAN

gWakeOnLAN utilizza il sistema [Wake On LAN] per accendere una macchina sia
nella rete locale sia attraverso Internet.

Il tipo di Wake On LAN usato da gWakeOnLAN è chiamato [Magic Packet]
ed è ottenuto inviando alla macchina di destinazione uno speciale pacchetto
[Pacchetto UDP][UDP] contenente alcuni dati.
La macchina a riposo deve essere configurata per ricevere i pacchetti anche
nello stato spento in modo che quando lo speciale Magic Packet è ricevuto la
macchina si accenderà automaticamente.

Per permettere il corretto funzionamento di gWakeOnLAN tutti i
[requisiti]({% link _gwakeonlan/italian/wol/requirements.md %})
di sistema devono essere soddisfatti.

# Utilizzo locale

{:.center}
![Utilizzo locale](/resources/gwakeonlan/usage/italian/local.png)
          
Quando il tipo di richiesta inviata gWakeOnLAN è **Locale (broadcast)** il
Magic Packet viene inviato all'intera rete locale con una richiesta broadcast
fatta all'indirizzo IP speciale **255.255.255.255**.
In un ambiente di rete normale dove i pacchetti broadcast non sono in alcun modo
bloccati, tutte le macchine nella rete locale riceveranno il pacchetto.

# Utilizzo Internet

{:.center}
![Utilizzo Internet](/resources/gwakeonlan/usage/italian/internet.png)
          
Quando il tipo di richiesta è **Internet** è richiesto un sistema di
destinazione e il Magic Packet sarà inviato a quel sistema che dovrà provvedere
ad inviarlo al sistema spento corretto.

Il sistema di destinazione non è inteso come la macchina da accendere ma un
punto di rete raggiungibile che sia in grado di ricevere il pacchetto UDP e
inoltrarlo alla macchina da accendere utilizzando il Wake On LAN.

{: target="_blank" .external }
[Wake On LAN]: https://en.wikipedia.org/wiki/Wake_on_LAN

{: target="_blank" .external }
[Magic Packet]: https://en.wikipedia.org/wiki/Wake-on-LAN#Magic_packet

{: target="_blank" .external }
[UDP]: https://en.wikipedia.org/wiki/User_Datagram_Protocol