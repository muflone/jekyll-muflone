---
layout: examples
order: 602
depth: 2
title: FieldTextFilter
---
# Descrizione

Il filtro [FieldTextFilter]({% link _django-admin-settings/italian/docs/fieldtextfilter.md %}) può essere aggiunto a
[ListDisplay]({% link _django-admin-settings/italian/docs/listdisplay.md %}),
[ListDisplayLink]({% link _django-admin-settings/italian/docs/listdisplaylink.md %}) o a
[ListFilter]({% link _django-admin-settings/italian/docs/listfilter.md %}),
per filtrare i record usando il campo di nome *field*.

>>>>> Il filtro FieldTextFilter è di **tipo ricerca esatta**, ovvero filtrerà i valori
>>>>> che corrispondono esattamente a quanto specificato dall'utente.

## Configurazione

{:.center}
![](/resources/django-admin-settings/archive/latest/italian/fieldtextfilter_filter.png)

Basterà aggiungere ai modelli ListDisplay, ListDisplayLink o ListFilter
(o qualsiasi altro modello che disponga di un campo di nome *field*) un nuovo filtro usando come
nome del campo `django_admin_settings.admin.FieldTextFilter`.

## Risultato

{:.center}
![](/resources/django-admin-settings/archive/latest/italian/fieldtextfilter_results.png)

Il filtro farà corrispondenza esatta di qualsiasi records con un campo di nome *field* col valore specificato.
