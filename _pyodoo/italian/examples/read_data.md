---
layout: examples
order: 604
depth: 2
title: Lettura dei dati
---
# Lettura dei dati

Esistono tre modi principali per leggere i dati nei modelli:

- TOC
{:toc}

---
## Lettura di tutti i dati da un modello

Gli oggetti **[Model]** dispongono del metodo [all] che restituisce tutti i
record presenti nel modello. Ciò può essere utile quando è necessario caricare
tutti i dati nel modello anziché filtrarli.

Per sapere come vengono trattati i record attivi e quelli archiviati,
consultare la pagina [Record attivi].

```python
from pyodoo.v12 import Model

model_partner = Model(model_name='res.partner',
                      endpoint='https://my.odoo.muflone.com/',
                      database='odoo_db',
                      username='utente',
                      password='password',
                      language='it_IT',
                      authenticate=False)
model_partner.authenticate()
data = model_partner.all()
```

---
## Lettura dei dati usando gli ID dei record

Se conosci già gli ID dei record a cui desideri accedere, puoi utilizzare
i metodi [find], [get] o [get_many].

Un record singolo può essere letto usando il metodo [get]:

```python
data = model_partner.get(entity_id=2)
```

Record multipli possono essere letti in una volta usando il metodo [get_many]:

```python
data = model_partner.get_many(entity_ids=(2, 3, 4))
```

Il metodo [find] offre un maggiore controllo rispetto al metodo [get_many],
consentendo anche di specificare argomenti aggiuntivi come is_active, limit,
offset e altri:

```python
data = model_partner.find(entity_ids=(2, 3, 4))
```

---
## Trovare i record usando i filtri

Per trovare i record necessari è possibile combinare diversi [Filters]
utilizzati per filtrare le righe del modello con i metodi
[filter], [first], [count], [search].

Tutti i metodi precedenti richiedono un elenco di oggetti [Filter] o
[BooleanOperator]. Verranno quindi restituiti solo i record corrispondenti
(dopo aver applicato il filtro automatico sui [Record attivi]).

Ad esempio, il seguente elenco di filtri includerà i contatti con un nome
contenente *Muflone*, escludendo i record con ID 193623.

```python
filters = [BooleanOperator.AND,
           Filter(field='name',
                  compare_type=CompareType.CONTAINS,
                  value='Muflone'),
           BooleanOperator.NOT,
           Filter(field='id',
                  compare_type=CompareType.NOT_EQUAL,
                  value=193623)
           ]
```

Se hai solo bisogno di **trovare gli ID dei record** corrispondenti, puoi
utilizzare il metodo [search], che restituirà solo gli ID dei record
corrispondenti ai criteri di ricerca.

```python
data = model_partner.search(filters=filters)
```

Se hai solo bisogno di conoscere il **numero di record corrispondenti** ai
filtri, allora il metodo [count] lo farà:

```python
count = model_partner.count(filters=filters)
```

Se hai bisogno di trovare e leggere i dati dei record, puoi utilizzare il metodo
[filter] che **restituirà un elenco di dizionari**
con tutti i dettagli dei record.

```python
data = model_partner.filter(filters=filters)
```

Il metodo [first] è molto simile al metodo [filter], ma restituisce solo
**il primo record** come dizionario o None se non verranno trovati record.

```python
data = model_partner.first(filters=filters)
```

[Model]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}
[all]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-all
[Record attivi]: {% link _pyodoo/italian/docs/active.md %}
[get]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-get
[get_many]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-get_many
[find]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-find
[Filters]: {% link _pyodoo/italian/docs/filters.md %}
[Filter]: {% link _pyodoo/italian/docs/pyodoo/filter.md %}
[BooleanOperator]: {% link _pyodoo/italian/docs/pyodoo/boolean_operator.md %}
[search]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-search
[filter]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-filter
[first]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-first
[count]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-count
