---
layout: default
order: 5
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

The **`do_process`** function is marked as awaitable and it will simply log a
descriptive text and sleep an amount of seconds as passed from the argument
**`t`**.

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

The **`process`** function is an asynchronous function which will gather a number
of processes before processing them at once in asynchronous way.

As the result, all the sleep (see the **`do_process`** function) calls will be
executed more or less at the same time and the whole process will be completed
when the longest sleep will be completed.

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

The function call **`run_awaitable`** will execute the asynchronous function
**`process`** passing the number of parallel workers 10 to process.

At the end the elapsed seconds needed to complete the operation will be
printed.

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

It will execute 10 jobs with a random sleep from 0 to 10 seconds and the whole
operation will be completed in about 10.02 seconds. Without using async or
awaitable the synchronous operation would have needed about 56 seconds.
