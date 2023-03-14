---
layout: default
order: 10
depth: 2
title: ListFilter
---
# Model ListFilter

## Description

The **ListFilter** model allows to set the *[list_filter]* attribute
in the Django Admin models to define the filters to configure.

{:.center}
![Filters list](/resources/django-admin-settings/archive/latest/english/listfilter.png)

In the above example the filters for the fields **is_active** and **model**
for the *ListDisplayAdmin*, *ListDisplayLinkAdmin* and *ListFilterAdmin* are
configured.

>>>>> After modifying the ListFilter model you will have to restart the
>>>>> Django application to load the new settings.

>>>>>> If no filters are defined the filters configured in the Django model
>>>>>> will be used. If every configured filters will be disabled then also
>>>>>> the default filters from the model will be removed.

## Fields

The following fields are present into the model:

| Name            | Type                  | Description                                               |
|:----------------|:----------------------|:----------------------------------------------------------|
| **id**          | Integer (automatic)   | Uniquely identifies the record into the model             |
| **\_\_str\_\_** | Character (automatic) | Shows a brief description of the record in the model      |
| **model**       | Character             | Identifies the model name to configure                    |
| **field**       | Character             | Identifies the field name in the admin model to configure |
| **order**       | Integer               | Defines the numeric order of the fields to configure      |
| **is_active**   | Boolean               | Allows to enable or disable the the configured field      |

{: target="_blank" .external }
[list_filter]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/#django.contrib.admin.ModelAdmin.list_filter
