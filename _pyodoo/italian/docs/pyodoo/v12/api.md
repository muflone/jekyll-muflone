---
layout: documentation
order: 551
depth: 2
title: Api
nav_prefix: Package pyodoo.v12
---

# Classe Api
{: .no_toc }

La classe **Api** è utilizzata per interfacciarsi con Odoo e si occupa di
eseguire i metodi attraverso l'interfaccia XML-RPC.

Molti dei metodi della classe [Model] utilizzano altri metodi della classe Api.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

- TOC
{: toc }

---
## Costruttore

```python
class Api(model_name: str,
          endpoint: str,
          database: str,
          username: str,
          password: str,
          language: str = None)
```

#### Parametri

- **model_name**: nome del modello a cui accedere.
- **endpoint**: URL dell'endpoint di Odoo.
- **database**: nome del database di Odoo da utilizzare.
- **username**: nome dell'utente di Odoo da utilizzare.
- **password**: password dell'utente di Odoo da utilizzare.
- **language**: lingua predefinita da utilizzare per i campi traducibili.

#### Esempio di utilizzo

```python
import pyodoo.v12

api = pyodoo.v12.Api(model_name='res.partner',
                     endpoint='https://demo.odoo.com',
                     database='demo_saas',
                     username='muflone',
                     password='mysecret',
                     language='it_IT')
```

Definisce l'accesso all'istanza di Odoo all'indirizzo https://demo.odoo.com sul
database demo_saas, utilizzando le credenziali fornite e la lingua italiana per
i campi traducibili.

Il modello res.partner sarà utilizzato per le operazioni di lettura, scrittura,
creazione e modifica dei dati.

---

## Metodo authenticate

```python
Api.authenticate()
```

Il metodo **authenticate** esegue l'autenticazione della sessione usando
database, utente and password.

#### Restituisce

- In caso di avvenuta autenticazione restituisce l'identificativo numerico
dell'utente autenticato.
- In caso di mancata autenticazione restituisce il valore False.

#### Esempio di utilizzo

```python
uid = api.authenticate()
```

---

## Metodo build_endpoint

```python
Api.build_endpoint(method: str)
```

Il metodo **build_endpoint** restituisce l'URL dell'endpoint per il metodo
richiesto.

Generalmente non è necessario richiamare questo metodo utilizzato dal metodo
*get_proxy*.

#### Parametri

- **method**: metodo remoto da utilizzare

#### Restituisce

- L'URL completo dell'endpoint e del metodo richiesti.

#### Esempio di utilizzo

```python
url = api.build_endpoint(method='xmlrpc/2/object')
```

---

## Metodo get_proxy

```python
Api.get_proxy(method: str)
```

Il metodo **get_proxy** restituisce un oggetto ServerProxy per eseguire comandi
attraverso XML-RPC.

Generalmente non è necessario richiamare questo metodo utilizzato dal metodo
*get_proxy_object*.

#### Parametri

- **method**: metodo remoto da utilizzare

#### Restituisce

- Un oggetto ServerProxy che punta all'endpoint per il metodo richiesto.

#### Esempio di utilizzo

```python
proxy = api.get_proxy(method='xmlrpc/2/object')
```

---

## Metodo get_proxy_object

```python
Api.get_proxy_object(method: str)
```

Il metodo **get_proxy_object** restituisce un oggetto ServerProxy per l'endpoint
standard *xmlrpc/2/object* di Odoo.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*execute*.

#### Parametri

- **method**: metodo remoto da utilizzare

#### Restituisce

- Un oggetto ServerProxy che punta all'endpoint standard XML-RPC di Odoo.

#### Esempio di utilizzo

```python
proxy = api.get_proxy(method='xmlrpc/2/object')
```

---

## Metodo statico explode_filter

```python
Api.explode_filter(filters: list[Union[BooleanOperator, Filter, str]])
```

Il metodo statico **explode_filter** è statico e può essere richiamato sia su
oggetti Api che sulla classe stessa con Api.explode_filter e si occupa di
convertire una lista di oggetti *Filter* e i valori *BooleanOperator* in una
lista di liste con i filtri esplosi, nel formato utilizzando da Odoo per la
selezione dei domini.

#### Parametri

- **filters**: lista di oggetti *Filter* o *BooleanOperator* da combinare

#### Restituisce

- Una lista di liste contententi stringhe o liste prodotta dal metodo explode
  di *[Filter]*.

#### Esempio di utilizzo

```python
results = api.explode_filter(
  filters=[pyodoo.BooleanOperator.AND,
           pyodoo.Filter(field='firstname',
                         compare_type=pyodoo.CompareType.EQUAL,
                         value='Muflone'),
           pyodoo.Filter(field='lastname',
                         compare_type=pyodoo.CompareType.EQUAL,
                         value='Ovinis'),
]))
```

---

## Metodo do_execute

```python
Api.do_execute(method_name: str,
               args: list[Any],
               kwargs: dict[str, Any])
```

Il metodo **do_execute** richiama il metodo scelto con la lista di argomenti,
per eseguire il comando remoto sul server XML-RPC.

Generalmente non è necessario richiamare questo metodo, utilizzato dai metodi
*do_read*, *do_create* e altri.

#### Parametri

- **method**: metodo remoto da utilizzare
- **args**: lista di argomenti da passare al metodo per valore
- **kwargs**: lista di argomenti da passare al metodo con nome e valore

#### Restituisce

- Il risultato della chiamata al metodo remoto XML-RPC.

#### Esempio di utilizzo

```python
results = api.do_execute(method_name='read',
                         args=[entity_ids],
                         kwargs=options)
```

---

## Metodo do_read

```python
Api.do_read(entity_id: int,
            options: dict[str, Any])
```

Il metodo **do_read** esegue la lettura di un record specifico identificato dal
suo *entity_id*, con le opzioni indicate e restituisce il risultato della
lettura.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*get* della classe [Model].

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da leggere
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- Il risultato della lettura del record indicato.

#### Esempio di utilizzo

```python
results = api.do_read(entity_id=123)
```

---

## Metodo do_read_many

```python
Api.do_read_many(entity_ids: list[int],
                 options: dict[str, Any])
```

Il metodo **do_read_many** esegue la lettura dei record specifici identificati
dai loro *entity_ids*, con le opzioni indicate e restituisce il risultato della
lettura.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*get_many* della classe [Model].

#### Parametri

- **entity_ids**: lista degli identificativi degli elementi da leggere
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- Il risultato della lettura dei record indicati.

#### Esempio di utilizzo

```python
results = api.do_read_many(entity_ids=[1, 2, 3])
```

---

## Metodo do_fields_get

```python
Api.do_fields_get(fields: list[str],
                  options: dict[str, Any])
```

Il metodo **do_fields_get** ottiene l'elenco dei campi presenti nel modello e
filtrati dalla lista *fields* per limitare il risultato.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*get_fields* della classe [Model].

#### Parametri

- **fields**: lista dei campi da includere
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- Un dizionario con tutti i campi presenti o indicati, con i loro tipi e
specifiche del modello.

#### Esempio di utilizzo

```python
results = api.get_fields(fields=['id', 'firstname', 'lastname'])
```

---

## Metodo do_search

```python
Api.do_search(filters: list[Union[BooleanOperator, Filter, str]],
              options: dict[str, Any])
```

Il metodo **do_search** esegue la ricerca dei record utilizzando la lista dei
filtri specificata in *filters*, con le opzioni indicate e restituisce il
risultato della ricerca.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*find* della classe [Model].

#### Parametri

- **filters**: lista di oggetti *Filter* o *BooleanOperator* per eseguire la
  ricerca
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- Una lista di interi identificativi i record trovati dalla ricerca.

#### Esempio di utilizzo

```python
results = api.do_search(
  filters=[pyodoo.BooleanOperator.AND,
           pyodoo.Filter(field='firstname',
                         compare_type=pyodoo.CompareType.EQUAL,
                         value='Muflone'),
           pyodoo.Filter(field='lastname',
                         compare_type=pyodoo.CompareType.EQUAL,
                         value='Ovinis'),
          ])
```

---

## Metodo do_search_count

```python
Api.do_search_count(filters: list[Union[BooleanOperator, Filter, str]],
                    options: dict[str, Any])
```

Il metodo **do_search_count** esegue la ricerca dei record utilizzando la lista
dei filtri specificata in *filters*, con le opzioni indicate e restituisce il
numero di record trovati dalla ricerca.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*count* della classe [Model].

#### Parametri

- **filters**: lista di oggetti *Filter* o *BooleanOperator* per eseguire la
  ricerca
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- Il conteggio dei record trovati dalla ricerca.

#### Esempio di utilizzo

```python
results = api.do_search_count(
  filters=[pyodoo.BooleanOperator.AND,
           pyodoo.Filter(field='firstname',
                         compare_type=pyodoo.CompareType.EQUAL,
                         value='Muflone'),
           pyodoo.Filter(field='lastname',
                         compare_type=pyodoo.CompareType.EQUAL,
                         value='Ovinis'),
          ])
```

---

## Metodo do_search_read

```python
Api.do_search_read(filters: list[Union[BooleanOperator, Filter, str]],
                   options: dict[str, Any])
```

Il metodo **do_search_read** esegue la ricerca dei record utilizzando la lista
dei filtri specificata in *filters*, con le opzioni indicate e restituisce i
record trovati dalla ricerca.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*filter* della classe [Model].

#### Parametri

- **filters**: lista di oggetti *Filter* o *BooleanOperator* per eseguire la
  ricerca
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- Una lista di record trovati, con un dizionario per record trovato.

#### Esempio di utilizzo

```python
results = api.do_search_read(
  filters=[pyodoo.BooleanOperator.AND,
           pyodoo.Filter(field='firstname',
                         compare_type=pyodoo.CompareType.EQUAL,
                         value='Muflone'),
           pyodoo.Filter(field='lastname',
                         compare_type=pyodoo.CompareType.EQUAL,
                         value='Ovinis'),
          ])
```

---

## Metodo do_create

```python
Api.do_create(values: dict[str, Any],
              options: dict[str, Any])
```

Il metodo **do_create** è utilizzato per creare un nuovo record nel modello
utilizzando i valori specificati in *values*, con le opzioni indicate e
restituisce i record trovati dalla ricerca.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*create* della classe [Model].

#### Parametri

- **values**: dizionario con nomi e valori dei campi per creare il record
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- L'identificativo intero del nuovo record creato.

#### Esempio di utilizzo

```python
entity_id = api.do_create(values={'firstname': 'Muflone',
                                  'lastname': 'Ovinis})
```

---

## Metodo do_update

```python
Api.do_update(entity_id: Union[int, list[int]],
              values: dict[str, Any],
              options: dict[str, Any])
```

Il metodo **do_update** è utilizzato per aggiornare uno o più record indicati
da *entity_id* (può essere un unico record come numero intero oppure una lista
di identificativi in una lista di interi) utilizzando i valori specificati in
*values*, con le opzioni indicate e restituisce True se l'aggiornamento è
stato eseguito.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*update* della classe [Model].

#### Parametri

- **entity_id**: identificativi univoci degli elementi da aggiornare
- **values**: dizionario con nomi e valori dei campi per aggiornare il record
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- True se i record indicati sono stati aggiornati.

#### Esempio di utilizzo

```python
entity_id = api.do_update(entity_id=[1, 2],
                          values={'firstname': 'Muflone',
                                  'lastname': 'Ovinis})
```

---

## Metodo do_delete

```python
Api.do_delete(entity_id: Union[int, list[int]],
              options: dict[str, Any])
```

Il metodo **do_delete** è utilizzato per eliminare uno o più record indicati
da *entity_id* (può essere un unico record come numero intero oppure una lista
di identificativi in una lista di interi), con le opzioni indicate e restituisce
True se la cancellazione è stato eseguita.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*delete* della classe [Model].

#### Parametri

- **entity_id**: identificativi univoci degli elementi da eliminare
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- True se i record indicati sono stati eliminati.

#### Esempio di utilizzo

```python
entity_id = api.do_delete(entity_id=[1, 2])
```

---

## Metodo do_post_message

```python
Api.do_post_message(subtype: Union[str, int],
                    entity_id: int,
                    author_id: int,
                    subject: Union[str, bool],
                    body: str,
                    options: dict[str, Any])
```

Il metodo **do_post_message** è utilizzato per inviare un messaggio del tipo
[MessageSubType] indicato in *subtype* e legato al record identificato da
*entity_id*, con l'autore indicato da *author_id*, l'oggetto specificato in
*subject* e il messaggio contenuto in *body*, con le opzioni indicate e
restituisce l'identificativo del nuovo messaggio creato.

Generalmente non è necessario richiamare questo metodo, utilizzato dal metodo
*post_message* della classe [Model].

#### Parametri

- **subtype**: tipologia di messaggio della classe [MessageSubType]
- **entity_id**: identificativo univoco dell'elemento a cui inviare il
  messaggio
- **author_id**: identificativo univoco dell'utente che invia il messaggio
- **subject**: oggetto del messaggio da inviare
- **body**: corpo del messaggio da inviare
- **options**: dizionario con le opzioni da utilizzare

#### Restituisce

- L'identificativo intero del nuovo messaggio creato.

#### Esempio di utilizzo

```python
entity_id = api.do_post_message(subtype=MessageSubType.NOTE,
                                entity_id=123,
                                author_id=2,
                                subject='Prova',
                                body='Messaggio per il record 123')
```

---


[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
[Model]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}
[Filter]: {% link _pyodoo/italian/docs/pyodoo/filter.md %}
[MessageSubType]: {% link _pyodoo/italian/docs/pyodoo/message_subtype.md %}