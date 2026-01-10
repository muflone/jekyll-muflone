---
layout: documentation
order: 531
depth: 2
title: ActiveStatusChoice
nav_prefix: Package pyodoo
---

# Class ActiveStatusChoice

The **ActiveStatusChoice** class is used to specify the behavior for the active
argument in many methods, to determine whether to include or exclude the
inactive records, those with field active=False.

This class is not required to be instanced as its members can be directly used
by specifying the class members.

To see some usage examples you can look at the page
[Usage examples].

## Members

### NOT_SET

```python
NOT_SET = None
```

The records with the active field won't be included in the filter operation,
leaving then the model the choice to include or not include them. This is the
default behavior if the value is not specified.

### ACTIVE

```python
ACTIVE = True
```

Only the records with active=True will be included in the filter.

### INACTIVE

```python
INACTIVE = False
```

Only the records with active=False will be included in the filter.

### BOTH

```python
BOTH = [True, False]
```

Both records with active=True and active=False will be included in the filter.

[Usage examples]: {% link _pyodoo/english/examples/index.md %}
