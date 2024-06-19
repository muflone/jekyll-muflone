---
layout: documentation
order: 533
depth: 2
title: CompareType
---

# Class CompareType

The **CompareType** class is used to compare a field with values and compose
a filter.

This class is not required to be instanced as its members can be directly used
by specifying the class members.

To see some usage examples you can look at the page
[Usage examples].

## Members

### EQUAL

```python
EQUAL = '='
```

The compared field value must match the value.

### NOT_EQUAL

```python
NOT_EQUAL = '!='
```

The compared field value must not match the value.

### GREATER

```python
GREATER = '>'
```

The compared field value must be greater than the value.

### GREATER_EQ

```python
GREATER_EQ = '>='
```

The compared field value must be greater or equal than the value.

### LOWER

```python
LOWER = '<'
```

The compared field value must be lower than the value.

### LOWER_EQ

```python
LOWER_EQ = '<='
```

The compared field value must be lower or equal than the value.

### IN

```python
IN = 'in'
```

The compared field value must be one of the values.

### NOT_IN

```python
NOT_IN = 'not in'
```

The compared field value must not be one of the values.

### CONTAINS

```python
CONTAINS = 'ilike'
```

The compared field value must contain the value.

### CONTAINS_NOT

```python
CONTAINS_NOT = 'not ilike'
```

The compared field value must not contain the value.

### NOT_CONTAINS

```python
NOT_CONTAINS = 'not ilike'
```

The compared field value must not contain the value.
It's a synonym of CONTAINS_NOT.

### LIKE

```python
LIKE = 'like'
```

The compared field value must be similar to the value.
For alphanumeric values it will be automatically added % to start and to the end
to make sure the value be included in any part of the field value.

### NOT_LIKE

```python
NOT_LIKE = 'not like'
```

The compared field value must not be similar to the value.
For alphanumeric values it will be automatically added % to start and to the end
to make sure the value be included in any part of the field value.

### ILIKE

```python
ILIKE = 'ilike'
```

The compare will be similar to LIKE but the field value must have the same
match for lowercase and uppercase.

### NOT_ILIKE

```python
NOT_ILIKE = 'not ilike'
```

The compare will be similar to NOT_LIKE but the field value must have the same
match for lowercase and uppercase.

### RAW_LIKE

```python
RAW_LIKE = '=like'
```

The compare will be similar to LIKE but no % will be added to the start and
to the end of the value, so it will be possible to do matches
more precise.

### RAW_ILIKE

```python
RAW_ILIKE = '=ilike'
```

The compare will be similar to ILIKE but no % will be added to the start and
to the end of the value, so it will be possible to do matches
more precise.

### UNSET_OR_EQUAL

```python
UNSET_OR_EQUAL = '=?'
```

The compare will be similar to EQUAL but it will be matched also if the field
value would be None or False.

### CHILD_OF

```python
CHILD_OF = 'child_of'
```

The compared field value must be a descendant child for the value.
This behaviour is based on hierarchies, for example with the products
categories.

### PARENT_OF

```python
PARENT_OF = 'parent_of'
```

The compared field value must be an ascendant parent for the value.
This behaviour is based on hierarchies, for example with the products
categories.

[Usage examples]: {% link _pyodoo/english/examples/index.md %}
