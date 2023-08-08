---
layout: default
order: 512
depth: 2
title: run_awaitable
---

# Function run_awaitable

## Definition

```python
def run_awaitable(func: typing.Callable, *args, **kwargs) -> None
```

The function **run_awaitable** allows to execute an aynchronous function from
within another synchronous function.

#### Arguments

- **func**: the asynchronous function to execute.
- **\*args**: a positional arguments list to pass to the function.
- **\*\*kwargs**: a keywords arguments dictionary to pass to the function.

#### Returns

- The functions returns none.

#### Usage example

The function can be used to execute asynchronous code from within another
synchronous function.

```python
import awaitable

async def process(count: int) -> None:
    pass

awaitable.run_awaitable(func=process, count=10)
```

This will execute the asynchronous function **process** passing the argument
*count=10* (through the argument **\*\*kwargs** in **run_awaitable**).
