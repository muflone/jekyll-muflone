---
layout: product_default
order: 3
title: Installazione
---
# Processo di produzione

A differenza di altri software **Remmina Plugin Builder** non è un software da
installare o da eseguire sulla propria macchina ma fornisce un ambiente di
sviluppo per la produzione di plugin per Remmina.

Il suo scopo è quello di semplificare il processo di produzione di plugin per
Remmina, che allo stato attuale, richiederebbero l'intero codice sorgente di
Remmina solo per compilare un plugin.
Utilizzando Remmina Plugin Builder il processo di produzione semplicemente
richiederà il posizionamento del codice sorgente del plugin in una cartella
specifica e la compilazione con pochi comandi.

# Preparazione alla compilazione

Il processo di preparazione semplicemente richiede l'estraazione del codice
sorgente di Remmina Plugin Builder con:
```
cd "~/cartella con il file scaricato"
mkdir build
tar xvzf "nome del file.tar.gz" -C build
cd build/remmina-plugin-builder-*
```

# Compilazione del plugin

Quindi è necessario posizionare il codice sorgente del plugin nella cartella
**remmina-plugin-to-build** e compilare tutto quanto usando:

```
cmake -DCMAKE_INSTALL_PREFIX=/usr .
make
```

Se i comandi precedenti non restituiscono alcun errore si dovrebbe leggere
qualcosa del genere:

```
Scanning dependencies of target NOME-PLUGIN
[100%] Building C object remmina-plugin-to-build/NOME-PLUGIN/..o
Linking C shared library NOME-PLUGIN.so
[100%] Built target NOME-PLUGIN
```

La libreria compilata del plugin si potrà trovare sotto la cartella
**remmina-plugin-to-build/NOME-PLUGIN**.

# Installazione del plugin

Se si desidera installare automaticamente il plugin nel sistema è possibile
utilizzare:

```
sudo make install
```

# Impacchettamento del plugin

Se si desidera impacchettare il plugin invece di installarlo nel sistema si
potrà utilizzare:

```
make DESTDIR=CARTELLA install
```

Dovrebbe essere mostrato qualcosa simile a:

```
[100%] Built target NOME-PLUGIN
Install the project...
-- Install configuration: "Release"
-- Installing: PACKAGE/usr/lib/remmina/plugins/NOME-PLUGIN.so
-- Installing: PACKAGE/usr/share/icons/hicolor/16x16/emblems/NOME-PLUGIN.png
-- Installing: PACKAGE/usr/share/icons/hicolor/22x22/emblems/NOME-PLUGIN.png
```

Al termine del processo si potrà trovare la libreria del plugin all'interno
della cartella specificata. Sarà quindi necessario completare il resto
dell'impacchettamento autonomamente.

# Pulizia

Dopo la fase di installazione/impacchettamento l'intera cartella build potrà
essere eliminata.