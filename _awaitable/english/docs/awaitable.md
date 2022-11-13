---
layout: default
order: 5
depth: 2
title: awaitable
---

# Function awaitable

## Definition

```python
def awaitable(func: typing.Callable)
```

The function decorator **awaitable** aims to mark a synchronous function as
an awaitable function to be called from another asynchronous function.

#### Arguments

- **func**: the decorated function to wrap and transform it in an asynchronous
            function.

#### Returns

- The decorated function marked as awaitable.

#### Usage example

The function can be used as a decorator with **@awaitable** before the function
to decorate.

```python
import awaitable

@awaitable.awaitable
def do_process(a, b):
    ...
```

Wrapping the **do_process** function with the **awaitable** decorator makes the
decorated function as awaitable, so it can be executed from another asynchronous
function and could also be suspended (awaited) allowing other parts of the code
to be run in parallel.
