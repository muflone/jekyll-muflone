---
layout: documentation
order: 534
depth: 2
title: Filter
---

# Classe Filter
{: .no_toc }

La classe **Filter** è utilizzata per definire un filtro usato per confrontare
campi e valori in alcuni metodi della classe Model.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

- TOC
{: toc }

---
## Costruttore

```python
class Filter(field: str,
             compare_type: CompareType,
             value: object)
```

#### Parametri

- **field**: nome del campo da confrontare.
- **compare_type**: uno dei valori della classe CompareType,
  usato come operatore di confronto.
- **value**: valore o valori da confrontare.

#### Esempio di utilizzo

```python
import pyodoo

filter = pyodoo.Filter(field='name',
                       compare_type=pyodoo.CompareType.CONTAINS,
                       value='Muflone')
```

Definisce un filtro che confronta il campo name alla ricerca dei record che
contengono la stringa Muflone, ignorando la differenza tra maiuscole e minuscole.

---

## Metodo explode

```python
Filter.explode()
```

Il metodo **explode** estrae le informazioni dall'oggetto filter
in una lista nella forma [field, compare_type, value] da passare ai metodi
dell'Api di Odoo.

#### Restituisce

- Questo metodo restituisce una lista contenente gli elementi del filtro.

#### Esempio di utilizzo

```python
triplets = filter.explode()
```

[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
