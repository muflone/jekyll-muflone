---
layout: index
order: 100
title: Introduzione
---
Un piccolo decoratore Python per eseguire in maniera asincrona funzioni
sincrone.

**Awaitable** può essere utile quando si desidera eseguide in maniera asincrona
una funzione sincrona che non può essere riscritta in maniera asincrona
utilizzando `await` poiché potrebbe contenere del codice che non può essere
atteso, per la presenza di librerie di terze parti oppure se alcune funzioni
sono utilizzate in altre parti del codice in maniera sincrona.

Il decoratore [awaitable]({% link _awaitable/italian/docs/awaitable.md %})
permette di dichiarare le funzioni sincrone come attese, in modo da poter essere
eseguite da un'altra funzione asincrona.

```python
import awaitable

@awaitable.awaitable
def do_something():
    # processa un singolo task
    return
```

# AsyncioGather

La classe [AsyncioGather]({% link _awaitable/italian/docs/asynciogather.md %})
può essere utilizzata per processare alcuni task usando asyncio, raccogliendo i
task da eseguire ed eseguendoli, per processarli raggruppati in maniera asincrona.

L'esempio seguente dichiara una funzione `do_something` come attesa e all'interno
della funzione `process` si definisce un gruppo di task per raccogliere, anche
con argomenti differenti o funzioni asincrone differenti (sia davvero attese sia
fatte attraverso il decoratore awaitable).

Il gruppo di task sarà utilizzato per eseguire dopo attraverso `run()` le chiamate
alle funzioni asincrone.

```python
import awaitable

@awaitable.awaitable
def do_something():
    # fai qualcosa con attività I/O intensa che può essere attesa
    return

async def process(count):
    # esegui alcuni lavori
    tasks = awaitable.AsyncioGather()
    for i in range(count):
        tasks.add(do_something())
    await tasks.run()
```

Utilizzando `tasks.run()` tutti i task all'interno del gruppo AsyncioGather
verranno eseguiti e saranno processati in maniera asincrona.

```python
awaitable.run_awaitable(func=process, count=10)
```

La funzione [run_awaitable]({% link _awaitable/italian/docs/run_awaitable.md %})
eseguira la funzione asincrona `process(count=10)` per raccogliere e processare
ogni task generato.
