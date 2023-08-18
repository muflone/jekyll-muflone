---
layout: documentation
order: 534
depth: 2
title: Filters
---
# Filters

È possibile applicare uno o più filtri per estrarre e trasformare i risultati
desiderati.

I tipi di filtri ammessi dall'opzione `FILTERS` sono i seguenti:

| Nome          | Descrizione                                                                                                   |
|:--------------|:--------------------------------------------------------------------------------------------------------------|
| STARTS        | L'elemento deve iniziare con la stringa specificata                                                           |
| NOT STARTS    | L'elemento non deve iniziare con la stringa specificata                                                       |
| ENDS          | L'elemento deve terminare con la stringa specificata                                                          |
| NOT ENDS      | L'elemento non deve terminare con la stringa specificata                                                      |
| CONTAINS      | L'elemento deve contenere la stringa specificata                                                              |
| NOT CONTAINS  | L'elemento non deve contenere la stringa specificata                                                          |
| REGEX         | L'elemento deve corrispondere alla stringa corrispondente all'espressione regolare specificata                |
| NOT REGEX     | L'elemento non deve corrispondere alla stringa corrispondente all'espressione regolare specificata            |
| TRIM          | Rimuove gli spazi o i caratteri specificati da sinistra e da destra                                           |
| LTRIM         | Rimuove gli spazi o i caratteri specificati da sinistra                                                       |
| RTRIM         | Rimuove gli spazi o i caratteri specificati da destra                                                         |
| PREPEND       | Inserisce all'inizio dell'elemento il testo specificato                                                       |
| APPEND        | Inserisce alla fine dell'elemento il testo specificato                                                        |
| REMOVE        | Rimuove dall'elemento il testo specificato                                                                    |
| REMOVE LEFT   | Rimuove dall'elemento la stringa corrispondente dall'inizio del testo                                         |
| REMOVE RIGHT  | Rimuove dall'elemento la stringa corrispondente dalla fine del testo                                          |
| REPLACE       | Sostituisce dall'elemento il testo specificato col nuovo pattern (indicato con WITH:)                         |
| REVERSE       | Inverte il testo dell'elemento                                                                                |
| UPPER         | Rende l'elemento tutto in maiuscolo                                                                           |
| LOWER         | Rende l'elemento tutto in minuscolo                                                                           |
| LEFT          | Restituisce i primi caratteri, da sinistra                                                                    |
| RIGHT         | Restituisce gli ultimi caratteri, da destra                                                                   |
| REGEX REPLACE | Sostituisce dall'elemento un pattern usando un'espressione regolare con un nuovo pattern (indicato con WITH:) |
| REGEX SEARCH  | Restituisce la prima corrispondenza dell'espressione regolare                                                 |
| JSON DICT     | Restituisce il valore da un dizionario JSON con la chiave specificata                                         |
| JSON LIST     | Restituisce il valore da una lista JSON con l'indice specificato                                              |

>>>>>> Vedi la [pagina Filters]({% link _watchpage/italian/examples/filters.md %})
>>>>>> nella sezione [Esempi di utilizzo]({% link _watchpage/italian/examples/index.md %}).
