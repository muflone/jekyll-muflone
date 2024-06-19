---
layout: documentation
order: 552
depth: 2
title: Model
---

# Classe Model
{: .no_toc }

La classe **Model** è utilizzata per interfacciarsi con un modello di Odoo e
si occupa di eseguire i metodi attraverso l'interfaccia XML-RPC.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

- TOC
{: toc }

---
## Costruttore

```python
class Model(model_name: str,
            endpoint: str,
            database: str,
            username: str,
            password: str,
            language: str = None,
            authenticate: bool = False)
```

#### Parametri

- **model_name**: nome del modello a cui accedere.
- **endpoint**: URL dell'endpoint di Odoo.
- **database**: nome del database di Odoo da utilizzare.
- **username**: nome dell'utente di Odoo da utilizzare.
- **password**: password dell'utente di Odoo da utilizzare.
- **language**: lingua predefinita da utilizzare per i campi traducibili.
- **authenticate**: determina se autenticare l'utente automaticamente.

#### Esempio di utilizzo

```python
import pyodoo.v12

model = pyodoo.v12.Model(model_name='res.partner',
                         endpoint='https://demo.odoo.com',
                         database='demo_saas',
                         username='muflone',
                         password='mysecret',
                         language='it_IT',
                         authenticate=True)
```

Definisce l'accesso all'istanza di Odoo all'indirizzo https://demo.odoo.com sul
database demo_saas, utilizzando le credenziali fornite e la lingua italiana per
i campi traducibili.

Il modello res.partner sarà utilizzato per le operazioni di lettura, scrittura,
creazione e modifica dei dati.

---

## Proprietà model_name

La proprietà **model_name** restituisce il nome del modello dell'oggetto Model.

#### Restituisce

- Il nome del modello usato dall'oggetto Model.

#### Esempio di utilizzo

```python
print(model.model_name)
```

---

## Proprietà language

La proprietà **language** imposta e restituisce la lingua usata dall'oggetto
Model per la lettura e scrittura di campi traducibili.

#### Restituisce

- La lingua usata dall'oggetto Model.

#### Esempio di utilizzo

```python
print(model.language)
model.language = 'it_IT'
```

---

## Proprietà partner_id

La proprietà **partner_id** restituisce l'ID del partner collegato
all'utente autenticato.

#### Restituisce

- L'identificativo del partner dell'utente autenticato.

#### Esempio di utilizzo

```python
print(model.partner_id)
```

---

## Proprietà partner_name

La proprietà **partner_name** restituisce il nome del partner collegato
all'utente autenticato.

#### Restituisce

- Il nome del partner dell'utente autenticato.

#### Esempio di utilizzo

```python
print(model.partner_name)
```

---

## Proprietà uid

La proprietà **uid** restituisce l'ID univoco dell'utente autenticato.

#### Restituisce

- L'identificativo univoco dell'utente autenticato.

#### Esempio di utilizzo

```python
print(model.uid)
```

---

## Metodo authenticate

```python
Model.authenticate()
```

Il metodo **authenticate** esegue l'autenticazione della sessione usando
database, utente and password.

#### Restituisce

- In caso di avvenuta autenticazione restituisce l'identificativo numerico
dell'utente autenticato.
- In caso di mancata autenticazione restituisce il valore False.

#### Esempio di utilizzo

```python
uid = model.authenticate()
```

---

## Metodo get_model

```python
Model.get_model(model_name: str,
                authenticate: bool = False,
                use_existing_uid: bool = False)
```

Il metodo **get_model** restituisce un nuovo oggetto Model verso il modello
indicato da *model_name*.

Il parametro *authenticate* se impostato a True esegue nuovamente
l'autenticazione sul nuovo oggetto Model.

Il parametro *use_existing_uid* nel caso di mancata autenticazione passando il
parametro *authenticate* a False, salta l'autenticazione e utilizza lo stesso
User ID usato dall'oggetto Model.

#### Parametri

- **model_name**: nome del modello a cui accedere.
- **authenticate**: se impostato a True esegue l'autenticazione.
- **use_existing_uid** se impostato a True utilizza il precedente User ID.

#### Restituisce

- Un nuovo oggetto Model che punta al modello indicato da *model_name*.

#### Esempio di utilizzo

```python
model_products = model.get_model(model_name='product.product',
                                 authenticate=False,
                                 use_existing_uid=True)
```

---

## Metodo get_model_data_reference

```python
Model.get_model_data_reference(module_name: str,
                               value: str,
                               ignore_none_errors: bool = False)
```

Il metodo **get_model_data_reference** restituisce una riga dal modello
*ir.model.data* identificata dal suo ID esterno indicato dal parametro *value*.

#### Parametri

- **module_name**: nome del modulo da cui ottenere il riferimento
- **value**: nome dell'ID esterno ricercato
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Un dizionario con gli attributi della riga trovata.

#### Esempio di utilizzo

```python
results = model.get_model_data_reference(module_name='mail',
                                         value='mt_comment')
```

---

## Metodo get

```python
Model.get(entity_id: int,
          fields: tuple[str, ...] = None,
          options: dict[str, Any] = None,
          ignore_none_errors: bool = False)
```

Il metodo **get** esegue la lettura di un record specifico identificato dal
suo *entity_id*, con le opzioni indicate e restituisce il risultato della
lettura.

Saranno restituiti tutti i campi del recordo oppure solo quelli indicati dal
parametro *fields*.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da leggere
- **fields**: tupla con i nomi dei campi da restituire
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Il risultato della lettura del record indicato.

#### Esempio di utilizzo

```python
results = model.get(entity_id=123,
                    fields=('id', 'firstname', 'lastname'))
```

---

## Metodo get_many

```python
Model.get_many(entity_ids: list[int],
               fields: tuple[str, ...] = None,
               options: dict[str, Any],
               ignore_none_errors: bool = False)
```

Il metodo **get_many** esegue la lettura dei record specifici identificati
dai loro *entity_ids*, con le opzioni indicate e restituisce il risultato della
lettura.

Saranno restituiti tutti i campi del recordo oppure solo quelli indicati dal
parametro *fields*.

#### Parametri

- **entity_ids**: lista degli identificativi degli elementi da leggere
- **fields**: tupla con i nomi dei campi da restituire
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Il risultato della lettura dei record indicati.

#### Esempio di utilizzo

```python
results = model.get_many(entity_ids=[1, 2, 3],
                         fields=('id', 'firstname', 'lastname'))
```

---

## Metodo all

```python
Model.all(is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
          fields: list[str] = None,
          options: dict[str, Any] = None,
          limit: Optional[int] = None,
          offset: Optional[int] = None,
          order: Optional[str] = None,
          ignore_none_errors: bool = False)
```

Il metodo **all** esegue la lettura di tutti i record presenti nel modello,
includendo o escludendo quelli archiviati (active=False) in base al valore del
parametro *is_active*.

Saranno restituiti tutti i campi del recordo oppure solo quelli indicati dal
parametro *fields*.

#### Parametri

- **is_active**: filtro sui record archiviati
- **fields**: tupla col nome dei campi da includere
- **options**: dizionario con le opzioni da utilizzare
- **limit**: numero massimo di record da restituire
- **offset**: record iniziale da cui effettuare la lettura
- **order**: clausola di ordinamento, come usata in SQL, una stringa di nomi
  di campo seguiti dalla claudola *asc* o *desc* per identificare il tipo di
  ordinamento
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Il risultato della lettura dei record indicati.

#### Esempio di utilizzo

```python
results = model.all(is_active=ActiveStatusChoice.ACTIVE,
                    fields=['id', 'firstname', 'lastname'],
                    options=None,
                    limit=100,
                    offset=200,
                    order='firstname asc, lastname asc')
```

---

## Metodo find

```python
Model.find(entity_ids: list[int],
           is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
           fields: list[str] = None,
           options: dict[str, Any] = None,
           limit: Optional[int] = None,
           offset: Optional[int] = None,
           order: Optional[str] = None,
           ignore_none_errors: bool = False)
```

Il metodo **find** esegue la lettura dei record indicati dal parametro
*entity_ids*, includendo o escludendo quelli archiviati (active=False) in base
al valore del parametro *is_active*.

Saranno restituiti tutti i campi del recordo oppure solo quelli indicati dal
parametro *fields*.

#### Parametri

- **entity_ids**: lista degli identificativi degli elementi da leggere
- **is_active**: filtro sui record archiviati
- **fields**: tupla col nome dei campi da includere
- **options**: dizionario con le opzioni da utilizzare
- **limit**: numero massimo di record da restituire
- **offset**: record iniziale da cui effettuare la lettura
- **order**: clausola di ordinamento, come usata in SQL, una stringa di nomi
  di campo seguiti dalla claudola *asc* o *desc* per identificare il tipo di
  ordinamento
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Il risultato della lettura dei record indicati.

#### Esempio di utilizzo

```python
results = model.find(is_active=ActiveStatusChoice.ACTIVE,
                     fields=['id', 'firstname', 'lastname'],
                     options=None,
                     limit=100,
                     offset=200,
                     order='firstname asc, lastname asc')
```

---

## Metodo filter

```python
Model.filter(filters: list[Union[BooleanOperator, Filter, str]],
             is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
             fields: list[str] = None,
             options: dict[str, Any] = None,
             limit: Optional[int] = None,
             offset: Optional[int] = None,
             order: Optional[str] = None,
             ignore_none_errors: bool = False)
```

Il metodo **filter** esegue la ricerca dei record utilizzando la lista dei
filtri specificata in *filters*, includendo o escludendo quelli archiviati
(active=False) in base al valore del parametro *is_active*, con le opzioni
indicate e restituisce il risultato della ricerca.

Saranno restituiti tutti i campi del recordo oppure solo quelli indicati dal
parametro *fields*.

#### Parametri

- **filters**: lista di oggetti *Filter* o *BooleanOperator* per eseguire la
  ricerca
- **is_active**: filtro sui record archiviati
- **fields**: tupla col nome dei campi da includere
- **options**: dizionario con le opzioni da utilizzare
- **limit**: numero massimo di record da restituire
- **offset**: record iniziale da cui effettuare la lettura
- **order**: clausola di ordinamento, come usata in SQL, una stringa di nomi
  di campo seguiti dalla claudola *asc* o *desc* per identificare il tipo di
  ordinamento
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Una lista di interi identificativi i record trovati dalla ricerca.

#### Esempio di utilizzo

```python
results = model.filter(
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

## Metodo first

```python
Model.first(filters: list[Union[BooleanOperator, Filter, str]],
            is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
            fields: list[str] = None,
            options: dict[str, Any] = None,
            limit: Optional[int] = None,
            offset: Optional[int] = None,
            order: Optional[str] = None,
            ignore_none_errors: bool = False)
```

Il metodo **first** esegue la ricerca dei record utilizzando la lista dei
filtri specificata in *filters*, includendo o escludendo quelli archiviati
(active=False) in base al valore del parametro *is_active*, con le opzioni
indicate e restituisce il primo record come risultato della ricerca.

Saranno restituiti tutti i campi del recordo oppure solo quelli indicati dal
parametro *fields*.

#### Parametri

- **filters**: lista di oggetti *Filter* o *BooleanOperator* per eseguire la
  ricerca
- **is_active**: filtro sui record archiviati
- **fields**: tupla col nome dei campi da includere
- **options**: dizionario con le opzioni da utilizzare
- **limit**: numero massimo di record da restituire
- **offset**: record iniziale da cui effettuare la lettura
- **order**: clausola di ordinamento, come usata in SQL, una stringa di nomi
  di campo seguiti dalla claudola *asc* o *desc* per identificare il tipo di
  ordinamento
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Una lista di interi identificativi i record trovati dalla ricerca.

#### Esempio di utilizzo

```python
results = model.first(
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

## Metodo count

```python
Model.count(filters: list[Union[BooleanOperator, Filter, str]],
            is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
            options: dict[str, Any] = None,
            ignore_none_errors: bool = False)
```

Il metodo **count** esegue la ricerca dei record utilizzando la lista
dei filtri specificata in *filters*, includendo o escludendo quelli archiviati
(active=False) in base al valore del parametro *is_active*, con le opzioni
indicate e restituisce il numero di record trovati dalla ricerca.

#### Parametri

- **filters**: lista di oggetti *Filter* o *BooleanOperator* per eseguire la
  ricerca
- **is_active**: filtro sui record archiviati
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Il conteggio dei record trovati dalla ricerca.

#### Esempio di utilizzo

```python
results = model.count(
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

## Metodo search

```python
Model.search(filters: list[Union[BooleanOperator, Filter, str]],
             is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
             options: dict[str, Any] = None,
             limit: Optional[int] = None,
             offset: Optional[int] = None,
             order: Optional[str] = None,
             ignore_none_errors: bool = False)
```

Il metodo **search** esegue la ricerca dei record utilizzando la lista
dei filtri specificata in *filters*, includendo o escludendo quelli archiviati
(active=False) in base al valore del parametro *is_active*, con le opzioni
indicate e restituisce i record trovati dalla ricerca.

Rispetto il metodo *filter*, il metodo search restituisce soltanto gli
identificativi dei record trovati, non i dati stessi.

#### Parametri

- **filters**: lista di oggetti *Filter* o *BooleanOperator* per eseguire la
  ricerca
- **is_active**: filtro sui record archiviati
- **fields**: tupla col nome dei campi da includere
- **options**: dizionario con le opzioni da utilizzare
- **limit**: numero massimo di record da restituire
- **offset**: record iniziale da cui effettuare la lettura
- **order**: clausola di ordinamento, come usata in SQL, una stringa di nomi
  di campo seguiti dalla claudola *asc* o *desc* per identificare il tipo di
  ordinamento
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Una lista di interi identificativi i record trovati dalla ricerca.

#### Esempio di utilizzo

```python
results = model.search(
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

## Metodo create

```python
Model.create(values: dict[str, Any],
             options: dict[str, Any] = None,
             ignore_none_errors: bool = False)
```

Il metodo **create** è utilizzato per creare un nuovo record nel modello
utilizzando i valori specificati in *values*, con le opzioni indicate e
restituisce l'identificativo del record creato.

#### Parametri

- **values**: dizionario con nomi e valori dei campi per creare il record
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- L'identificativo intero del nuovo record creato.

#### Esempio di utilizzo

```python
entity_id = model.create(values={'firstname': 'Muflone',
                                 'lastname': 'Ovinis})
```

---

## Metodo update

```python
Model.update(entity_id: Union[int, list[int]],
             values: dict[str, Any],
             options: dict[str, Any] = None,
             ignore_none_errors: bool = False)
```

Il metodo **update** è utilizzato per aggiornare uno o più record indicati
da *entity_id* (può essere un unico record come numero intero oppure una lista
di identificativi in una lista di interi) utilizzando i valori specificati in
*values*, con le opzioni indicate e restituisce True se l'aggiornamento è
stato eseguito.

#### Parametri

- **entity_id**: identificativi univoci degli elementi da aggiornare
- **values**: dizionario con nomi e valori dei campi per aggiornare il record
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se i record indicati sono stati aggiornati.

#### Esempio di utilizzo

```python
entity_id = model.update(entity_id=[1, 2],
                         values={'firstname': 'Muflone',
                                 'lastname': 'Ovinis})
```

---

## Metodo delete

```python
Model.delete(entity_id: Union[int, list[int]],
             options: dict[str, Any] = None,
             ignore_none_errors: bool = False)
```

Il metodo **delete** è utilizzato per eliminare uno o più record indicati
da *entity_id* (può essere un unico record come numero intero oppure una lista
di identificativi in una lista di interi), con le opzioni indicate e restituisce
True se la cancellazione è stato eseguita.

#### Parametri

- **entity_id**: identificativi univoci degli elementi da eliminare
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se i record indicati sono stati eliminati.

#### Esempio di utilizzo

```python
entity_id = model.delete(entity_id=[1, 2])
```

---

## Metodo get_fields

```python
Model.get_fields(fields: list[str] = None,
                 attributes: list[str] = None,
                 options: dict[str, Any] = None,
                 ignore_none_errors: bool = False)
```

Il metodo **get_fields** è utilizzato per ottenere i campi presenti nel modello,
filtrati sulla base dei parametri *fields* e *attributes*, con le opzioni
indicate.

#### Parametri

- **fields**: lista col nome dei campi da includere
- **attributes**: lista col nome degli attributi da includere
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Un dizionario contenente tutti i campi identificati per il modello.

#### Esempio di utilizzo

```python
fields = model.get_fields(attributes=['string', 'type'])
```

---

## Metodo many_to_many_create

```python
Model.many_to_many_create(entity_id: int,
                          field: str,
                          values: dict[str, Any],
                          options: dict[str, Any] = None,
                          ignore_none_errors: bool = False)
```

Il metodo **many_to_many_create** crea un nuovo record con i valori
specificati dal parametro *values* e lo associa alla relazione
indicata dal campo *field* per il record identificato da *entity_id*,
con le opzioni indicate.

Il metodo viene utilizzato per creare un nuovo valore in una relazione
Many-to-Many.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da aggiornare
- **field**: nome del campo che identifica la relazione Many-to-Many
- **values**: dizionario con nomi e valori dei campi del record da creare
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
results = model.many_to_many_create(entity_id=123,
                                    field='child_ids',
                                    values={'firstname': 'Muflone',
                                            'lastname': 'Ovinis'})
```

---

## Metodo many_to_many_add

```python
Model.many_to_many_add(entity_id: int,
                       field: str,
                       related_id: int,
                       options: dict[str, Any] = None,
                       ignore_none_errors: bool = False)
```

Il metodo **many_to_many_add** aggiunge un record esistente identificato da
*related_id* alla relazione indicata dal campo *field* per il record
identificato da *entity_id*, con le opzioni indicate.

Il metodo viene utilizzato per aggiungere un valore esistente in una relazione
Many-to-Many.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da aggiornare
- **field**: nome del campo che identifica la relazione Many-to-Many
- **related_id**: identificativo univoco dell'elemento da aggiungere
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
results = model.many_to_many_add(entity_id=123,
                                 field='child_ids',
                                 related_id=321)
```

---

## Metodo many_to_many_update

```python
Model.many_to_many_update(entity_id: int,
                          field: str,
                          related_id: int,
                          values: dict[str, Any],
                          options: dict[str, Any] = None,
                          ignore_none_errors: bool = False)
```

Il metodo **many_to_many_update** aggiorna un record esistente identificato da
*related_id* nella relazione indicata dal campo *field* per il record
identificato da *entity_id*, con le opzioni indicate.

Il metodo viene utilizzato per aggiornare un valore esistente in una relazione
Many-to-Many.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da aggiornare
- **field**: nome del campo che identifica la relazione Many-to-Many
- **related_id**: identificativo univoco dell'elemento da aggiornare
- **values**: dizionario con nomi e valori dei campi del record da aggiornare
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
results = model.many_to_many_update(entity_id=123,
                                    field='child_ids',
                                    related_id=321,
                                    values={'firstname': 'Muflone',
                                            'lastname': 'Ovinis'})
```

---

## Metodo many_to_many_delete

```python
Model.many_to_many_delete(entity_id: int,
                          field: str,
                          related_id: int,
                          options: dict[str, Any] = None,
                          ignore_none_errors: bool = False)
```

Il metodo **many_to_many_delete** elimina un record esistente identificato da
*related_id* nella relazione indicata dal campo *field* per il record
identificato da *entity_id*, con le opzioni indicate.

Il metodo viene utilizzato per eliminare un valore esistente in una relazione
Many-to-Many e cancellare anche il record correlato.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da aggiornare
- **field**: nome del campo che identifica la relazione Many-to-Many
- **related_id**: identificativo univoco dell'elemento da eliminare
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
results = model.many_to_many_delete(entity_id=123,
                                    field='child_ids',
                                    related_id=321)
```

---

## Metodo many_to_many_remove

```python
Model.many_to_many_remove(entity_id: int,
                          field: str,
                          related_id: int,
                          options: dict[str, Any] = None,
                          ignore_none_errors: bool = False)
```

Il metodo **many_to_many_remove** rimuove un record esistente identificato da
*related_id* nella relazione indicata dal campo *field* per il record
identificato da *entity_id*, con le opzioni indicate.

Il metodo viene utilizzato per rimuovere un valore esistente in una relazione
Many-to-Many ma senza cancellare anche il record correlato che continuerà a
esistere nel modello relazionato e potrà essere aggiunto nuovamente in seguito.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da aggiornare
- **field**: nome del campo che identifica la relazione Many-to-Many
- **related_id**: identificativo univoco dell'elemento da rimuovere
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
results = model.many_to_many_remove(entity_id=123,
                                    field='child_ids',
                                    related_id=321)
```

---

## Metodo many_to_many_clear

```python
Model.many_to_many_clear(entity_id: int,
                         field: str,
                         options: dict[str, Any] = None,
                         ignore_none_errors: bool = False)
```

Il metodo **many_to_many_clear** rimuove tutti i record dalla relazione
indicata dal campo *field* per il record identificato da *entity_id*, con le
opzioni indicate.

Il metodo viene utilizzato per rimuovere tutti i valori esistenti in una
relazione Many-to-Many ma senza cancellare anche i record correlati che
continueranno a esistere nel modello relazionato e potranno essere aggiunti
nuovamente in seguito.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da aggiornare
- **field**: nome del campo che identifica la relazione Many-to-Many
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
results = model.many_to_many_clear(entity_id=123,
                                   field='child_ids')
```

---

## Metodo many_to_many_replace

```python
Model.many_to_many_replace(entity_id: int,
                           field: str,
                           related_ids: list[int],
                           options: dict[str, Any] = None,
                           ignore_none_errors: bool = False)
```

Il metodo **many_to_many_replace** sostituisce tutti i record esistenti nella
relazione indicata dal campo *field* con i record identificati da *related_ids*
per il record identificato da *entity_id*, con le opzioni indicate.

Il metodo viene utilizzato per rimuovere tutti i valori esistenti in una
relazione Many-to-Many e sostituirli con altri valori ma senza cancellare anche
i record correlati che continueranno a esistere nel modello relazionato e
potranno essere aggiunti nuovamente in seguito.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento da aggiornare
- **field**: nome del campo che identifica la relazione Many-to-Many
- **related_ids**: identificativi univoco degli elementi da inserire
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- True se il record è stato aggiornato.

#### Esempio di utilizzo

```python
results = model.many_to_many_replace(entity_id=123,
                                     field='child_ids',
                                     related_ids=[321, 322])
```

---

## Metodo execute

```python
Model.execute(method_name: str,
              args: list[Any],
              kwargs: dict[str, Any],
              ignore_none_errors: bool = False)
```

Il metodo **execute** richiama un metodo del modello, passando gli argomenti
posizionali *args* e gli argomenti con nome e valore *kwargs*. 

#### Parametri

- **method**: metodo remoto da utilizzare
- **args**: lista di argomenti da passare al metodo per valore
- **kwargs**: lista di argomenti da passare al metodo con nome e valore
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Il risultato della chiamata al metodo remoto.

#### Esempio di utilizzo

```python
results = model.execute(method_name='message_post',
                        args=[123],
                        kwargs={
                            'message_type': 'comment',
                            'subtype_id': model.get_message_subtype_id(
                                subtype=MessageSubType.COMMENT),
                            'subject': 'Some comment',
                            'body': 'Comment content'
                        })
```

---

## Metodo get_message_subtype_id

```python
Model.get_message_subtype_id(subtype: str,
                             ignore_none_errors: bool = False)
```

Il metodo **get_message_subtype_id** ottiene il riferimento al *subtype* per
il modulo *mail*, ovvero un valore usato dal metodo *post_message*.

Lo scopo di questo metodo è tenere una cache di questi valori e non doverli
recuperare ogni volta, per cui dopo la prima richiesta il valore verrà
conservato e non sarà necessario richiedere nuovamente il valore al modello
remoto.

#### Parametri

- **subtype**: nome del *subtype* da richiedere
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- Il valore del subtype dal modulo *mail*.

#### Esempio di utilizzo

```python
results = model.get_message_subtype_id(subtype=MessageSubType.COMMENT)
```

---

## Metodo post_message

```python
Model.post_message(subtype: Union[str, int],
                   entity_id: int,
                   author_id: int,
                   subject: Union[str, bool],
                   body: str,
                   options: dict[str, Any] = None,
                   ignore_none_errors: bool = False)
```

Il metodo **post_message** è utilizzato per inviare un messaggio del tipo
[MessageSubType] indicato in *subtype* e legato al record identificato da
*entity_id*, con l'autore indicato da *author_id*, l'oggetto specificato in
*subject* e il messaggio contenuto in *body*, con le opzioni indicate e
restituisce l'identificativo del nuovo messaggio creato.

#### Parametri

- **subtype**: tipologia di messaggio della classe [MessageSubType]
- **entity_id**: identificativo univoco dell'elemento a cui inviare il
  messaggio
- **author_id**: identificativo univoco dell'utente che invia il messaggio
- **subject**: oggetto del messaggio da inviare
- **body**: corpo del messaggio da inviare
- **options**: dizionario con le opzioni da utilizzare
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- L'identificativo intero del nuovo messaggio creato.

#### Esempio di utilizzo

```python
entity_id = model.do_post_message(subtype=MessageSubType.NOTE,
                                  entity_id=123,
                                  author_id=2,
                                  subject='Prova',
                                  body='Messaggio per il record 123')
```

---

## Metodo post_message_as_activity

```python
Model.post_message_as_activity(entity_id: int,
                               body: str,
                               author_id: int,
                               ignore_none_errors: bool = False)
```

Il metodo **post_message_as_activity** è utilizzato per inviare un messaggio
di tipo *Activity* al record identificato da *entity_id*.

Il metodo semplicemente richiama il metodo *post_message* fornendo il
*subtype* come *MessageSubType.ACTIVITY*.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento a cui inviare il
  messaggio
- **body**: corpo del messaggio da inviare
- **author_id**: identificativo univoco dell'utente che invia il messaggio
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- L'identificativo intero del nuovo messaggio creato.

#### Esempio di utilizzo

```python
entity_id = model.post_message_as_activity(entity_id=123,
                                           body='Activity per il record 123',
                                           author_id=2)
```

---

## Metodo post_message_as_comment

```python
Model.post_message_as_comment(entity_id: int,
                              body: str,
                              author_id: int,
                              ignore_none_errors: bool = False)
```

Il metodo **post_message_as_comment** è utilizzato per inviare un messaggio
di tipo *Comment* al record identificato da *entity_id*.

Il metodo semplicemente richiama il metodo *post_message* fornendo il
*subtype* come *MessageSubType.COMMENT*.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento a cui inviare il
  messaggio
- **body**: corpo del messaggio da inviare
- **author_id**: identificativo univoco dell'utente che invia il messaggio
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- L'identificativo intero del nuovo messaggio creato.

#### Esempio di utilizzo

```python
entity_id = model.post_message_as_comment(entity_id=123,
                                          body='Commento per il record 123',
                                          author_id=2)
```

---

## Metodo post_message_as_note

```python
Model.post_message_as_note(entity_id: int,
                           body: str,
                           author_id: int,
                           ignore_none_errors: bool = False)
```

Il metodo **post_message_as_note** è utilizzato per inviare un messaggio
di tipo *Note* al record identificato da *entity_id*.

Il metodo semplicemente richiama il metodo *post_message* fornendo il
*subtype* come *MessageSubType.NOTE*.

#### Parametri

- **entity_id**: identificativo univoco dell'elemento a cui inviare il
  messaggio
- **body**: corpo del messaggio da inviare
- **author_id**: identificativo univoco dell'utente che invia il messaggio
- **ignore_none_errors**: se impostato a True ignora l'errore di valore None

#### Restituisce

- L'identificativo intero del nuovo messaggio creato.

#### Esempio di utilizzo

```python
entity_id = model.post_message_as_note(entity_id=123,
                                       body='Nota per il record 123',
                                       author_id=2)
```

---


[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
[Model]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}
[Filter]: {% link _pyodoo/italian/docs/pyodoo/filter.md %}
[MessageSubType]: {% link _pyodoo/italian/docs/pyodoo/message_subtype.md %}
