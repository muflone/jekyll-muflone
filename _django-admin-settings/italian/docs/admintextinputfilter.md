---
layout: documentation
order: 551
depth: 2
title: AdminTextInputFilter
nav_prefix: Filtri
---
# Filtro AdminTextInputFilter

>>>>>> **Disponibile a partire dalla versione 0.4.0**.

## Descrizione

La classe del filtro **AdminTextInputFilter** può essere utilizzata per definire
nuove tipologie di filtro, utilizzabili direttamente nel codice o attraverso
[ListFilter]({% link _django-admin-settings/italian/docs/listfilter.md %}).

```python
class AdminTextInputFilter:
    title = None
    parameter_name = None
    lookup_condition = None
    lookup_condition_advanced = None
```

Creando una nuova classe derivata della precedente è possibile definire nuovi
filtri testuali da aggiungere a Django Admin.

## Membri

All'interno della classe sono disponibili i seguenti membri:

| Nome                          | Tipologia | Descrizione                                                       |
|:------------------------------|:----------|:------------------------------------------------------------------|
| **title**                     | Carattere | Specifica il titolo che verrà mostrato per il nuovo filtro        |
| **parameter_name**            | Carattere | Nome del campo che verrà filtrato, utilizzando `lookup_condition` |
| **lookup_condition**          | Carattere | Condizione da applicare a `parameter_name` per filtrare i record  |
| **lookup_condition_advanced** | Carattere | Condizione avanzata utilizzata per filtrare i record              |

##### lookup_condition

Il valore di `lookup_condition` è lo stesso usato in [Field lookups] e in combinazione con
`parameter_name` è utilizzato per filtrare i record del modello.

I valori ammessi per `lookup_condition` sono i seguenti:

| Valore          | Descrizione                                                                              | Ignora maiuscole/minuscole |
|:----------------|:-----------------------------------------------------------------------------------------|:--------------------------:|
| **exact**       | Filtra i record il cui valore è uguale al valore specificato                             |             No             | 
| **iexact**      | Filtra i record il cui valore è uguale al valore specificato                             |             Sì             |
| **contains**    | filtra i record il cui valore contiene il valore specificato                             |             No             |
| **icontains**   | Filtra i record il cui valore contiene il valore specificato                             |             Sì             |
| **in**          | Filtra i record il cui valore è contenuto nel valore specificato                         |             No             |
| **gt**          | Filtra i record il cui valore è alfabeticamente maggiore del valore specificato          |             No             |
| **gte**         | Filtra i record il cui valore è alfabeticamente maggiore o uguale del valore specificato |             No             |
| **lt**          | Filtra i record il cui valore è alfabeticamente minore del valore specificato            |             No             |
| **lte**         | Filtra i record il cui valore è alfabeticamente minore o uguale del valore specificato   |             No             |
| **startswith**  | Filtra i record il cui valore inizia col valore specificato                              |             No             |
| **istartswith** | Filtra i record il cui valore inizia col valore specificato                              |             Sì             |
| **endswith**    | Filtra i record il cui valore termina col valore specificato                             |             No             |
| **iendswith**   | Filtra i record il cui valore termina col valore specificato                             |             Sì             |
| **regex**       | Filtra i record il cui valore corrisponde all'espressione regolare specificata           |             No             |
| **iregex**      | Filtra i record il cui valore corrisponde all'espressione regolare specificata           |             Sì             |

##### lookup_condition_advanced

Il valore di `lookup_condition_advanced` può essere utilizzato in alternativa a `lookup_condition` per
specificare un filtro personalizzato.

## Esempi di utilizzo

Per alcuni esempi di utilizzo fare riferimento alla pagina [Esempi di utilizzo]({% link _django-admin-settings/italian/examples/admintextinputfilter.md %}).

{: target="_blank" .external }
[Field lookups]: https://docs.djangoproject.com/en/stable/ref/models/querysets/#field-lookups
