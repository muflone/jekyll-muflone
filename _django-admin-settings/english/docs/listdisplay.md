---
layout: documentation
order: 531
depth: 2
title: ListDisplay
nav_prefix: Models
---
# Model ListDisplay

## Description

The **ListDisplay** model allows to set the *[list_display]* attribute
in the Django Admin models to define the columns to show in
Django Admin.

{: .center }
![Columns list](/resources/django-admin-settings/archive/latest/english/listdisplay.png)

In the above example all the existing columns for *ListDisplayAdmin* are
displayed.

>>>>> After modifying the ListDisplay model you will have to restart the
>>>>> Django application to load the new settings.

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
[list_display]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/#django.contrib.admin.ModelAdmin.list_display
