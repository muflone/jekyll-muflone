---
layout: documentation
order: 512
depth: 2
title: Filters
---
# Filters

There are some ways to filter data in order to find the desired records in
a model: `filter` and `search` methods. The method `first` operates in a way
similar to `filter`, while the method `count` simply returns the records
count.

To filter the data the `filters` argument for the previous methods must be
specified as a list combined of:

- some [BooleanOperator] objects to apply to the next values in the filters
  list. The ***NOT*** operator applies to the next Filter object,
  while ***AND*** and ***OR*** operators apply to next two Filter
  objects.
- some [Filter] objects

You can define a filters list using a Python list combining both
[BooleanOperator] and [Filter] objects.

<blockquote><blockquote><blockquote><blockquote><blockquote><blockquote><p>
If no operators are specified an implicit AND will be applied to all the Filter
objects.
</p></blockquote></blockquote></blockquote></blockquote></blockquote></blockquote>

## Single field filters list

To create a filters list for a single field you can use the following:

```python
filters = [
  Filter('field1', CompareType.EQUAL, 'value1'),
]
```

## Two fields filters list

To create a filters list with two fields you can use the following:

```python
filters = [
  BooleanOperator.AND,
  Filter('field1', CompareType.EQUAL, 'value1'),
  Filter('field2', CompareType.EQUAL, 'value2'),
]
```

## Multiple fields filters list

To create a filters list with three fields you have to specify two operators:
the former for combining the first Filter object with the result of the
operation between the second operator with the second and the third Filter
objects:

```python
filters = [
  BooleanOperator.AND,
  Filter('field1', CompareType.EQUAL, 'value1'),  # A
  BooleanOperator.OR,
  Filter('field2', CompareType.EQUAL, 'value2'),  # B
  Filter('field3', CompareType.EQUAL, 'value3'),  # C
]
```

The previous expression will match the record having `field1 = 'value1'` and
those having either `field2 = 'value2'` or `field3 = 'value3'`. In Python code
this would be described as ***A and (B or C)*** which equals to:

```python
field1 == 'value1' and (field2 == 'value2' or field3 == 'value3')
```

If you need to create a filters list combining the first two filters or another
filter, you have to change the order BooleanOperator objects:

```python
filters = [
  BooleanOperator.AND,
  BooleanOperator.OR,
  Filter('field1', CompareType.EQUAL, 'value1'),  # A
  Filter('field2', CompareType.EQUAL, 'value2'),  # B
  Filter('field3', CompareType.EQUAL, 'value3'),  # C
]
```

The previous filters list will translate to ***(A or B) and C*** which equals
to:

```python
(field1 == 'value1' or field2 == 'value2') and field3 == 'value3'
```

You can combine multiple BooleanOperator object with multiple Filter object as
you need.

## Negate a filter object

You can negate a Filter object using `BooleanOperator.NOT` applied to the next
filter or expression like the following example:

```python
filters = [
  BooleanOperator.AND,
  Filter('field1', CompareType.EQUAL, 'value1'),
  BooleanOperator.NOT,
  Filter('field2', CompareType.EQUAL, 'value2'),
]
```

[Filter]: {% link _pyodoo/english/docs/pyodoo/filter.md %}
[BooleanOperator]: {% link _pyodoo/english/docs/pyodoo/boolean_operator.md %}
