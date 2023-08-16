---
layout: documentation
order: 551
depth: 2
title: AdminTextInputFilter
nav_prefix: Filters
---
# AdminTextInputFilter Filter

>>>>>> **Available since version 0.4.0**.

## Description

The filter class **AdminTextInputFilter** can be used to define new filter
types, which can be directly used in the code or through
[ListFilter]({% link _django-admin-settings/english/docs/listfilter.md %}).

```python
class AdminTextInputFilter:
    title = None
    parameter_name = None
    lookup_condition = None
    lookup_condition_advanced = None
```

By creating a new inherited class from the previous it will be possible to define new
textual filters to add to Django Admin.

## Members

The following members are available into the class:

| Name                          | Type      | Description                                              |
|:------------------------------|:----------|:---------------------------------------------------------|
| **title**                     | Character | Specifies the title shown for the new filter             |
| **parameter_name**            | Character | Field name to filter, using `lookup_condition`           |
| **lookup_condition**          | Character | Condition to apply to `parameter_name` to filter records |
| **lookup_condition_advanced** | Character | Advanced condition used to filter records                |

##### lookup_condition

The `lookup_condition` value is the same used for [Field lookups] and along with
`parameter_name` is used to filter the model records.

The valid values for `lookup_condition` are the following:

| Valore          | Description                                                                                 | Case insensitive |
|:----------------|:--------------------------------------------------------------------------------------------|:----------------:|
| **exact**       | Filters the records whose value equals the specified value                                  |        No        | 
| **iexact**      | Filters the records whose value equals the specified value                                  |       Yes        |
| **contains**    | Filters the records whose value contains the specified value                                |        No        |
| **icontains**   | Filters the records whose value contains the specified value                                |       Yes        |
| **in**          | Filters the records whose value is contained into the specified value                       |        No        |
| **gt**          | Filters the records whose value is alphabetically greater than the specified value          |        No        |
| **gte**         | Filters the records whose value is alphabetically greater or equal than the specified value |        No        |
| **lt**          | Filters the records whose value is alphabetically lower than the specified value            |        No        |
| **lte**         | Filters the records whose value is alphabetically lower or equal than the specified value   |        No        |
| **startswith**  | Filters the records whose value begins with the specified value                             |        No        |
| **istartswith** | Filters the records whose value begins with the specified value                             |       Yes        |
| **endswith**    | Filters the records whose value ends with the specified value                               |        No        |
| **iendswith**   | Filters the records whose value ends with the specified value                               |       Yes        |
| **regex**       | Filters the records whose value matches the specified regular expression                    |        No        |
| **iregex**      | Filters the records whose value matches the specified regular expression                    |       Yes        |

##### lookup_condition_advanced

The `lookup_condition_advanced` value can be used as alternative for `lookup_condition` to specify
a custom filter.

## Usage examples

For some usage examples refer to the page [Usage examples]({% link _django-admin-settings/english/examples/admintextinputfilter.md %}).

{: target="_blank" .external }
[Field lookups]: https://docs.djangoproject.com/en/stable/ref/models/querysets/#field-lookups
