---
layout: index
order: 100
title: Introduzione
---

**PyOdoo** è una libreria Python per realizzare una API comune per interagire
con i server Odoo al fine di operare utilizzando le API XML RPC per cercare,
ottenere, creare, aggiornare, eliminare dati dai modelli di Odoo e anche di
eseguire metodi nei modelli.

# Utilizzo da codice Python

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

Il codice precedente stabilirà una connessione con l'istanza Odoo indicata
utilizzando le credenziali fornite, e quindi otterà un massimo di 2 contatti
aventi il nome Muflone, estraendo soltanto i campi id, name e country_id e
stamperà i risultati:

```
[{'country_id': [110, 'Italia'], 'id': 312819, 'name': 'Muflone Ovinis'},
 {'country_id': [110, 'Italia'], 'id': 312818, 'name': 'Muflone Clone'}]
```

Gli oggetti Model hanno numerosi metodi con cui lavorare, alcuni dei quali
useranno una lista di oggetti Filter mentre altri potrebbero usare uno o più
identificatori di entità (il numero ID del record).

Per maggiori informazioni fare riferimento alla pagina [Documentazione]
e per alcuni esempi di utilizzo vedi la pagina [Esempi].

[Documentazione]: {% link _pyodoo/italian/docs/index.md %}
[Esempi]: {% link _pyodoo/italian/examples/index.md %}
