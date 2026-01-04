---
layout: examples
order: 602
depth: 2
title: FieldTextFilter
---
# Description

The [FieldTextFilter]({% link _django-admin-settings/english/docs/fieldtextfilter.md %}) can be added to
[ListDisplay]({% link _django-admin-settings/english/docs/listdisplay.md %}),
[ListDisplayLink]({% link _django-admin-settings/english/docs/listdisplaylink.md %}) or to
[ListFilter]({% link _django-admin-settings/english/docs/listfilter.md %}),
to filter the records using the field named *field*.

>>>>> The FieldTextFilter filter is of **exact match type**, so it will filter the values
>>>>> which exactly match with what was specified from the user.

## Configuration

{: .center }
![](/resources/django-admin-settings/archive/latest/english/fieldtextfilter_filter.png)

You can simply add a new filter with field name `django_admin_settings.admin.FieldTextFilter`
to the models ListDisplay, ListDisplayLink or ListFilter
(or any other model with a field named *field*).

## Results

{: .center }
![](/resources/django-admin-settings/archive/latest/english/fieldtextfilter_results.png)

The filter will match any records with the field named *field* with the specified value.
