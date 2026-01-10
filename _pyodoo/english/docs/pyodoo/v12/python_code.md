---
layout: documentation
order: 553
depth: 2
title: PythonCode
---

# Class PythonCode
{: .no_toc }

The **PythonCode** class is used to execute Python code within
the `execute.python.code` model, and this model is necessary for the
class to function.

This is a non-standard Odoo module provided by third-party applications,
and it must be installed in order to use this class.

To see some usage examples you can look at the page
[Usage examples].

- TOC
{: toc }

---
## Constructor

```python
class PythonCode(name: str,
                 endpoint: str,
                 database: str,
                 username: str,
                 password: str,
                 language: str = None)
```

#### Parameters

- **name**: name of the script to be created or used.
- **endpoint**: URL of the Odoo endpoint.
- **database**: name of the Odoo database to use.
- **username**: name of the Odoo user to use.
- **password**: password of the Odoo user to use.
- **language**: default language to use for translatable fields.

#### Usage example

```python
import pyodoo.v12

script = pyodoo.v12.PythonCode(name='Python Script Demo',
                               endpoint='https://demo.odoo.com',
                               database='demo_saas',
                               username='muflone',
                               password='mysecret',
                               language='en_GB')
```

Access the Odoo instance at https://demo.odoo.com on the
demo_saas database, using the credentials provided and the English language for
the translatable fields, and call up or create the script named
*Python Script Demo*.

---

## Static method is_available

```python
PythonCode.is_available(endpoint: str,
                        database: str,
                        username: str,
                        password: str,
                        language: str = None)
```

The static method **is_available** is static and can be called on both
PythonCode objects and on the class itself with PythonCode.is_available.
It checks whether the `execute.python.code` model is available and
returns True if the model is found, otherwise it returns
False.

#### Parameters

- **endpoint**: URL of the Odoo endpoint.
- **database**: name of the Odoo database to use.
- **username**: name of the Odoo user to use.
- **password**: password of the Odoo user to use.
- **language**: default language to use for translatable fields.

#### Returns

- True if the `execute.python.code` model was found.
- False if the `execute.python.code` model is not available.

#### Usage example

```python
print(PythonCode.is_available(endpoint='https://demo.odoo.com',
                              database='demo_saas',
                              username='muflone',
                              password='mysecret',
                              language='en_GB')
```

---

## Property name

The **name** property returns the name of the PythonCode object's script.

#### Returns

- The name of the script used by the PythonCode object.

#### Usage example

```python
print(script.name)
```

---

## Property id

The **id** property returns the unique identifier of the script
of the PythonCode object.

#### Returns

- The unique identifier from the PythonCode object.

#### Usage example

```python
print(script.id)
```

---

## Method get_code

```python
PythonCode.get_code()
```

The **get_code** method returns the Python code of the PythonCode object.

#### Returns

- The Python code of the PythonCode object script.

#### Usage example

```python
print(script.get_code())
```

---

## Method set_code

```python
PythonCode.set_code(text: str)
```

The **set_code** method sets the Python code for the PythonCode object.

The *text* parameter corresponds to the Python code to be saved.

#### Parameters

- **text**: Python code to be set.

#### Returns

- True if the record has been updated.

#### Usage example

```python
script.set_code(text='import sys\nresult = sys.version')
```

---

## Method execute

```python
PythonCode.execute()
```

The **execute** method executes the Python code of the PythonCode object.

#### Returns

- The method returns nothing.

#### Usage example

```python
script.set_code(text='import sys\nresult = sys.version')
script.execute()
```

---

## Method get_result

```python
PythonCode.get_result()
```

The **get_result** method reads the result of the last execution of the Python script
from the PythonCode object.

After executing the `execute` method, you can call the
`get_result` method to obtain the result of the execution.

#### Returns

- The result of the last execution of the Python script.

#### Usage example

```python
script.set_code(text='import sys\nresult = sys.version')
script.execute()
print(script.get_result())
```

---

## Method delete

```python
PythonCode.delete()
```

The **delete** method deletes the PythonCode object record.

#### Returns

- True if the record has been deleted.

#### Usage example

```python
script.delete()
```

---


[Usage examples]: {% link _pyodoo/english/examples/index.md %}
