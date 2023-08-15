---
layout: documentation
order: 552
depth: 2
title: FieldTextFilter
---
# Filtro FieldTextFilter

>>>>>> **Disponibile a partire dalla versione 0.4.0**.

## Descrizione

La classe del filtro **FieldTextFilter** è derivata da
[AdminTextInputFilter]({% link _django-admin-settings/italian/docs/admintextinputfilter.md %})
e può essere utilizzata per filtrare i record utilizzando il campo di nome `field`
(già presente in alcuni modelli di Django Admin Settings).
Per utilizzare questo filtro è necessario specificare `django_admin_settings.admin.FieldTextFilter` come nome di campo.

>>>>> Il filtro FieldTextFilter è di **tipo ricerca esatta**, ovvero filtrerà i valori
>>>>> che corrispondono esattamente a quanto specificato dall'utente.

## Esempi di utilizzo

Per alcuni esempi di utilizzo fare riferimento alla pagina [Esempi di utilizzo]({% link _django-admin-settings/italian/examples/fieldtextfilter.md %}).
