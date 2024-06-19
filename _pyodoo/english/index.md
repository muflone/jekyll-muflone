---
layout: index
order: 100
title: Introduction
---

**PyOdoo** is a Python library to build a common API to interact with any Odoo
server in order to operate using its XML RPC API to search, get, create, update,
delete data from the Odoo models and
also to execute methods on the models.

# Usage from Python code

```python
import os
import pprint
from pyodoo import CompareType, Filter
from pyodoo.v12 import Model

# Instance model object for Contacts
model = Model(model_name='res.partner',
              endpoint='https://my.odoo.muflone.com/',
              database='odoo_db',
              username='myuser',
              password='mypassword',
              language=None,
              authenticate=True)
# Get some records by partner name
results = model.filter(filters=[Filter(field='name',
                                       compare_type=CompareType.CONTAINS,
                                       value='Muflone')],
                       fields=('id', 'name', 'country_id'),
                       limit=2)
pprint.pprint(results)
```

The previous code will establish a connection with the indicated Odoo instance
using the provided credentials, next will get up to 2 contacts contaning the
name Muflone, extracting only the fields id, name and country_id and will
print the results:

```
[{'country_id': [110, 'Italia'], 'id': 312819, 'name': 'Muflone Ovinis'},
 {'country_id': [110, 'Italia'], 'id': 312818, 'name': 'Muflone Clone'}]
```

The Model objects have many methods to work with, some of them will use a list
of Filter objects while others may use one or more entities identifier
(the records ID number).

For more information please refer to the [Documentation]
page and for some usage examples please see the [Examples] page.

[Documentation]: {% link _pyodoo/english/docs/index.md %}
[Examples]: {% link _pyodoo/english/examples/index.md %}
