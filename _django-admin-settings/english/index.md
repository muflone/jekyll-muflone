---
layout: index
order: 100
title: Introduction
---
**Django Admin Settings** is a Django application to configure some aspects
of the [Django Admin] administration interface.

{:.center}
![Columns list](/resources/django-admin-settings/archive/latest/english/listdisplay.png)

Using the models **ListDisplay** and **ListDisplayLink** will be possible
to configure the records list in Django Admin.

{:.center}
![Filters list](/resources/django-admin-settings/archive/latest/english/listfilter.png)

Using the **ListFilter** model will be possible to define what filters are
available in the side panel.

# Documentation

The settings and models documentation for Django Admin Settings can be found
in the [Documentation section]({% link _django-admin-settings/english/docs/index.md %}).

{: target="_blank" .external }
[Django Admin]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/

# Activation

The application can be added to any existing project, simply by installing the
package and then adding the application to the `INSTALLED_APPS` variable in
the Django project's settings:

```python
INSTALLED_APPS = [
    'django_admin_settings',
    ...
]
```
