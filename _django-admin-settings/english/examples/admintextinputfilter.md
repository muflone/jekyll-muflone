---
layout: examples
order: 601
depth: 2
title: AdminTextInputFilter
---
# Description

The followings are some usage examples for
[AdminTextInputFilter]({% link _django-admin-settings/english/docs/admintextinputfilter.md %}). The newly created class
could then be inserted in [ListFilter]({% link _django-admin-settings/english/docs/listfilter.md %}) or
be specified in the matching ModelAdmin [list_filter].

## Exact match

```python
class TextInputFilterExact(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'exact'
```

Filters the model records including those whose data1 field **matches the exact** specified value.

{: .center }
![](/resources/django-admin-settings/archive/latest/english/admintextinputfilter_exact.png)

## Partial match with contains

```python
class TextInputFilterContains(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'contains'
```

Filters the model records including those whose data1 field **contains** the specified value.

```python
class TextInputFilterIContains(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'icontains'
```

Filters the model records including those whose data1 field **contains** the specified value, ignoring
any differences between upper and lower case.

{: .center }
![](/resources/django-admin-settings/archive/latest/english/admintextinputfilter_contains.png)

## Initial or final match

```python
class TextInputFilterStarting(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'startswith'
```

Filters the model records including those whose data1 field **begins** with the indicated value.

{: .center }
![](/resources/django-admin-settings/archive/latest/english/admintextinputfilter_startswith.png)

```python
class TextInputFilterIEnding(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'iendswith'
```

Filters the model records including those whose data1 field **ends** with the indicated value, ignoring
any differences between upper and lower case.

{: .center }
![](/resources/django-admin-settings/archive/latest/english/admintextinputfilter_endswith.png)

## Match with regular expression

```python
class TextInputFilterRegex(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'regex'
```

Filters the model records including those whose data1 field **matches the regular expression**
with the indicated value.

For example, specifying on the filter the value `^[0-9]{4}$` only the records with 4 digits in the data1
field will be found.

{: .center }
![](/resources/django-admin-settings/archive/latest/english/admintextinputfilter_regex.png)


## Match with regular expression using an advanced filter

```python
class TextInputFilterData1(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition_advanced = 'data1__regex'
```

Filters the model records including those whose data1 field **matches the regular expression**
with the indicated value, using the advanced filter.

For example, specifying on the filter the value `^[0-9]{4}$` only the records with 4 digits in the data1
field will be found.

{: .center }
![](/resources/django-admin-settings/archive/latest/english/admintextinputfilter_regex.png)

{: target="_blank" .external }
[list_filter]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/filters/
