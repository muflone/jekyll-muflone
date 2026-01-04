---
layout: examples
order: 601
depth: 2
title: AdminTextInputFilter
---
# Descrizione

Quelli seguenti sono alcuni esempi di utilizzo di
[AdminTextInputFilter]({% link _django-admin-settings/italian/docs/admintextinputfilter.md %}). La nuova classe
creata potrà poi essere inserita su [ListFilter]({% link _django-admin-settings/italian/docs/listfilter.md %}) oppure
essere specificata in [list_filter] del ModelAdmin corrispondente.

## Corrispondenza esatta

```python
class TextInputFilterExact(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'exact'
```

Filtra i record del modello riportando quelli il cui campo data1 **corrisponde esattamente** al valore indicato.

{: .center }
![](/resources/django-admin-settings/archive/latest/italian/admintextinputfilter_exact.png)

## Corrispondenza parziale con contains

```python
class TextInputFilterContains(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'contains'
```

Filtra i record del modello riportando quelli il cui campo data1 **contiene** il valore indicato.

```python
class TextInputFilterIContains(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'icontains'
```

Filtra i record del modello riportando quelli il cui campo data1 **contiene** il valore indicato, ignorando le
differenze tra maiuscole e minuscole.

{: .center }
![](/resources/django-admin-settings/archive/latest/italian/admintextinputfilter_contains.png)

## Corrispondenza iniziale o finale

```python
class TextInputFilterStarting(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'startswith'
```

Filtra i record del modello riportando quelli il cui campo data1 **inizia** col valore indicato.

{: .center }
![](/resources/django-admin-settings/archive/latest/italian/admintextinputfilter_startswith.png)

```python
class TextInputFilterIEnding(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'iendswith'
```

Filtra i record del modello riportando quelli il cui campo data1 **termina** col valore indicato, ignorando le
differenze tra maiuscole e minuscole.

{: .center }
![](/resources/django-admin-settings/archive/latest/italian/admintextinputfilter_endswith.png)

## Corrispondenza con espressione regolare

```python
class TextInputFilterRegex(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition = 'regex'
```

Filtra i record del modello riportando quelli il cui campo data1 **corrisponde all'espressione regolare**
del valore indicato.

Inserendo sul filtro il valore `^[0-9]{4}$` saranno ad esempio trovati i record il cui campo data1 contiene
esattamente 4 numeri.

{: .center }
![](/resources/django-admin-settings/archive/latest/italian/admintextinputfilter_regex.png)


## Corrispondenza con espressione regolare usando un filtro avanzato

```python
class TextInputFilterData1(AdminTextInputFilter):
    parameter_name = 'data1'
    title = 'Data 1'
    lookup_condition_advanced = 'data1__regex'
```

Filtra i record del modello riportando quelli il cui campo data1 **corrisponde all'espressione regolare**
del valore indicato, utilizzando il filtro avanzato.

Inserendo sul filtro il valore `^[0-9]{4}$` saranno ad esempio trovati i record il cui campo data1 contiene
esattamente 4 numeri.

{: .center }
![](/resources/django-admin-settings/archive/latest/italian/admintextinputfilter_regex.png)

{: target="_blank" .external }
[list_filter]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/filters/
