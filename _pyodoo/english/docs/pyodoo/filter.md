---
layout: documentation
order: 534
depth: 2
title: Filter
---

# Class Filter
{: .no_toc }

The **Filter** class is used to define a filter used to compare field and values
in some methods for the class Model.

To see some usage examples you can look at the page
[Usage examples].

- TOC
{: toc }

---
## Constructor

```python
class Filter(field: str,
             compare_type: CompareType,
             value: object)
```

#### Parameters

- **field**: field name to compare.
- **compare_type**: one of the CompareType class values,
  used as comparing operator.
- **value**: value or values to compare.

#### Usage example

```python
import pyodoo

filter = pyodoo.Filter(field='name',
                       compare_type=pyodoo.CompareType.CONTAINS,
                       value='Muflone')
```

Define a filter to compare the field name to search records containing the
string Muflone, ignoring any differences between uppercase and lowercase.

---

## Method explode

```python
Filter.explode()
```

The method **explode** extracts the information into the filter object
in a list in the form [field, compare_type, value] to be passed to the Odoo
Api methods.

#### Returns

- The method returns a list with the items in the filter.

#### Usage example

```python
triplets = filter.explode()
```

[Usage examples]: {% link _pyodoo/english/examples/index.md %}
