---
layout: default
order: 512
depth: 2
title: run_awaitable
---

# Funzione run_awaitable

## Definizione

```python
def run_awaitable(func: typing.Callable, *args, **kwargs) -> None
```

La funzione **run_awaitable** consente di eseguire una funzione asincrona da
un'altra funzione sincrona.

#### Argomenti

- **func**: la funzione asincrona da eseguire.
- **\*args**: una lista di argomenti posizionali da passare alla funzione.
- **\*\*kwargs**: un dizionario di argomenti per nome da passare alla funzione.

#### Restituisce

- La funzione non restituisce nulla.

#### Esempio di utilizzo

La funzione può essere usata per avviare l'esecuzione di codice asincrono
dall'interno di un'altra funzione sincrona.

```python
import awaitable

async def process(count: int) -> None:
    pass

awaitable.run_awaitable(func=process, count=10)
```

Verrà eseguita la funzione asincrona chiamata **process** passando l'argomento
*count=10* (attraverso l'argomento **\*\*kwargs** di **run_awaitable**).
