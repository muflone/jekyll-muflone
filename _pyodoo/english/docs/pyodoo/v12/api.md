---
layout: documentation
order: 551
depth: 2
title: Api
nav_prefix: Package pyodoo.v12
---

# Class Api
{: .no_toc }

The **Api** class is used to interface with Odoo and is responsible for
executing methods through the XML-RPC interface.

Many of the methods in the [Model] class use other methods in the Api class.

To see some usage examples you can look at the page
[Usage examples].

- TOC
{: toc }

---
## Constructor

```python
class Api(model_name: str,
          endpoint: str,
          database: str,
          username: str,
          password: str,
          language: str = None)
```

#### Parameters

- **model_name**: name of the model to access.
- **endpoint**: URL of the Odoo endpoint.
- **database**: name of the Odoo database to use.
- **username**: name of the Odoo user to use.
- **password**: password of the Odoo user to use.
- **language**: default language to use for translatable fields.

#### Usage example

```python
import pyodoo.v12

api = pyodoo.v12.Api(model_name='res.partner',
                     endpoint='https://demo.odoo.com',
                     database='demo_saas',
                     username='muflone',
                     password='mysecret',
                     language='en_GB')
```

Defines access to the Odoo instance at https://demo.odoo.com on the
demo_saas database, using the credentials provided and the English language for
translatable fields.

The res.partner model will be used for reading, writing,
creating, and modifying data.

---

## Method authenticate

```python
Api.authenticate()
```

The **authenticate** method performs session authentication using
database, user, and password.

#### Returns

- If authentication is successful, it returns the numerical identifier
of the authenticated user.
- If authentication fails, it returns the value False.

#### Usage example

```python
uid = api.authenticate()
```

---

## Method build_endpoint

```python
Api.build_endpoint(method: str)
```

The **build_endpoint** method returns the endpoint URL for the requested
method.

It is generally not necessary to call this method, which is used by the
*get_proxy* method.

#### Parameters

- **method**: remote method to be used

#### Returns

- The complete URL of the requested endpoint and method.

#### Usage example

```python
url = api.build_endpoint(method='xmlrpc/2/object')
```

---

## Method get_proxy

```python
Api.get_proxy(method: str)
```

The **get_proxy** method returns a ServerProxy object for executing commands
via XML-RPC.

It is generally not necessary to call this method, which is used by the
*get_proxy_object* method.

#### Parameters

- **method**: remote method to be used

#### Returns

- A ServerProxy object that points to the endpoint for the requested method.

#### Usage example

```python
proxy = api.get_proxy(method='xmlrpc/2/object')
```

---

## Method get_proxy_object

```python
Api.get_proxy_object(method: str)
```

The **get_proxy_object** method returns a ServerProxy object for Odoo's standard
*xmlrpc/2/object* endpoint.

It is generally not necessary to call this method, which is used by the
*execute* method.

#### Parameters

- **method**: remote method to be used

#### Returns

- A ServerProxy object pointing to Odoo's standard XML-RPC endpoint.

#### Usage example

```python
proxy = api.get_proxy(method='xmlrpc/2/object')
```

---

## Static method explode_filter

```python
Api.explode_filter(filters: list[Union[BooleanOperator, Filter, str]])
```

The static method **explode_filter** is static and can be called on both
Api objects and on the class itself with Api.explode_filter. It converts a
list of *Filter* objects and *BooleanOperator* values into a list of lists
with exploded filters, in the format used by Odoo for
domain selection.

#### Parameters

- **filters**: list of *Filter* or *BooleanOperator* objects to combine

#### Returns

- A list of lists containing strings or lists produced by the explode method
  of *[Filter]*.

#### Usage example

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

## Method do_execute

```python
Api.do_execute(method_name: str,
               args: list[Any],
               kwargs: dict[str, Any])
```

The **do_execute** method calls the chosen method with the list of arguments,
to execute the remote command on the XML-RPC server.

It is not usually necessary to call this method, which is used by the
*do_read*, *do_create* and other methods.

#### Parameters

- **method**: remote method to use
- **args**: list of arguments to pass to the method by value
- **kwargs**: list of arguments to pass to the method by name and value

#### Returns

- The result of the call to the remote XML-RPC method.

#### Usage example

```python
results = api.do_execute(method_name='read',
                         args=[entity_ids],
                         kwargs=options)
```

---

## Method do_read

```python
Api.do_read(entity_id: int,
            options: dict[str, Any])
```

The **do_read** method reads a specific record identified by its
*entity_id*, with the specified options, and returns the result of the
read.

It is generally not necessary to call this method, which is used by the
*get* method of the [Model] class.

#### Parameters

- **entity_id**: unique identifier of the element to be read
- **options**: dictionary with the options to be used

#### Returns

- The result of reading the specified record.

#### Usage example

```python
results = api.do_read(entity_id=123)
```

---

## Method do_read_many

```python
Api.do_read_many(entity_ids: list[int],
                 options: dict[str, Any])
```

The **do_read_many** method reads specific records identified
by their *entity_ids*, with the specified options, and returns the result of the
read.

It is generally not necessary to call this method, which is used by the
*get_many* method of the [Model] class.

#### Parameters

- **entity_ids**: list of identifiers of the elements to be read
- **options**: dictionary with the options to be used

#### Returns

- The result of reading the specified records.

#### Usage example

```python
results = api.do_read_many(entity_ids=[1, 2, 3])
```

---

## Method do_fields_get

```python
Api.do_fields_get(fields: list[str],
                  options: dict[str, Any])
```

The **do_fields_get** method obtains the list of fields present in the model and
filtered by the *fields* list to limit the result.

It is generally not necessary to call this method, which is used by the
*get_fields* method of the [Model] class.

#### Parameters

- **fields**: list of fields to include
- **options**: dictionary with the options to use

#### Returns

- A dictionary with all the fields present or indicated, with their types and
model specifications.

#### Usage example

```python
results = api.get_fields(fields=['id', 'firstname', 'lastname'])
```

---

## Method do_search

```python
Api.do_search(filters: list[Union[BooleanOperator, Filter, str]],
              options: dict[str, Any])
```

The **do_search** method searches for records using the list of
filters specified in *filters*, with the options indicated, and returns the
search results.

It is generally not necessary to call this method, which is used by the
*find* method of the [Model] class.

#### Parameters

- **filters**: list of *Filter* or *BooleanOperator* objects to perform the
  search
- **options**: dictionary with the options to use

#### Returns

- A list of integers identifying the records found by the search.

#### Usage example

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

## Method do_search_count

```python
Api.do_search_count(filters: list[Union[BooleanOperator, Filter, str]],
                    options: dict[str, Any])
```

The **do_search_count** method searches for records using the list
of filters specified in *filters*, with the options indicated, and returns the
number of records found by the search.

It is generally not necessary to call this method, which is used by the
*count* method of the [Model] class.

#### Parameters

- **filters**: list of *Filter* or *BooleanOperator* objects to perform the
  search
- **options**: dictionary with the options to use

#### Returns

- The count of records found by the search.

#### Usage example

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

## Method do_search_read

```python
Api.do_search_read(filters: list[Union[BooleanOperator, Filter, str]],
                   options: dict[str, Any])
```

The **do_search_read** method searches for records using the list
of filters specified in *filters*, with the options indicated, and returns the
records found by the search.

It is generally not necessary to call this method, which is used by the
*filter* method of the [Model] class.

#### Parameters

- **filters**: list of *Filter* or *BooleanOperator* objects to perform the
  search
- **options**: dictionary with the options to use

#### Returns

- A list of records found, with a dictionary for each record found.

#### Usage example

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

## Method do_create

```python
Api.do_create(values: dict[str, Any],
              options: dict[str, Any])
```

The **do_create** method is used to create a new record in the model
using the values specified in *values*, with the options indicated, and
returns the records found by the search.

It is generally not necessary to call this method, which is used by the
*create* method of the [Model] class.

#### Parameters

- **values**: dictionary with field names and values to create the record
- **options**: dictionary with options to use

#### Returns

- The integer identifier of the newly created record.

#### Usage example

```python
entity_id = api.do_create(values={'firstname': 'Muflone',
                                  'lastname': 'Ovinis})
```

---

## Method do_update

```python
Api.do_update(entity_id: Union[int, list[int]],
              values: dict[str, Any],
              options: dict[str, Any])
```

The **do_update** method is used to update one or more records specified
by *entity_id* (which can be a single record as an integer or a list
of identifiers in a list of integers) using the values specified in
*values*, with the options indicated, and returns True if the update
was successful.

It is generally not necessary to call this method, which is used by the
*update* method of the [Model] class.

#### Parameters

- **entity_id**: unique identifiers of the elements to be updated
- **values**: dictionary with field names and values to update the record
- **options**: dictionary with the options to be used

#### Returns

- True if the specified records have been updated.

#### Usage example

```python
entity_id = api.do_update(entity_id=[1, 2],
                          values={'firstname': 'Muflone',
                                  'lastname': 'Ovinis})
```

---

## Method do_delete

```python
Api.do_delete(entity_id: Union[int, list[int]],
              options: dict[str, Any])
```

The **do_delete** method is used to delete one or more records specified
by *entity_id* (which can be a single record as an integer or a list
of identifiers in a list of integers), with the specified options, and returns
True if the deletion was successful.

It is generally not necessary to call this method, which is used by the
*delete* method of the [Model] class.

#### Parameters

- **entity_id**: unique identifiers of the elements to be deleted
- **options**: dictionary with the options to be used

#### Returns

- True if the specified records have been deleted.

#### Usage example

```python
entity_id = api.do_delete(entity_id=[1, 2])
```

---

## Method do_post_message

```python
Api.do_post_message(subtype: Union[str, int],
                    entity_id: int,
                    author_id: int,
                    subject: Union[str, bool],
                    body: str,
                    options: dict[str, Any])
```

The **do_post_message** method is used to send a message of the type
[MessageSubType] indicated in *subtype* and linked to the record identified by
*entity_id*, with the author indicated by *author_id*, the subject specified in
*subject* and the message contained in *body*, with the options indicated, and
returns the identifier of the new message created.

It is generally not necessary to call this method, which is used by the
*post_message* method of the [Model] class.

#### Parameters

- **subtype**: message type of the class [MessageSubType]
- **entity_id**: unique identifier of the element to which the message is to be
  sent
- **author_id**: unique identifier of the user sending the message
- **subject**: subject of the message to be sent
- **body**: body of the message to be sent
- **options**: dictionary with the options to be used

#### Returns

- The integer identifier of the newly created message.

#### Usage example

```python
entity_id = api.do_post_message(subtype=MessageSubType.NOTE,
                                entity_id=123,
                                author_id=2,
                                subject='Test',
                                body='Message for the record 123')
```

---


[Usage examples]: {% link _pyodoo/english/examples/index.md %}
[Model]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}
[Filter]: {% link _pyodoo/english/docs/pyodoo/filter.md %}
[MessageSubType]: {% link _pyodoo/english/docs/pyodoo/message_subtype.md %}