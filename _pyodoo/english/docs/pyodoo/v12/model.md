---
layout: documentation
order: 552
depth: 2
title: Model
---

# Class Model
{: .no_toc }

The **Model** class is used to interface with an Odoo model and
is responsible for executing methods through the XML-RPC interface.

To see some usage examples you can look at the page
[Usage examples].

- TOC
{: toc }

---
## Constructor

```python
class Model(model_name: str,
            endpoint: str,
            database: str,
            username: str,
            password: str,
            language: str = None,
            authenticate: bool = False)
```

#### Parameters

- **model_name**: name of the model to access.
- **endpoint**: URL of the Odoo endpoint.
- **database**: name of the Odoo database to use.
- **username**: name of the Odoo user to use.
- **password**: password of the Odoo user to use.
- **language**: default language to use for translatable fields.
- **authenticate**: determines whether to authenticate the user automatically.

#### Usage example

```python
import pyodoo.v12

model = pyodoo.v12.Model(model_name='res.partner',
                         endpoint='https://demo.odoo.com',
                         database='demo_saas',
                         username='muflone',
                         password='mysecret',
                         language='en_GB',
                         authenticate=True)
```

Defines access to the Odoo instance at https://demo.odoo.com on the
demo_saas database, using the credentials provided and the English language for
translatable fields.

The res.partner model will be used for reading, writing,
creating, and modifying data.

---

## Property model_name

The **model_name** property returns the name of the Model object's model.

#### Returns

- The name of the model used by the Model object.

#### Usage example

```python
print(model.model_name)
```

---

## Property language

The **language** property sets and returns the language used by the
Model object for reading and writing translatable fields.

#### Returns

- The language used by the Model object.

#### Usage example

```python
print(model.language)
model.language = 'it_IT'
```

---

## Property partner_id

The **partner_id** property returns the related partner ID for the
authenticated user.

#### Returns

- The partner identifier of the authenticated user.

#### Usage example

```python
print(model.partner_id)
```

---

## Property partner_name

The **partner_name** property returns the related partner name for the
authenticated user.

#### Returns

- The partner name of the authenticated user.

#### Usage example

```python
print(model.partner_name)
```

---

## Property uid

The **uid** property returns the authenticated user unique ID.

#### Returns

- The unique identifier of the authenticated user.

#### Usage example

```python
print(model.uid)
```

---

## Method authenticate

```python
Model.authenticate()
```

The **authenticate** method performs session authentication using
database, user, and password.

#### Returns

- If authentication is successful, it returns the numerical identifier
of the authenticated user.
- If authentication fails, it returns the value False.

#### Usage example

```python
uid = model.authenticate()
```

---

## Method get_model

```python
Model.get_model(model_name: str,
                authenticate: bool = False,
                use_existing_uid: bool = False)
```

The **get_model** method returns a new Model object to the model
specified by *model_name*.

If the *authenticate* parameter is set to True, it performs authentication again
on the new Model object.

The *use_existing_uid* parameter, in the event of failed authentication by
setting the *authenticate* parameter to False, skips authentication and uses
the same User ID used by the Model object.

#### Parameters

- **model_name**: name of the model to access.
- **authenticate**: if set to True, performs authentication.
- **use_existing_uid**: if set to True, uses the previous User ID.

#### Returns

- A new Model object that points to the model specified by *model_name*.

#### Usage example

```python
model_products = model.get_model(model_name='product.product',
                                 authenticate=False,
                                 use_existing_uid=True)
```

---

## Method get_model_data_reference

```python
Model.get_model_data_reference(module_name: str,
                               value: str,
                               ignore_none_errors: bool = False)
```

The **get_model_data_reference** method returns a row from the *ir.model.data*
model identified by its external ID specified by the *value* parameter.

#### Parameters

- **module_name**: name of the module from which to obtain the reference
- **value**: name of the external ID being searched for
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- A dictionary with the attributes of the row found.

#### Usage example

```python
results = model.get_model_data_reference(module_name='mail',
                                         value='mt_comment')
```

---

## Method get

```python
Model.get(entity_id: int,
          fields: tuple[str, ...] = None,
          options: dict[str, Any] = None,
          ignore_none_errors: bool = False)
```

The **get** method reads a specific record identified by its
*entity_id*, with the specified options, and returns the result of the
read.

All fields of the record will be returned, or only those specified by the
*fields* parameter.

#### Parameters

- **entity_id**: unique identifier of the element to be read
- **fields**: tuple with the names of the fields to be returned
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The result of reading the specified record.

#### Usage example

```python
results = model.get(entity_id=123,
                    fields=('id', 'firstname', 'lastname'))
```

---

## Method get_many

```python
Model.get_many(entity_ids: list[int],
               fields: tuple[str, ...] = None,
               options: dict[str, Any] = None,
               ignore_none_errors: bool = False)
```

The **get_many** method reads the specific records identified
by their *entity_ids*, with the options indicated, and returns the result of the
read.

All fields of the record will be returned, or only those indicated by the
*fields* parameter.

#### Parameters

- **entity_ids**: list of identifiers of the elements to be read
- **fields**: tuple with the names of the fields to be returned
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The result of reading the specified records.

#### Usage example

```python
results = model.get_many(entity_ids=[1, 2, 3],
                         fields=('id', 'firstname', 'lastname'))
```

---

## Method all

```python
Model.all(is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
          fields: list[str] = None,
          options: dict[str, Any] = None,
          limit: Optional[int] = None,
          offset: Optional[int] = None,
          order: Optional[str] = None,
          ignore_none_errors: bool = False)
```

The **all** method reads all records in the model,
including or excluding archived ones (active=False) based on the value of the
*is_active* parameter.

All fields in the record will be returned, or only those indicated by the
*fields* parameter.

#### Parameters

- **is_active**: filter on archived records
- **fields**: tuple with the names of the fields to include
- **options**: dictionary with the options to use
- **limit**: maximum number of records to return
- **offset**: initial record from which to read
- **order**: sorting clause, as used in SQL, a string of field names
  followed by the clause *asc* or *desc* to identify the type of
  sorting
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The result of reading the specified records.

#### Usage example

```python
results = model.all(is_active=ActiveStatusChoice.ACTIVE,
                    fields=['id', 'firstname', 'lastname'],
                    options=None,
                    limit=100,
                    offset=200,
                    order='firstname asc, lastname asc')
```

---

## Method find

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

The **find** method reads the records indicated by the *entity_ids* parameter,
including or excluding archived records (active=False) based on
the value of the *is_active* parameter.

All fields of the record will be returned, or only those indicated by the
*fields* parameter.

#### Parameters

- **entity_ids**: list of identifiers of the elements to be read
- **is_active**: filter on archived records
- **fields**: tuple with the names of the fields to include
- **options**: dictionary with the options to use
- **limit**: maximum number of records to return
- **offset**: initial record from which to read
- **order**: sorting clause, as used in SQL, a string of field names
  followed by the clause *asc* or *desc* to identify the type of
  sorting
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The result of reading the specified records.

#### Usage example

```python
results = model.find(is_active=ActiveStatusChoice.ACTIVE,
                     fields=['id', 'firstname', 'lastname'],
                     options=None,
                     limit=100,
                     offset=200,
                     order='firstname asc, lastname asc')
```

---

## Method filter

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

The **filter** method searches for records using the list of
filters specified in *filters*, including or excluding archived records
(active=False) based on the value of the *is_active* parameter, with the options
indicated, and returns the search results.

All fields of the record will be returned, or only those indicated by the
*fields* parameter.

#### Parameters

- **filters**: list of *Filter* or *BooleanOperator* objects to perform the
  search
- **is_active**: filter on archived records
- **fields**: tuple with the names of the fields to include
- **options**: dictionary with the options to use
- **limit**: maximum number of records to return
- **offset**: initial record from which to read
- **order**: sorting clause, as used in SQL, a string of field names
  followed by the clause *asc* or *desc* to identify the type of
  sorting
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- A list of integers identifying the records found by the search.

#### Usage example

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

## Method first

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

The **first** method searches for records using the list of
filters specified in *filters*, including or excluding archived records
(active=False) based on the value of the *is_active* parameter, with the options
indicated, and returns the first record as the search result.

All fields of the record will be returned, or only those indicated by the
*fields* parameter.

#### Parameters

- **filters**: list of *Filter* or *BooleanOperator* objects to perform the
  search
- **is_active**: filter on archived records
- **fields**: tuple with the names of the fields to include
- **options**: dictionary with the options to use
- **limit**: maximum number of records to return
- **offset**: initial record from which to read
- **order**: sorting clause, as used in SQL, a string of field names
  followed by the clause *asc* or *desc* to identify the type of
  sorting
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- A list of integers identifying the records found by the search.

#### Usage example

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

## Method count

```python
Model.count(filters: list[Union[BooleanOperator, Filter, str]],
            is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
            options: dict[str, Any] = None,
            ignore_none_errors: bool = False)
```

The **count** method searches for records using the list
of filters specified in *filters*, including or excluding archived records
(active=False) based on the value of the *is_active* parameter, with the options
indicated, and returns the number of records found by the search.

#### Parameters

- **filters**: list of *Filter* or *BooleanOperator* objects to perform the
  search
- **is_active**: filter on archived records
- **options**: dictionary with the options to use
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The number of records found by the search.

#### Usage example

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

## Method search

```python
Model.search(filters: list[Union[BooleanOperator, Filter, str]],
             is_active: ActiveStatusChoice = ActiveStatusChoice.NOT_SET,
             options: dict[str, Any] = None,
             limit: Optional[int] = None,
             offset: Optional[int] = None,
             order: Optional[str] = None,
             ignore_none_errors: bool = False)
```

The **search** method searches for records using the list
of filters specified in *filters*, including or excluding archived ones
(active=False) based on the value of the *is_active* parameter, with the options
indicated, and returns the records found by the search.

Compared to the *filter* method, the search method only returns the
identifiers of the records found, not the data itself.

#### Parameters

- **filters**: list of *Filter* or *BooleanOperator* objects to perform the
  search
- **is_active**: filter on archived records
- **fields**: tuple with the names of the fields to include
- **options**: dictionary with the options to use
- **limit**: maximum number of records to return
- **offset**: initial record from which to read
- **order**: sorting clause, as used in SQL, a string of field names
  followed by the clause *asc* or *desc* to identify the type of
  sorting
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- A list of integers identifying the records found by the search.

#### Usage example

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

## Method create

```python
Model.create(values: dict[str, Any],
             options: dict[str, Any] = None,
             ignore_none_errors: bool = False)
```

The **create** method is used to create a new record in the model
using the values specified in *values*, with the options indicated, and
returns the identifier for record created.

#### Parameters

- **values**: dictionary with field names and values to create the record
- **options**: dictionary with options to use
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The integer identifier of the newly created record.

#### Usage example

```python
entity_id = model.create(values={'firstname': 'Muflone',
                                 'lastname': 'Ovinis})
```

---

## Method update

```python
Model.update(entity_id: Union[int, list[int]],
             values: dict[str, Any],
             options: dict[str, Any] = None,
             ignore_none_errors: bool = False)
```

The **update** method is used to update one or more records indicated
by *entity_id* (this can be a single record as an integer or a list
of identifiers in a list of integers) using the values specified in
*values*, with the options indicated, and returns True if the update
was successful.

#### Parameters

- **entity_id**: unique identifiers of the elements to be updated
- **values**: dictionary with field names and values to create the record
- **options**: dictionary with options to use
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the specified records have been updated.

#### Usage example

```python
entity_id = model.update(entity_id=[1, 2],
                         values={'firstname': 'Muflone',
                                 'lastname': 'Ovinis})
```

---

## Method delete

```python
Model.delete(entity_id: Union[int, list[int]],
             options: dict[str, Any] = None,
             ignore_none_errors: bool = False)
```

The **delete** method is used to delete one or more records indicated
by *entity_id* (this can be a single record as an integer or a list
of identifiers in a list of integers), with the options indicated, and returns
True if the deletion was successful.

#### Parameters

- **entity_id**: unique identifiers of the elements to be deleted
- **options**: dictionary with options to use
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the specified records have been deleted.

#### Usage example

```python
entity_id = model.delete(entity_id=[1, 2])
```

---

## Method get_fields

```python
Model.get_fields(fields: list[str] = None,
                 attributes: list[str] = None,
                 options: dict[str, Any] = None,
                 ignore_none_errors: bool = False)
```

The **get_fields** method is used to obtain the fields present in the model,
filtered based on the *fields* and *attributes* parameters, with the options
indicated.

#### Parameters

- **fields**: list with the names of the fields to include
- **attributes**: list with the names of the attributes to include
- **options**: dictionary with the options to use
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- A dictionary containing all the fields identified for the model.

#### Usage example

```python
fields = model.get_fields(attributes=['string', 'type'])
```

---

## Method many_to_many_create

```python
Model.many_to_many_create(entity_id: int,
                          field: str,
                          values: dict[str, Any],
                          options: dict[str, Any] = None,
                          ignore_none_errors: bool = False)
```

The **many_to_many_create** method creates a new record with the values
specified by the *values* parameter and associates it with the relationship
indicated by the *field* field for the record identified by *entity_id*,
with the options indicated.

The method is used to create a new value in a
Many-to-Many relationship.

#### Parameters

- **entity_id**: unique identifier of the element to be updated
- **field**: name of the field that identifies the Many-to-Many relationship
- **values**: dictionary with names and values of the fields of the record to be created
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the record has been updated.

#### Usage example

```python
results = model.many_to_many_create(entity_id=123,
                                    field='child_ids',
                                    values={'firstname': 'Muflone',
                                            'lastname': 'Ovinis'})
```

---

## Method many_to_many_add

```python
Model.many_to_many_add(entity_id: int,
                       field: str,
                       related_id: int,
                       options: dict[str, Any] = None,
                       ignore_none_errors: bool = False)
```

The **many_to_many_add** method adds an existing record identified by
*related_id* to the relationship indicated by the *field* field for the record
identified by *entity_id*, with the options indicated.

The method is used to add an existing value in a
Many-to-Many relationship.

#### Parameters

- **entity_id**: unique identifier of the element to be updated
- **field**: name of the field that identifies the Many-to-Many relationship
- **related_id**: unique identifier of the element to be added
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the record has been updated.

#### Usage example

```python
results = model.many_to_many_add(entity_id=123,
                                 field='child_ids',
                                 related_id=321)
```

---

## Method many_to_many_update

```python
Model.many_to_many_update(entity_id: int,
                          field: str,
                          related_id: int,
                          values: dict[str, Any],
                          options: dict[str, Any] = None,
                          ignore_none_errors: bool = False)
```

The **many_to_many_update** method updates an existing record identified by
*related_id* in the relationship indicated by the *field* field for the record
identified by *entity_id*, with the options indicated.

The method is used to update an existing value in a
Many-to-Many relationship.

#### Parameters

- **entity_id**: unique identifier of the element to be updated
- **field**: name of the field that identifies the Many-to-Many relationship
- **related_id**: unique identifier of the element to be updated
- **values**: dictionary with names and values of the fields of the record to be updated
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the record has been updated.

#### Usage example

```python
results = model.many_to_many_update(entity_id=123,
                                    field='child_ids',
                                    related_id=321,
                                    values={'firstname': 'Muflone',
                                            'lastname': 'Ovinis'})
```

---

## Method many_to_many_delete

```python
Model.many_to_many_delete(entity_id: int,
                          field: str,
                          related_id: int,
                          options: dict[str, Any] = None,
                          ignore_none_errors: bool = False)
```

The **many_to_many_delete** method deletes an existing record identified by
*related_id* in the relationship indicated by the *field* field for the record
identified by *entity_id*, with the options indicated.

The method is used to delete an existing value in a
Many-to-Many relationship and also delete the related record.

#### Parameters

- **entity_id**: unique identifier of the element to be updated
- **field**: name of the field that identifies the Many-to-Many relationship
- **related_id**: unique identifier of the element to be deleted
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the record has been updated.

#### Usage example

```python
results = model.many_to_many_delete(entity_id=123,
                                    field='child_ids',
                                    related_id=321)
```

---

## Method many_to_many_remove

```python
Model.many_to_many_remove(entity_id: int,
                          field: str,
                          related_id: int,
                          options: dict[str, Any] = None,
                          ignore_none_errors: bool = False)
```

The **many_to_many_remove** method removes an existing record identified by
*related_id* in the relationship indicated by the *field* field for the record
identified by *entity_id*, with the options indicated.

The method is used to remove an existing value in a
Many-to-Many relationship but without also deleting the related record, which
will continue to exist in the related model and can be added again later.

#### Parameters

- **entity_id**: unique identifier of the element to be updated
- **field**: name of the field that identifies the Many-to-Many relationship
- **related_id**: unique identifier of the element to be removed
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the record has been updated.

#### Usage example

```python
results = model.many_to_many_remove(entity_id=123,
                                    field='child_ids',
                                    related_id=321)
```

---

## Method many_to_many_clear

```python
Model.many_to_many_clear(entity_id: int,
                         field: str,
                         options: dict[str, Any] = None,
                         ignore_none_errors: bool = False)
```

The **many_to_many_clear** method removes all records from the relationship
indicated by the *field* field for the record identified by *entity_id*, with
the options indicated.

The method is used to remove all existing values in a
Many-to-Many relationship but without also deleting the related records, which
will continue to exist in the related model and can be added
again later.

#### Parameters

- **entity_id**: unique identifier of the element to be updated
- **field**: name of the field that identifies the Many-to-Many relationship
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the record has been updated.

#### Usage example

```python
results = model.many_to_many_clear(entity_id=123,
                                   field='child_ids')
```

---

## Method many_to_many_replace

```python
Model.many_to_many_replace(entity_id: int,
                           field: str,
                           related_ids: list[int],
                           options: dict[str, Any] = None,
                           ignore_none_errors: bool = False)
```

The **many_to_many_replace** method replaces all existing records in the
relationship indicated by the *field* field with the records identified by
*related_ids* for the record identified by *entity_id*, with the options indicated.

The method is used to remove all existing values in a
Many-to-Many relationship and replace them with other values, but without also
deleting the related records, which will continue to exist in the related model
and can be added again later.

#### Parameters

- **entity_id**: unique identifier of the element to be updated
- **field**: name of the field that identifies the Many-to-Many relationship
- **related_ids**: unique identifiers of the elements to be inserted
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- True if the record has been updated.

#### Usage example

```python
results = model.many_to_many_replace(entity_id=123,
                                     field='child_ids',
                                     related_ids=[321, 322])
```

---

## Method execute

```python
Model.execute(method_name: str,
              args: list[Any],
              kwargs: dict[str, Any],
              ignore_none_errors: bool = False)
```

The **execute** method calls a model method, passing positional arguments
*args* and named and value arguments *kwargs*. 

#### Parameters

- **method**: remote method to use
- **args**: list of arguments to pass to the method by value
- **kwargs**: list of arguments to pass to the method by name and value
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The result of the remote method call.

#### Usage example

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

## Method get_message_subtype_id

```python
Model.get_message_subtype_id(subtype: str,
                             ignore_none_errors: bool = False)
```

The **get_message_subtype_id** method obtains the reference to the *subtype* for
the *mail* module, i.e. a value used by the *post_message* method.

The purpose of this method is to keep a cache of these values and not have to
retrieve them every time, so after the first request the value will be
stored and it will not be necessary to request the value again from the remote
model.

#### Parameters

- **subtype**: name of the *subtype* to request
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The value of the subtype from the *mail* module.

#### Usage example

```python
results = model.get_message_subtype_id(subtype=MessageSubType.COMMENT)
```

---

## Method post_message

```python
Model.post_message(subtype: Union[str, int],
                   entity_id: int,
                   author_id: int,
                   subject: Union[str, bool],
                   body: str,
                   options: dict[str, Any] = None,
                   ignore_none_errors: bool = False)
```

The **post_message** method is used to send a message of the type
[MessageSubType] indicated in *subtype* and linked to the record identified by
*entity_id*, with the author indicated by *author_id*, the subject specified in
*subject* and the message contained in *body*, with the options indicated, and
returns the identifier of the new message created.

#### Parameters

- **subtype**: message type of the [MessageSubType] class
- **entity_id**: unique identifier of the element to which the
  message is to be sent
- **author_id**: unique identifier of the user sending the message
- **subject**: subject of the message to be sent
- **body**: body of the message to be sent
- **options**: dictionary with the options to be used
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The integer identifier of the new message created.

#### Usage example

```python
entity_id = model.do_post_message(subtype=MessageSubType.NOTE,
                                  entity_id=123,
                                  author_id=2,
                                  subject='Prova',
                                  body='Messaggio per il record 123')
```

---

## Method post_message_as_activity

```python
Model.post_message_as_activity(entity_id: int,
                               body: str,
                               author_id: int,
                               ignore_none_errors: bool = False)
```

The **post_message_as_activity** method is used to send a message
of type *Activity* to the record identified by *entity_id*.

The method simply calls the *post_message* method, providing the
*subtype* as *MessageSubType.ACTIVITY*.

#### Parameters

- **entity_id**: unique identifier of the element to which the
  message is to be sent
- **body**: body of the message to be sent
- **author_id**: unique identifier of the user sending the message
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The integer identifier of the new message created.

#### Usage example

```python
entity_id = model.post_message_as_activity(entity_id=123,
                                           body='Activity per il record 123',
                                           author_id=2)
```

---

## Method post_message_as_comment

```python
Model.post_message_as_comment(entity_id: int,
                              body: str,
                              author_id: int,
                              ignore_none_errors: bool = False)
```

The **post_message_as_comment** method is used to send a message
of type *Comment* to the record identified by *entity_id*.

The method simply calls the *post_message* method, providing the
*subtype* as *MessageSubType.COMMENT*.

#### Parameters

- **entity_id**: unique identifier of the element to which the
  message is to be sent
- **body**: body of the message to be sent
- **author_id**: unique identifier of the user sending the message
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The integer identifier of the new message created.

#### Usage example

```python
entity_id = model.post_message_as_comment(entity_id=123,
                                          body='Commento per il record 123',
                                          author_id=2)
```

---

## Method post_message_as_note

```python
Model.post_message_as_note(entity_id: int,
                           body: str,
                           author_id: int,
                           ignore_none_errors: bool = False)
```

The **post_message_as_note** method is used to send a message
of type *Note* to the record identified by *entity_id*.

The method simply calls the *post_message* method, providing the
*subtype* as *MessageSubType.NOTE*.

#### Parameters

- **entity_id**: unique identifier of the element to which the
  message is to be sent
- **body**: body of the message to be sent
- **author_id**: unique identifier of the user sending the message
- **ignore_none_errors**: if set to True, ignores the None value error

#### Returns

- The integer identifier of the new message created.

#### Usage example

```python
entity_id = model.post_message_as_note(entity_id=123,
                                       body='Nota per il record 123',
                                       author_id=2)
```

---


[Usage examples]: {% link _pyodoo/english/examples/index.md %}
[Model]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}
[Filter]: {% link _pyodoo/english/docs/pyodoo/filter.md %}
[MessageSubType]: {% link _pyodoo/english/docs/pyodoo/message_subtype.md %}
