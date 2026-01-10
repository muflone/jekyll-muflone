---
layout: examples
order: 602
depth: 2
title: Basic usage
---
# Connect and authenticate

Before accessing a model you need to instance a [Model] object and authenticate
using valid username and password.

Please refer to the [authentication] page.

---
# Read data from the model

You can read the data from the model object using the methods *get* or
*get_many*.

A single record can be read using the method [get]:

```python
partner = model_partner.get(entity_id=2)
```

Multiple records can be read at once using the method [get_many]:

```python
partners = model_partner.get_many(entity_ids=(2, 3, 4))
```

---
# Get data from another model

From any model you can get a reference to a different model using the
method [get_model] without having to provide the server, database, username
and password.

```python
model_countries = model_partner.get_model(model_name='res.country',
                                          authenticate=True)
country = model_countries.get(entity_id=10)
```

---
# Get all data from a model

If you need to read all the data at once from a Model instance you can use the
method [all]:

```python
countries = model_countries.all()
```

---
# Limit the number of returned fields

Some methods allow you to specify a *fields* argument to limit the number of
returned fields per each record, reducing the amount of transferred data.
The field called *id* will always be returned.

```python
partners = model_partner.get_many(entity_ids=(2, 3, 4),
                                  fields=('name', 'country', 'lang')) 
pprint.pprint(partners)
```

Will return only the selected fields:

```text
[{'country_id': [110, 'Italy'], 'id': 2, 'lang': 'it_IT', 'name': 'OdooBot'},
 {'country_id': [110, 'Italy'], 'id': 3, 'lang': 'en_GB', 'name': 'Admin'},
 {'country_id': False, 'id': 4, 'lang': 'it_IT', 'name': 'default user'}]
```

The same can be also applied for other methods:

```python
countries = model_countries.all(fields=('id', 'name'))
```

---
# Create a new record

To create a new record you can simply pass the desired values with a dictionary
object to the method [create].

```python
new_partner_id = model_partner.create(values={'name': 'Muflone',
                                              'lang': 'en_GB',
                                              'country_id': 110})
```

---
# Update existing records

You can update one or many records at once using a dictionary object with the
new values and the method [update].

```python
model_partner.update(new_partner_id, values={'country_id': 50})
```

---
# Delete existing records

When you need to remove some records you can use the method [delete]. 

```python
model_partner.delete(new_partner_id)
```

[Model]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}
[authentication]: {% link _pyodoo/english/docs/authentication.md %}
[get]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-get
[get_many]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-get_many
[get_model]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-get_model
[all]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-all
[create]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-create
[update]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-update
[delete]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-delete
