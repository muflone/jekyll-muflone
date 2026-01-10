---
layout: documentation
order: 511
depth: 2
title: Authentication
---
# Connect and authenticate

To access an Odoo model you simply istance a **[Model]** object by passing the
model name, the server URL, the database name, username and passwords for
authentication.

If you specify a value for *language* the returned values will be translated
in the specified language code.

If you provide the value **True** for the argument *authenticate* the user
authentication will be executed automatically, otherwise you have to
explicitly call the method [authenticate].

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
```

[Model]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}
[authenticate]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-authenticate
