---
layout: examples
order: 602
depth: 2
title: Utilizzo di base
---
# Connessione e autenticazione

Prima di accedere a un modello è necessario istanziare un oggetto [Model] ed
eseguire l'autenticazione utilizzando utente e password.

Si prega di fare riferimento alla pagina [autenticazione].

---
# Leggere dati da un modello

È possibile leggere i dati da un oggetto Model utilizzando i metodi *get* o
*get_many*.

Un record singolo può essere letto usando il metodo [get]:

```python
partner = model_partner.get(entity_id=2)
```

Record multipli possono essere letti usando il metodo [get_many]:

```python
partners = model_partner.get_many(entity_ids=(2, 3, 4))
```

---
# Leggere dati da un altro modello

Da qualsiasi modello è possibile ottenere un riferimento a un modello differente
utilizzando il metodo [get_model] senza dover fornire server, database, utente
e password.

```python
model_countries = model_partner.get_model(model_name='res.country',
                                          authenticate=True)
country = model_countries.get(entity_id=10)
```

---
# Leggere tutti i dati da un modello

In caso di necessità di leggere tutti i dati da un'istanza Model è possibile
usare il metodo [all]:

```python
countries = model_countries.all()
```

---
# Limitare il numero di campi restituiti

Alcuni metodi consentono di specificare un argomento *fields* per limitare il
numero di campi restituito per ciascun record, riducendo la quantità di dati
trasferiti.
Il campo chiamato *id* sarà sempre restituito.

```python
partners = model_partner.get_many(entity_ids=(2, 3, 4),
                                  fields=('name', 'country', 'lang')) 
pprint.pprint(partners)
```

Restituirà soltanto i campi selezionati:

```text
[{'country_id': [110, 'Italy'], 'id': 2, 'lang': 'it_IT', 'name': 'OdooBot'},
 {'country_id': [110, 'Italy'], 'id': 3, 'lang': 'en_GB', 'name': 'Admin'},
 {'country_id': False, 'id': 4, 'lang': 'it_IT', 'name': 'default user'}]
```

Lo stesso può essere applicato ad altri metodi:

```python
countries = model_countries.all(fields=('id', 'name'))
```

---
# Creare un nuovo record

Per creare un nuovo record è possibile semplicemente passare i valori desiderati
con un oggetto dizionario al metodo [create].

```python
new_partner_id = model_partner.create(values={'name': 'Muflone',
                                              'lang': 'en_GB',
                                              'country_id': 110})
```

---
# Aggiornare record esistenti

È possibile aggiornare uno o più record assieme utilizzando un oggetto dizionario
con i nuovi valori e il metodo [update].

```python
model_partner.update(new_partner_id, values={'country_id': 50})
```

---
# Cancellare i record esistenti

Per rimuovere alcuni record è possibile usare il metodo [delete]. 

```python
model_partner.delete(new_partner_id)
```

[Model]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}
[autenticazione]: {% link _pyodoo/italian/docs/authentication.md %}
[get]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#metodo-get
[get_many]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#metodo-get_many
[get_model]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#metodo-get_model
[all]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#metodo-all
[create]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#metodo-create
[update]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#metodo-update
[delete]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#metodo-delete
