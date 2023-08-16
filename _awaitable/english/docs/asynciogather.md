---
layout: documentation
order: 551
depth: 2
title: AsyncioGather
nav_prefix: Classes
---

# Class AsyncioGather

The **AsyncioGather** class is used to collect all the tasks to execute and
when the gather is complete to execute them all asynchronously in parallel.

To see some usage examples you can look at the page
[Usage examples]({% link _awaitable/english/examples/index.md %}).

## Method add

```python
def add(self, coroutine: typing.Coroutine) -> int
```

The **add** method adds an asynchronous function (coroutine) to the tasks list
to execute.

This method is used to add an asynchronous function to the tasks list to
execute them all in parallel at the end of the collect.

#### Arguments

- **coroutine**: the asynchronous function to execute.

#### Returns

- The number of tasks already added.

#### Usage example

```python
import awaitable

tasks = awaitable.AsyncioGather()
tasks.add(do_process(...))
```

---

## Method count

```python
def count(self) -> int
```

The **count** method returns the number of queued tasks.

#### Returns

- The number of tasks in queue.

#### Usage example

```python
import awaitable

tasks = awaitable.AsyncioGather()
tasks.add(do_process(...))
print(tasks.count())
```

---

## Method run

```python
async def run(self) -> None
```

The **run** method executes all the queued tasks in parallel.

This method is asynchronous, so it must be called from an asynchronous function
or through **run_awaitable**.

#### Returns

- The method returns none.

#### Usage example

```python
import awaitable

async def process():
    tasks = awaitable.AsyncioGather()
    for _ in range(5):
        tasks.add(do_process(...))
    await tasks.run()
```
