---
layout: documentation
order: 502
depth: 2
title: Requisiti
---
# Requisiti

Per permettere a gWakeOnLAN di accendere una macchina
**tutti i seguenti requisiti** devono essere soddisfatti.

Ogni macchina da accendere deve:

* avere una scheda di rete Ethernet integrata (oppure PCI/PCIE).
* avere il cavo di rete sempre connesso.
* avere il cavo di alimentazione sempre connesso.
* supportare il Wake On LAN con [Magic Packet].
* avere il Wake On LAN 
  [abilitato nel BIOS]({% link _gwakeonlan/italian/docs/bios.md %}).
* avere il Wake On LAN con Magic Packet 
  [abilitato nel sistema operativo]({% link _gwakeonlan/italian/docs/os.md %}).
* essere spenta dal Sistema operativo.

Se uno o più di questi requisiti non è soddisfatto **per tutto il tempo**,
il Wake On LAN non funzionerà.

Non funzionerà se un requisito non è soddisfatto per un certo tempo,
**anche dopo che la macchina è stata spenta**, come ad esempio scollegare il
cavo di alimentazione dalla macchina e ricollegarlo successivamente.

# Requisiti aggiuntivi per Internet

Nel caso che il comando sia inviato attraverso Internet (e non in broadcast
locale) esistono dei requisiti aggiuntivi da soddisfare:

* La macchina da accendere deve essere raggiungibile dalla rete
* I dati UDP inviati da gWakeOnLAN devono raggiungere la macchina di destinazione
* Il router deve ricordare le macchine spente

## La macchina da accendere deve essere raggiungibile dalla rete

La macchina non deve essere collegata con un modem direttamente connesso alla
macchina, altrimenti i dati non saranno ricevuti se la rete è scollegata.

Un **router raggiungibile** e connesso è quindi raccomandato per poter
ricevere i dati inviati da  gWakeOnLAN.

## I dati UDP inviati da gWakeOnLAN devono raggiungere la macchina di destinazione

Il router deve supportare l'inoltro dei dati UDP dal numero di porta specificato
all'indirizzo IP di destinazione nella sua rete locale.

Generalmente questo viene fatti nella configurazione del router impostando un
**Server Virtuale, Port forward oppure Port mapping**.

Consulta la documentazione del router per sapere come configurarlo.

## Il router deve ricordare le macchine spente

Molti router di casa dimenticano gli indirizzi MAC nella loro rete locale dopo
2-5 minuti di inattività, quindi anche se una macchina è stata correttamente
spenta con tutti i precedenti requisiti il router ricevente potrebbe non
ricordare a quale indirizzo MAC inoltrare i dati.

La chiave di successo per ottenere questo è chiamata
[cache ARP statica][ARP Cache]
che staticamente assegna un indirizzo MAC all'indirizzo IP da inoltrare.

Consulta la documentazione del router per sapere come configurarlo.

Se questo requisito non può essere soddisfatto perchè il router non supporta
una cache ARP statica in alternativa è possibile configurare un computer sempre
acceso che agisca come gateway e configurare la cache ARP nel suo sistema
operativo.

{: target="_blank" .external }
[Magic Packet]: https://en.wikipedia.org/wiki/Wake-on-LAN#Magic_packet

{: target="_blank" .external }
[ARP Cache]: https://en.wikipedia.org/wiki/Address_Resolution_Protocol
