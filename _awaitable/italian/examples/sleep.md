---
layout: default
order: 9
depth: 2
title: Sleep
---
# Sleep

```python
import logging
import time
import random
import typing

import awaitable


@awaitable.awaitable
def do_process(name: str,
               t: typing.Union[int, float]) -> None:
    """
    Await some time before returning
    :param name: task name
    :param t: time to sleep in seconds
    :return: None
    """
    logging.info(f'From {name}: awaiting {t} seconds...')
    starting_time = time.time()
    time.sleep(t)
    logging.info(f'From {name}: task complete '
                 f'in {time.time() - starting_time:.2f} seconds')
```

La funzione **`do_process`** è contrassegnata come awaitable e semplicemente
registrerà un testo descrittivo e attenderà un numero di secondi passato
dall'argomento **`t`**.

```python
async def process(count: int) -> None:
    """
    Run some processes asynchronously
    Each process will await a random number of seconds

    :param count: number of tasks to process
    :return: None
    """
    logging.info(f'Running {count} processes')
    tasks = awaitable.AsyncioGather()
    for i in range(count):
        tasks.add(do_process(name=f'task_{tasks.count() + 1}',
                             t=random.randint(0, count)))
    logging.info(f'Starting to process {len(tasks)} tasks')
    await tasks.run()
```

La funzione **`process`** è una funzione asincrona che raccoglierà un numero di
processi prima di elaborarli tutti insieme in maniera asincrona.

Come risultato, tutte le chiamate a sleep (vedi la funzione **`do_process`**)
saranno eseguite più o meno allo stesso momento e l'intero processo sarà
completato quando l'attesa più lunga verrà completata.

```python
if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO,
                        format='%(levelname)-8s '
                               '%(filename)-15s '
                               'line: %(lineno)-5d '
                               '%(funcName)-20s '
                               '%(message)s')
    starting_time = time.time()
    awaitable.run_awaitable(func=process,
                            count=10)
    ending_time = time.time()
    logging.info(f'Operation completed in {ending_time - starting_time:.2f} '
                 'seconds')
```

La chiamata alla funzione **`run_awaitable`** richiamerà la funzione asincrona
**`process`** passando il numero 10 di lavori paralleli da processare.

Al termine sarà mostrato il numero di secondi passati per completare
l'operazione.

```text
INFO     01_sleep.py     line: 53    process              Running 10 processes
INFO     01_sleep.py     line: 58    process              Starting to process 10 tasks
INFO     01_sleep.py     line: 38    do_process           From task_1: awaiting 10 seconds...
INFO     01_sleep.py     line: 38    do_process           From task_2: awaiting 0 seconds...
INFO     01_sleep.py     line: 41    do_process           From task_2: task complete in 0.00 seconds
INFO     01_sleep.py     line: 38    do_process           From task_3: awaiting 2 seconds...
INFO     01_sleep.py     line: 38    do_process           From task_4: awaiting 9 seconds...
INFO     01_sleep.py     line: 38    do_process           From task_5: awaiting 7 seconds...
INFO     01_sleep.py     line: 38    do_process           From task_6: awaiting 10 seconds...
INFO     01_sleep.py     line: 38    do_process           From task_7: awaiting 5 seconds...
INFO     01_sleep.py     line: 38    do_process           From task_8: awaiting 5 seconds...
INFO     01_sleep.py     line: 38    do_process           From task_9: awaiting 8 seconds...
INFO     01_sleep.py     line: 38    do_process           From task_10: awaiting 0 seconds...
INFO     01_sleep.py     line: 41    do_process           From task_10: task complete in 0.00 seconds
INFO     01_sleep.py     line: 41    do_process           From task_3: task complete in 2.00 seconds
INFO     01_sleep.py     line: 41    do_process           From task_8: task complete in 5.00 seconds
INFO     01_sleep.py     line: 41    do_process           From task_7: task complete in 5.00 seconds
INFO     01_sleep.py     line: 41    do_process           From task_5: task complete in 7.01 seconds
INFO     01_sleep.py     line: 41    do_process           From task_9: task complete in 8.01 seconds
INFO     01_sleep.py     line: 41    do_process           From task_4: task complete in 9.01 seconds
INFO     01_sleep.py     line: 41    do_process           From task_1: task complete in 10.01 seconds
INFO     01_sleep.py     line: 41    do_process           From task_6: task complete in 10.01 seconds
INFO     01_sleep.py     line: 74    <module>             Operation completed in 10.02 seconds
```

Verranno eseguiti 10 lavori con un'attesa casuale tra 0 e 10 secondi e l'intera
operazione verrà completata in circa 10.02 secondi. Senza usare async o
awaitable l'operazione in maniera sincrona avrebbe impiegato circa 56 secondi.
