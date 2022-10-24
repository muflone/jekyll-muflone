---
layout: index
order: 1
title: Introduction
---
A small Python decorator to asynchronously execute synchronous functions.

**Awaitable** can be useful when you want asynchronously to execute a synchronous
function which you cannot rewrite asynchronously using `await` because it may
contain some code that's not awaitable, for thirdy part libraries or some
functions are used in some other parts of the code in synchronous way.

The awaitable decorator allows you to declare the synchronous function as
awaitable, so it could be executed from another asynchonous function.

```python
import awaitable

@awaitable.awaitable
def do_something():
    # process a single task
    return
```

# AsyncioGather

The **AsyncioGather** class can be used to process some tasks using asyncio,
collecting the tasks to run and to run them, to process them asynchronously
grouped.

The following example declares a function `do_something` as awaitable and
into the asynchronous function `process` you define a group of tasks to
collect, also with different arguments or different asynchronous functions
(both really awaitable or made them awaitable with the decorator).

The tasks group will be used to execute later with `run()` the calls to the
asynchronous functions.

```python
import awaitable

@awaitable.awaitable
def do_something():
    # do something I/O intensive which can be awaited
    return

async def process(count):
    # execute some workers
    tasks = awaitable.AsyncioGather()
    for i in range(count):
        tasks.add(do_something())
    await tasks.run()
```

Using `tasks.run()` you'll execute all the tasks into the AsyncioGather tasks
group and you'll process all the tasks asynchronously.

```python
awaitable.run_awaitable(func=process, count=10)
```

The `run_awaitable` function will execute the asynchronous function
`process(count=10)` to collect and process every generated task.
