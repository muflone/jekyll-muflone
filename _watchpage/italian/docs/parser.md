---
layout: documentation
order: 532
depth: 2
title: Parser
---
# Parser

I parser ammessi dall'opzione `PARSER` sono i seguenti:

| Nome        | Descrizione                                                          |
|:------------|:---------------------------------------------------------------------|
| html.parser | Il parser predefinito di Python, velocità e compatibilità intermedia |
| html5lib    | Il parser della libreria html5lib, il più compatibile ma più lento   |
| lxml        | Il parser HTML della libreria lxml, il più veloce                    |
| xml         | Il parser XML della libreria lxml, il più veloce                     |

In generale per controllare pagine HTML è raccomandato l'uso di lxml che
risulta essere il più veloce. Se si riscontrassero problemi di compatibilità
è possibile ripiegare su html5lib o html.parser.

Per controllare pagine XML è raccomandato l'uso di xml.
