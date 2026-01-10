---
layout: documentation
order: 554
depth: 2
title: SqlExcelQuery
---

# Class SqlExcelQuery
{: .no_toc }

The **SqlExcelQuery** class is used to execute an SQL query using
the `sql.excel.pdf` template, which is required for the
class to function.

This is a non-standard Odoo module provided by third-party applications
and must be installed in order to use this class.

To see some usage examples you can look at the page
[Usage examples].

- TOC
{: toc }

---
## Constructor

```python
class SqlExcelQuery(name: str,
                    category: str,
                    endpoint: str,
                    database: str,
                    username: str,
                    password: str,
                    language: str = None)
```

#### Parameters

- **name**: name of the SQL query to be created or used.
- **category**: name of the query category to be created or used.
- **endpoint**: URL of the Odoo endpoint.
- **database**: name of the Odoo database to use.
- **username**: name of the Odoo user to use.
- **password**: password of the Odoo user to use.
- **language**: default language to use for translatable fields.

#### Usage example

```python
import pyodoo.v12

query = pyodoo.v12.SqlExcelQuery(name='SQL Excel Query Demo',
                                 category='PyOdoo Demo',
                                 endpoint='https://demo.odoo.com',
                                 database='demo_saas',
                                 username='muflone',
                                 password='mysecret',
                                 language='en_GB')
```

Access the Odoo instance at https://demo.odoo.com on the
demo_saas database, using the credentials provided and the Italian language for
the translatable fields, and call up or create the SQL query named
*SQL Excel Query Demo* in the `PyOdoo Demo` category.

---

## Static method is_available

```python
SqlExcelQuery.is_available(endpoint: str,
                           database: str,
                           username: str,
                           password: str,
                           language: str = None)
```

The static method **is_available** is static and can be called on both
SqlExcelQuery objects and on the class itself with SqlExcelQuery.is_available.
It checks whether the `sql.excel.pdf` template is available and
returns True if the template is found, otherwise it returns
False.

#### Parameters

- **endpoint**: URL of the Odoo endpoint.
- **database**: name of the Odoo database to use.
- **username**: name of the Odoo user to use.
- **password**: password of the Odoo user to use.
- **language**: default language to use for translatable fields.

#### Returns

- True if the `sql.excel.pdf` model was found.
- False if the `sql.excel.pdf` model is not available.

#### Usage example

```python
print(SqlExcelQuery.is_available(endpoint='https://demo.odoo.com',
                                 database='demo_saas',
                                 username='muflone',
                                 password='mysecret',
                                 language='it_IT')
```

---

## Property name

The **name** property returns the name of the query of the
SqlExcelQuery object.

#### Returns

- The name of the query used by the SqlExcelQuery object.

#### Usage example

```python
print(query.name)
```

---

## Property language

The **language** property returns and assigns the language for the
SqlExcelQuery object.

#### Returns

- The current language from the SqlExcelQuery object.

#### Usage example

```python
print(query.language)
query.language = 'it_IT'
```

---

## Property id

The **id** property returns the unique identifier of the query
of the SqlExcelQuery object.

#### Returns

- The unique identifier from the SqlExcelQuery object.

#### Usage example

```python
print(query.id)
```

---

## Method get_sql

```python
SqlExcelQuery.get_code()
```

The **get_sql** method returns the SQL code of the SqlExcelQuery object.

#### Returns

- The SQL code for the query of the SqlExcelQuery object.

#### Usage example

```python
print(query.get_sql())
```

---

## Method set_sql

```python
SqlExcelQuery.set_sql(text: str)
```

The **set_sql** method sets the SQL code for the SqlExcelQuery object.

The *text* parameter corresponds to the SQL code to be saved.

#### Parameters

- **text**: SQL code to be set.

#### Returns

- True if the record has been updated.

#### Usage example

```python
query.set_sql(text='SELECT * FROM res_partner LIMIT 100')
```

---

## Method set_draft

```python
SqlExcelQuery.set_draft()
```

The **set_draft** method sets the SqlExcelQuery record to draft for editing.

#### Returns

- The method returns nothing.

#### Usage example

```python
query.set_draft()
```

---

## Method validate

```python
SqlExcelQuery.validate()
```

The **validate** method validates the SQL code of the SqlExcelQuery object.

#### Returns

- The method returns nothing.

#### Usage example

```python
query.validate()
```

---

## Method get_state

```python
SqlExcelQuery.get_state()
```

The **get_state** method reads the status of the SqlExcelQuery object.

#### Returns

- The status of the SqlExcelQuery object.

#### Usage example

```python
query.set_draft()
print(query.get_state())
query.validate()
print(query.get_state())
```

---

## Method get_active

```python
SqlExcelQuery.get_active()
```

The **get_active** method reads the `active` status of the SqlExcelQuery object.

#### Returns

- The `active` status of the SqlExcelQuery object.

#### Usage example

```python
print(query.get_active())
```

---

## Method set_active

```python
SqlExcelQuery.set_active(active: bool)
```

The **set_active** method sets the `active` status of the SqlExcelQuery object.

#### Returns

- True if the record has been updated.

#### Usage example

```python
print(query.set_active(active=False))
print(query.set_active(active=True))
```

---

## Method execute

```python
SqlExcelQuery.execute()
```

The **execute** method executes the SQL query of the SqlExcelQuery object.

#### Returns

- The method returns nothing.

#### Usage example

```python
query.set_sql(text='SELECT\n  *\nFROM res_partner\nLIMIT 100')
query.execute()
```

---

## Method clear

```python
SqlExcelQuery.clear()
```

The **clear** method clears the result of previous executions
of the SqlExcelQuery object.

#### Returns

- True if the record has been updated.

#### Usage example

```python
query.clear()
```

---

## Method delete

```python
SqlExcelQuery.delete()
```

The **delete** method deletes the record from the SqlExcelQuery object.

#### Returns

- True if the record has been deleted.

#### Usage example

```python
query.delete()
```

---

## Method get_file

```python
SqlExcelQuery.get_file()
```

The **get_file** method retrieves the Excel file from the last execution of the
SQL query of the SqlExcelQuery object.

#### Returns

- The binary content of the Excel file obtained.

#### Usage example

```python
query.execute()
data = query.get_file()
```

---

## Method get_data

```python
SqlExcelQuery.get_data()
```

The **get_data** method extracts data from the Excel file of the last execution
of the SQL query of the SqlExcelQuery object.

#### Returns

- A list of dictionaries with data extracted from the Excel file obtained.

#### Usage example

```python
query.execute()
data = query.get_data()
```

---

## Method add_tag

```python
SqlExcelQuery.add_tag(tag_id: int)
```

The **add_tag** method adds the tag identified by `tag_id` to the
SqlExcelQuery object.

#### Returns

- True if the record has been updated.

#### Usage example

```python
query.add_tag(tag_id=4)
```

---

## Method get_tags

```python
SqlExcelQuery.get_tags()
```

The **get_tags** method retrieves all tags from the `sql.tags` model to be
associated with the SqlExcelQuery object using the **add_tag** method.

#### Returns

- A list of dictionaries with tag data.

#### Usage example

```python
print(query.get_tags())
```

---


[Usage examples]: {% link _pyodoo/english/examples/index.md %}
