---
layout: examples
order: 604
depth: 2
title: Read data
---
# Read data

There are three major ways to read data in the models:

- TOC
{:toc}

---
## Read all data from a model

**[Model]** objects have the [all] method which will return all the records in
the model. This may be useful when you need to load all the data in the model
instead of filtering them.

Please refer the page [Active records] to know how the active and archived
records are treated.

```python
from pyodoo.v12 import Model

model_partner = Model(model_name='res.partner',
                      endpoint='https://my.odoo.muflone.com/',
                      database='odoo_db',
                      username='myuser',
                      password='mypassword',
                      language='en_GB',
                      authenticate=False)
model_partner.authenticate()
data = model_partner.all()
```

---
## Read data using their record IDs

If you already know the IDs of the records you want to access to you can use
the [find], [get] or [get_many] methods.

A single record can be read using the method [get]:

```python
data = model_partner.get(entity_id=2)
```

Multiple records can be read at once using the method [get_many]:

```python
data = model_partner.get_many(entity_ids=(2, 3, 4))
```

The method [find] offers more control compared to the method [get_many],
allowing also to specify extra arguments like is_active, limit, offset and
others:

```python
data = model_partner.find(entity_ids=(2, 3, 4))
```

---
## Find the records using the filters

To find the needed records you can combine many [Filters] used to filter
the model rows with the methods
[filter], [first], [count], [search].

All the previous methods requires a list of [Filter] or [BooleanOperator]
objects. Only the matching records will be then returned (after applying the
[Active records] automatic filtering).

For example the following filters list will include the contacts with a name
containing *Muflone*, excluding the records with ID 193623.

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

If you only need to **find the record IDs** for the matching records you can
use the [search] method, which will only return the record IDs matching the
search criteria.

```python
data = model_partner.search(filters=filters)
```

If you only need to know the **number of records matching** the filters then
the [count] method will do so:

```python
count = model_partner.count(filters=filters)
```

If you need to find and read the records data you can use the method [filter]
which will **return a list of dictionaries**
with all the records details.

```python
data = model_partner.filter(filters=filters)
```

The method [first] is very similar to the [filter] method but it will only
**return the first record** as a dictionary or None if no records can be found.

```python
data = model_partner.first(filters=filters)
```

[Model]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}
[all]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-all
[Active records]: {% link _pyodoo/english/docs/active.md %}
[get]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-get
[get_many]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-get_many
[find]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-find
[Filters]: {% link _pyodoo/english/docs/filters.md %}
[Filter]: {% link _pyodoo/english/docs/pyodoo/filter.md %}
[BooleanOperator]: {% link _pyodoo/english/docs/pyodoo/boolean_operator.md %}
[search]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-search
[filter]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-filter
[first]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-first
[count]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-count
