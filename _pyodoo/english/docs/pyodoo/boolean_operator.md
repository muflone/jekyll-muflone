---
layout: documentation
order: 532
depth: 2
title: BooleanOperator
---

# Class BooleanOperator

The **BooleanOperator** class is used to combine multiple filters for the
filter method in the Model class, to specify whether the next filter will be
negated or else the two following filters are combined with And/Or.

This class is not required to be instanced as its members can be directly used
by specifying the class members.

To see some usage examples you can look at the page
[Usage examples].

## Members

### NOT

```python
NOT = '!'
```

The next filter will be negated, and it will return True if the filter result
would be False or the opposite.

### AND

```python
AND = '&'
```

The next two filters will be combined with a boolean And. This is the default
also if the operator is not specified and two filters are combined.

### OR

```python
OR = '|'
```

The next two filters will be combined with a boolean Or.

[Usage examples]: {% link _pyodoo/english/examples/index.md %}
