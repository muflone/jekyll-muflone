---
layout: documentation
order: 554
depth: 2
title: SqlExcelQuery
---

# Classe SqlExcelQuery
{: .no_toc }

La classe **SqlExcelQuery** è utilizzata per eseguire una query SQL utilizzando
il modello `sql.excel.pdf` e questo modello è necessario affinché la
classe funzioni.

Si tratta di un modulo non standard di Odoo ma fornito da applicazioni di
terze parti e andrà installato per utilizzare questa classe.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

- TOC
{: toc }

---
## Costruttore

```python
class SqlExcelQuery(name: str,
                    category: str,
                    endpoint: str,
                    database: str,
                    username: str,
                    password: str,
                    language: str = None)
```

#### Parametri

- **name**: nome della query SQL da creare o utilizzare.
- **category**: nome della categoria della query da creare o utilizzare.
- **endpoint**: URL dell'endpoint di Odoo.
- **database**: nome del database di Odoo da utilizzare.
- **username**: nome dell'utente di Odoo da utilizzare.
- **password**: password dell'utente di Odoo da utilizzare.
- **language**: lingua predefinita da utilizzare per i campi traducibili.

#### Esempio di utilizzo

```python
import pyodoo.v12

query = pyodoo.v12.SqlExcelQuery(name='SQL Excel Query Demo',
                                 category='PyOdoo Demo',
                                 endpoint='https://demo.odoo.com',
                                 database='demo_saas',
                                 username='muflone',
                                 password='mysecret',
                                 language='it_IT')
```

Accede all'istanza di Odoo all'indirizzo https://demo.odoo.com sul database
demo_saas, utilizzando le credenziali fornite e la lingua italiana per
i campi traducibili e richiama o crea la query SQL di nome
*SQL Excel Query Demo* nella categoria `PyOdoo Demo`.

---

## Metodo statico is_available

```python
SqlExcelQuery.is_available(endpoint: str,
                           database: str,
                           username: str,
                           password: str,
                           language: str = None)
```

Il metodo statico **is_available** è statico e può essere richiamato sia su
oggetti SqlExcelQuery che sulla classe stessa con SqlExcelQuery.is_available e
si occupa di verificare se il modello `sql.excel.pdf` sia disponibile e
restituirà il valore True se il modello è stato trovato, altrimenti restituirà
il valore False.

#### Parametri

- **endpoint**: URL dell'endpoint di Odoo.
- **database**: nome del database di Odoo da utilizzare.
- **username**: nome dell'utente di Odoo da utilizzare.
- **password**: password dell'utente di Odoo da utilizzare.
- **language**: lingua predefinita da utilizzare per i campi traducibili.

#### Restituisce

- True se il modello `sql.excel.pdf` è stato trovato.
- False se il modello `sql.excel.pdf` non risulta disponibile.

#### Esempio di utilizzo

```python
print(SqlExcelQuery.is_available(endpoint='https://demo.odoo.com',
                                 database='demo_saas',
                                 username='muflone',
                                 password='mysecret',
                                 language='it_IT')
```

---

## Proprietà name

La proprietà **name** restituisce il nome della query dell'oggetto
SqlExcelQuery.

#### Restituisce

- Il nome della query usata dall'oggetto SqlExcelQuery.

#### Esempio di utilizzo

```python
print(query.name)
```

---

## Proprietà language

La proprietà **language** restituisce e assegna la lingua per l'oggetto
SqlExcelQuery.

#### Restituisce

- La lingua attuale dall'oggetto SqlExcelQuery.

#### Esempio di utilizzo

```python
print(query.language)
query.language = 'it_IT'
```

---

## Proprietà id

La proprietà **id** restituisce l'identificativo univoco della query
dell'oggetto SqlExcelQuery.

#### Restituisce

- L'identificativo univoco dall'oggetto SqlExcelQuery.

#### Esempio di utilizzo

```python
print(query.id)
```

---

## Metodo get_sql

```python
SqlExcelQuery.get_code()
```

Il metodo **get_sql** restituisce il codice SQL dell'oggetto SqlExcelQuery.

#### Restituisce

- Il codice SQL della query dell'oggetto SqlExcelQuery.

#### Esempio di utilizzo

```python
print(query.get_sql())
```

---

## Metodo set_sql

```python
SqlExcelQuery.set_sql(text: str)
```

Il metodo **set_sql** imposta il codice SQL per l'oggetto SqlExcelQuery.

Il parametro *text* corrisponde al codice SQL da salvare.

#### Parametri

- **text**: codice SQL da impostare.

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
query.set_sql(text='SELECT * FROM res_partner LIMIT 100')
```

---

## Metodo set_draft

```python
SqlExcelQuery.set_draft()
```

Il metodo **set_draft** imposta il record SqlExcelQuery a bozza per la modifica.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
query.set_draft()
```

---

## Metodo validate

```python
SqlExcelQuery.validate()
```

Il metodo **validate** valida il codice SQL dell'oggetto SqlExcelQuery.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
query.validate()
```

---

## Metodo get_state

```python
SqlExcelQuery.get_state()
```

Il metodo **get_state** legge lo stato dell'oggetto SqlExcelQuery.

#### Restituisce

- Lo stato dell'oggetto SqlExcelQuery.

#### Esempio di utilizzo

```python
query.set_draft()
print(query.get_state())
query.validate()
print(query.get_state())
```

---

## Metodo get_active

```python
SqlExcelQuery.get_active()
```

Il metodo **get_active** legge lo stato `active` dell'oggetto SqlExcelQuery.

#### Restituisce

- Lo stato `active` dell'oggetto SqlExcelQuery.

#### Esempio di utilizzo

```python
print(query.get_active())
```

---

## Metodo set_active

```python
SqlExcelQuery.set_active(active: bool)
```

Il metodo **set_active** imposta lo stato `active` dell'oggetto SqlExcelQuery.

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
print(query.set_active(active=False))
print(query.set_active(active=True))
```

---

## Metodo execute

```python
SqlExcelQuery.execute()
```

Il metodo **execute** esegue la query SQL dell'oggetto SqlExcelQuery.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
query.set_sql(text='SELECT\n  *\nFROM res_partner\nLIMIT 100')
query.execute()
```

---

## Metodo clear

```python
SqlExcelQuery.clear()
```

Il metodo **clear** pulisce il risultato delle precedenti esecuzioni
dell'oggetto SqlExcelQuery.

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
query.clear()
```

---

## Metodo delete

```python
SqlExcelQuery.delete()
```

Il metodo **delete** elimina il record dell'oggetto SqlExcelQuery.

#### Restituisce

- True se il record è stato eliminato.

#### Esempio di utilizzo

```python
query.delete()
```

---

## Metodo get_file

```python
SqlExcelQuery.get_file()
```

Il metodo **get_file** recupera il file Excel dell'ultima esecuzione della
query SQL dell'oggetto SqlExcelQuery.

#### Restituisce

- Il contenuto binario del file Excel ottenuto.

#### Esempio di utilizzo

```python
query.execute()
data = query.get_file()
```

---

## Metodo get_data

```python
SqlExcelQuery.get_data()
```

Il metodo **get_data** estrae i dati dal file Excel dell'ultima esecuzione della
query SQL dell'oggetto SqlExcelQuery.

#### Restituisce

- Una lista di dizionari con i dati estratti dal file Excel ottenuto.

#### Esempio di utilizzo

```python
query.execute()
data = query.get_data()
```

---

## Metodo add_tag

```python
SqlExcelQuery.add_tag(tag_id: int)
```

Il metodo **add_tag** aggiunge il tag identificato da `tag_id` all'oggetto
SqlExcelQuery.

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
query.add_tag(tag_id=4)
```

---

## Metodo get_tags

```python
SqlExcelQuery.get_tags()
```

Il metodo **get_tags** recupera tutti i tag dal modello `sql.tags` da associare
all'oggetto SqlExcelQuery mediante il metodo **add_tag**.

#### Restituisce

- Una lista di dizionari con i dati sui tag.

#### Esempio di utilizzo

```python
print(query.get_tags())
```

---


[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
