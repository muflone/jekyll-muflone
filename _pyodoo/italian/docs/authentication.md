---
layout: documentation
order: 511
depth: 2
title: Autenticazione
---
# Connessione e autenticazione

Per accedere a un modello di Odoo è possibile semplicemente istanziare un
oggetto **[Model]** passando il nome del modello, l'URL del server, il nome del
db, l'utente e la password per l'autenticazione.

Specificando un valore per *language* i valori ritornati saranno tradotti nel
codice di lingua specificato.

Fornendo il valore **True** all'argomento *authenticate* l'autenticazione sarà
eseguita automaticamente, altrimenti sarà necessario chiamare esplicitamente
il metodo [authenticate].

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
```

[Model]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}
[authenticate]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#metodo-authenticate
