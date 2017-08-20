---
layout: default
order: 61
title: Cambiamenti
---
# Versione 0.8.6 (2 Agosto 2015)

* Aggiornamento delle traduzioni

# Versione 0.8.5 (4 Ottobre 2014)

* Aggiornamento delle traduzioni

# Versione 0.8.4 (6 Settembre 2014)

* Aggiornamento delle traduzioni

# Versione 0.8.3 (31 Agosto 2014)

* Aggiornamento delle traduzioni
* Nuova traduzione in arabo da M I
* Nuova traduzione in vietnamita da Anh Phan
* Nuova traduzione in turco da Necdet Yücel

# Versione 0.8.2 (17 Ottobre 2010)

* Rimossi i plugin amsn, emesene, kopete, pidgin, telepathy.
  Sono stati spostati ad un altro repository sorgente per una manutenzione e un
  versionamento separati
* Aggiunto handlepaths a EspeakFrontend.py
* Se la cartella specificata per MBROLA non esiste ripiega sul percorso
  predefinito
* Cambio alle nuove versioni di MBROLA e espeak
* Nuova traduzione in tedesco da Heinrich Schwietering
* Nuova traduzione in faroese daGunleif Joensen
* Sistemata la gestione dei collegamenti interrotti per i plugin amsn ed emesene

# Versione 0.8.1 (26 Giugno 2010)

* Nuova traduzione in bulgaro da Svetoslav Stefanov
* La configurazione utente è stata spostata in XDG_CONFIG_HOME invece del
  precedente percorso codificato (mi spiace per i salvataggi persi)
* Nuova architettura a plugin
* Spostate le impostazioni per dbus, salvataggio delle configurazioni della
  voce, salvataggio delle dimensioni della finestra, messaggio di benvenuto in
  plugin esterni
* Nuova funzionalità a riga di comando
* Interruzione della riproduzione precedente in fase di chiusura (spostato su
  plugin esterno)
* Nuovi plugin: debug, salva posizione della finestra
* Nuova configurazione minimale dei plugin nella finestra delle preferenze
* Nuovi plugin Telepathy, Pidgin, Emesene, Kopete e aMSN

# Versione 0.8 (13 Giugno 2010)

* Spostati i traduttori dai files .po a doc/translators
* Nuova traduzione polacca di Andrey J.
* Nuova interfaccia DBUS per l'interazione da applicazioni esterne
* Corretto il ritardo minimo delle parole da 5 a 0 nell'interfaccia principale

{:.center}
![Finestra delle informazioni di Gespeaker 0.8](/resources/gespeaker/archive/v0.8/italian/about.png)

# Versione 0.7 (13 Dicembre 2009)

* Nuovo modulo handlepaths che riflette il cambiamento della struttura delle
  directory.
* Nuovo setup.py per l'installazione distutils.
* Nuova pacchettizzazione che segue le regole Debian.

{:.center}
![Finestra delle informazioni di Gespeaker 0.7](/resources/gespeaker/archive/v0.7/italian/about.png)

# Versione 0.6 (18 Luglio 2009)

* Corretta la stringa localizzata per la verifica audio.
* Invece di ignorare l'errore, un messaggio di errore viene mostrato se il
  riproduttore audio non viene trovato.
* Nuova traduzione spagnola fornita da David Prieto.
* Nuovo supporto a MBROLA per voci più realistiche.
* Aggiunge le voci MBROLA all'elenco delle lingue.
* Finestra di dialogo delle preferenze a schede col nuovo supporto a MBROLA.
* Spostati lingua, tipo di voce e varianti alle impostazioni di base e
  intonazione, volume, velocità e ritardo alle impostazioni avanzate
  dietro suggerimento frandavid100.
* Aggiunta automaticamente estensione txt nel salvataggio del file di testo.
* Aggiunta automaticamente estensione wav nel salvataggio del file WAVE.
  Ciò causava strani rumori nella riproduzione della traccia registrata se il
  nome del file non terminava in .wav.

{:.center}
![Finestra principale di Gespeaker 0.6](/resources/gespeaker/archive/v0.6/italian/main.jpg)

{:.center}
![Finestra delle preferenze per MBROLA di Gespeaker 0.6](/resources/gespeaker/archive/v0.6/italian/mbrola.jpg)

# Versione 0.5 (30 Giugno 2009)

* Aggiunto un separatore espansore per le impostazioni in modo da massimizzare
  l'utilizzo della finestra col testo.
* Aggiunti i filtri per le finestre di dialogo carica/salva testo.
* Aggiunto il supporto per il salvataggio in wave della traccia audio.
* Aggiunta una barra di stato per mostrare la modalità di registrazione attiva.
* Aggiunta la finestra delle preferenze.
* Aggiunte le preferenze per salvare e ricaricare il messaggio di benvenuto,
  le dimensioni della finestra, le impostazioni della voce e lo stato
  dell'espansore.
* Aggiunto il supporto per il frontend audio: ```ALSA``` (aplay),
  ```PulseAudio``` (paplay) e comando di riproduzione personalizzato
  dall'utente, con comando di verifica dell'audio.
* Aggiunte le varianti delle voci verificando la directory 
  ```/usr/share/espeak-data/voices/!v``` per varianti extra della voce.
* Sistemate le icone predefinite per ```DialogFileOpenSave```.

{:.center}
![Finestra principale di Gespeaker 0.5](/resources/gespeaker/archive/v0.5/italian/main.png)

{:.center}
![Finestra delle preferenze di Gespeaker 0.5](/resources/gespeaker/archive/v0.5/italian/preferences.png)

# Versione 0.4 (20 Giugno 2009)

* Aggiunto ```SubprocessWrapper.Popen``` per racchiudere subprocess.Popen in
  modo da supportare versioni di Python antecedenti alla 2.6 che non offrono
  l'argomento delete alla creazione dell'oggetto.
* Aggiunto ```TempfileWrapper.NamedTemporaryFile``` per racchiudere l'oggetto
  Popen di tempfile in modo da supportare versioni di Python antecedenti alla
  2.6 che non offrono i metodi terminate e send_signal.
  Attualmente non viene più usato, rimasto per utilizzi futuri.
* Adesso Gespeaker funziona con Python versioni 2.4 e successive.
* Il file temporaneo per il testo da riprodurre viene creato all'avvio del
  programma così non verranno più creati files temporanei dopo ogni riproduzione.
* Incluse le funzionalità pausa e riprendi.
* Nuove icona e logo, gentilmente forniti da MIX.
* Nuova traduzione francese fornita da Emmanuel.

{:.center}
![Finestra principale di Gespeaker 0.4](/resources/gespeaker/archive/v0.4/italian/main.png)

# Versione 0.3 (18 Giugno 2009)

* Usata soltanto per verifiche, mai rilasciata.
* Aggiunto il supporto per il tipo di voce (maschile/femminile) con +12 per la
  voce femminile.
* Rimossa la sostituzione del testo con un file temporaneo più sicuro con il
  testo da riprodurre.
* Sostituita la chiamata rediretta tramite shell con la più sicura redirezione
  attraverso subprocess.
* Miglior controllo delle chiamate esterne, adesso sia l'esecuzione di espeak e
  del riproduttore vengono controllati in caso di uscita e terminati se richiesto.
* Aggiunti parametri documentazione e artisti a ```DialogAbout```.

# Versione 0.2 (14 Giugno 2009)

* Cambiata l'interfaccia utente secondo le
  [specifiche HIG di GNOME 2.32][GNOME HIG specifications]
* Corretto l'utilizzo dell'icona su ```DialogAbout.set_icon_from_file```, che
  era stata erroneamente scritta nel codice.
* Aggiunto collegamento simbolico del file di copyright a 
  ```/usr/share/doc/gespeaker/copyright```

{:.center}
![Finestra principale di Gespeaker 0.2](/resources/gespeaker/archive/v0.2/italian/main.png)

# Versione 0.1 (13 Giugno 2009)

* Rilascio iniziale.

{:.center}
![Finestra principale di Gespeaker 0.1](/resources/gespeaker/archive/v0.1/italian/main.jpg)

{:target="_blank"}
[GNOME HIG specifications]: https://developer.gnome.org/hig-book/2.32/design-window.html.en