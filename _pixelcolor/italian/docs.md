---
layout: documentation
order: 500
title: Documentazione
---

# Opzioni da riga di comando

**PixelColor** è un'utilità a riga di comando e richiede alcuni argomenti e
opzioni. Argomenti e opzioni tra parentesi quadre sono opzionali.

Per alcuni esempi di utilizzo vedi la pagina
[Esempi di utilizzo]({% link _pixelcolor/italian/examples.md %}).

## Usage

```shell
pixelcolor [-h] [-V] [--display DISPLAY] [--triplets] [--hex] [--upper] --x X --y Y

options:
  -h, --help         mostra questo messaggio di aiuto
  -V, --version      mostra il numero di versione del programma

Screen:
  --display DISPLAY  display dal quale catturare il pixel
  --x X, -x X        coordinata X del pixel da ottenere
  --y Y, -y Y        coordinata Y del pixel da ottenere

Output:
  --triplets, -T     restituisce il colore in triplette
  --hex, -H          restituisce il colore in formato esadecimale
  --upper, -U        restituisce il risultato in maiuscolo
```
