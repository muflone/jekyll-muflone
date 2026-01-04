---
layout: documentation
order: 551
depth: 2
title: AsyncioGather
nav_prefix: Classi
---

# Classe AsyncioGather
{: .no_toc }

La classe **AsyncioGather** è utilizzata per raccogliere i task da eseguire
parallelamente e al termine elaborarli tutti insieme in maniera asincrona.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo]({% link _awaitable/italian/examples/index.md %}).

- TOC
{: toc }

---
## Metodo add

```python
def add(self, coroutine: typing.Coroutine) -> int
```

Il metodo **add** aggiunge una funzione asincrona (coroutine) all'elenco
dei task da eseguire.

Il metodo viene usato per aggiungere una funzione asincrona all'elenco dei task
affinché al termine della raccolta dei task essi possano essere elaborati tutti
parallelamente.

#### Parametri

- **coroutine**: la funzione asincrona da eseguire.

#### Restituisce

- Il numero di task in coda.

#### Esempio di utilizzo

```python
import awaitable

tasks = awaitable.AsyncioGather()
tasks.add(do_process(...))
```

---

## Metodo count

```python
def count(self) -> int
```

Il metodo **count** restituisce il numero di task in coda.

#### Restituisce

- Il numero di task in coda.

#### Esempio di utilizzo

```python
import awaitable

tasks = awaitable.AsyncioGather()
tasks.add(do_process(...))
print(tasks.count())
```

---

## Metodo run

```python
async def run(self) -> None
```

Il metodo **run** esegue tutti i task in coda in maniera parallela.

Trattandosi di un metodo asincrono deve essere chiamato da una funzione
asincrona oppure attraverso **run_awaitable**.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
import awaitable

async def process():
    tasks = awaitable.AsyncioGather()
    for _ in range(5):
        tasks.add(do_process(...))
    await tasks.run()
```
