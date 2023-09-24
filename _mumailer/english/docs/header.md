---
layout: documentation
order: 554
depth: 2
title: Header
---

# Class Header

The **Header** class is used to configure an additional message
header.

To see some usage examples you can look at the page
[Usage examples].

## Constructor

```python
class Header(name: str,
             value: str)
```

#### Arguments

- **name**: name of the header.
- **value**: string value assigned to the header.

#### Usage example

```python
import mumailer

header = mumailer.Header(name='X-Mailer',
                         value='MuMailer')
message.add_header(header=header)
```

---

## Method parse

```python
Header.parse(header: str)
```

The static method **parse** can be used to create a new Header object from a
string representation in the form Name=Value.

#### Arguments

- **header**: string header representation.

#### Returns

- The method returns a new Header object.

#### Usage example

```python
header = mumailer.Header.parse(header='X-Spam=0'))
message.add_header(header=header)
```

---

## Method parse_as_list

```python
Header.parse_as_list(headers: list[str])
```

The static method **parse_as_list** can be used to get a list of Header objects
from a list of string representations in the form Name=Value.

#### Arguments

- **headers**: list of string header representation.

#### Returns

- The method returns a list of Header objects.

#### Usage example

```python
headers = mumailer.Header.parse_as_list(headers=['X-Mailer=MuMailer',
                                                 'X-Spam=0'])))
message.headers.extend(headers)
```

[Usage examples]: {% link _mumailer/english/examples/index.md %}
