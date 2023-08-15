---
layout: documentation
order: 552
depth: 2
title: FieldTextFilter
---
# FieldTextFilter Filter

>>>>>> **Available since version 0.4.0**.

## Description

The filter class **FieldTextFilter** is inherited from
[AdminTextInputFilter]({% link _django-admin-settings/english/docs/admintextinputfilter.md %})
and can be used to filters the records using the field named `field`
(already existing in some Django Admin Settings models).
To use this filter you have to specify `django_admin_settings.admin.FieldTextFilter` as field name.

>>>>> The FieldTextFilter filter is of **exact match type**, so it will filter the values
>>>>> which exactly match with what was specified from the user.

## Usage examples

For some usage examples refer to the page [Usage examples]({% link _django-admin-settings/english/examples/fieldtextfilter.md %}).
