---
layout: default
order: 511
depth: 2
title: awaitable
---

# Funzione awaitable

## Definizione

```python
def awaitable(func: typing.Callable)
```

La funzione decoratore **awaitable** mira a contrassegnare una funzione
sincrona come funzione awaitable da poter essere chiamata da un'altra
funzione asincrona.

#### Argomenti

- **func**: la funzione decorata da racchiudere e trasformare in funzione
            asincrona.

#### Restituisce

- La funzione decorata contrassegnata come awaitable.

#### Esempio di utilizzo

La funzione può essere usata come decoratore con **@awaitable** prima del nome
della funzione da decorare.

```python
import awaitable

@awaitable.awaitable
def do_process(a, b):
    ...
```

Racchiudendo la funzione **do_process** col decoratore **awaitable** si rende
la funzione decorata come awaitable al fine di poter essere eseguita da
un'altra funzione asincrona e può essere sospesa (attesa) permettendo ad altre
parti del codice di essere eseguite in parallelo.
