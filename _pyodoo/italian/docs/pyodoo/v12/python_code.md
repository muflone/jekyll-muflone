---
layout: documentation
order: 553
depth: 2
title: PythonCode
---

# Classe PythonCode
{: .no_toc }

La classe **PythonCode** è utilizzata per eseguire del codice Python all'interno
del modello `execute.python.code` e questo modello è necessario affinché la
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
class PythonCode(name: str,
                 endpoint: str,
                 database: str,
                 username: str,
                 password: str,
                 language: str = None)
```

#### Parametri

- **name**: nome dello script da creare o utilizzare.
- **endpoint**: URL dell'endpoint di Odoo.
- **database**: nome del database di Odoo da utilizzare.
- **username**: nome dell'utente di Odoo da utilizzare.
- **password**: password dell'utente di Odoo da utilizzare.
- **language**: lingua predefinita da utilizzare per i campi traducibili.

#### Esempio di utilizzo

```python
import pyodoo.v12

script = pyodoo.v12.PythonCode(name='Python Script Demo',
                               endpoint='https://demo.odoo.com',
                               database='demo_saas',
                               username='muflone',
                               password='mysecret',
                               language='it_IT')
```

Accede all'istanza di Odoo all'indirizzo https://demo.odoo.com sul database
demo_saas, utilizzando le credenziali fornite e la lingua italiana per
i campi traducibili e richiama o crea lo script di nome
*Python Script Demo*.

---

## Metodo statico is_available

```python
PythonCode.is_available(endpoint: str,
                        database: str,
                        username: str,
                        password: str,
                        language: str = None)
```

Il metodo statico **is_available** è statico e può essere richiamato sia su
oggetti PythonCode che sulla classe stessa con PythonCode.is_available e si
occupa di verificare se il modello `execute.python.code` sia disponibile e
restituirà il valore True se il modello è stato trovato, altrimenti restituirà
il valore False.

#### Parametri

- **endpoint**: URL dell'endpoint di Odoo.
- **database**: nome del database di Odoo da utilizzare.
- **username**: nome dell'utente di Odoo da utilizzare.
- **password**: password dell'utente di Odoo da utilizzare.
- **language**: lingua predefinita da utilizzare per i campi traducibili.

#### Restituisce

- True se il modello `execute.python.code` è stato trovato.
- False se il modello `execute.python.code` non risulta disponibile.

#### Esempio di utilizzo

```python
print(PythonCode.is_available(endpoint='https://demo.odoo.com',
                              database='demo_saas',
                              username='muflone',
                              password='mysecret',
                              language='it_IT')
```

---

## Proprietà name

La proprietà **name** restituisce il nome dello script dell'oggetto PythonCode.

#### Restituisce

- Il nome dello script usato dall'oggetto PythonCode.

#### Esempio di utilizzo

```python
print(script.name)
```

---

## Proprietà id

La proprietà **id** restituisce l'identificativo univoco dello script
dell'oggetto PythonCode.

#### Restituisce

- L'identificativo univoco dall'oggetto PythonCode.

#### Esempio di utilizzo

```python
print(script.id)
```

---

## Metodo get_code

```python
PythonCode.get_code()
```

Il metodo **get_code** restituisce il codice Python dell'oggetto PythonCode.

#### Restituisce

- Il codice Python dello script dell'oggetto PythonCode.

#### Esempio di utilizzo

```python
print(script.get_code())
```

---

## Metodo set_code

```python
PythonCode.set_code(text: str)
```

Il metodo **set_code** imposta il codice Python per l'oggetto PythonCode.

Il parametro *text* corrisponde al codice Python da salvare.

#### Parametri

- **text**: codice Python da impostare.

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
script.set_code(text='import sys\nresult = sys.version')
```

---

## Metodo execute

```python
PythonCode.execute()
```

Il metodo **execute** esegue il codice Python dell'oggetto PythonCode.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
script.set_code(text='import sys\nresult = sys.version')
script.execute()
```

---

## Metodo get_result

```python
PythonCode.get_result()
```

Il metodo **get_result** legge il risultato dell'ultima esecuzione dello script
Python dall'oggetto PythonCode.

Dopo l'esecuzione del metodo `execute` è possibile richiamare il metodo
`get_result` per ottenere il risultato dell'esecuzione.

#### Restituisce

- Il risultato dell'ultima esecuzione dello script Python.

#### Esempio di utilizzo

```python
script.set_code(text='import sys\nresult = sys.version')
script.execute()
print(script.get_result())
```

---

## Metodo delete

```python
PythonCode.delete()
```

Il metodo **delete** elimina il record dell'oggetto PythonCode.

#### Restituisce

- True se il record è stato eliminato.

#### Esempio di utilizzo

```python
script.delete()
```

---


[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
