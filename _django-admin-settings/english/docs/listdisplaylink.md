---
layout: default
order: 9
depth: 2
title: ListDisplayLink
---
# Model ListDisplayLink

## Description

The **ListDisplayLink** model allows to set the *[list_display_links]* attribute
in the Django Admin models to define what columns in the records list can be
clicked to access the record in Django Admin.

{:.center}
![Clickable columns](/resources/django-admin-settings/archive/latest/english/listdisplaylink.png)

In the above example the **id** and the **\_\_str\_\_** columns in the
*ListDisplayAdmin*, *ListDisplayLinkAdmin* and *ListFilterAdmin* are set as clickable.

>>>>> After modifying the ListDisplayLink model you will have to restart the
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
[list_display_links]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/#django.contrib.admin.ModelAdmin.list_display_links
