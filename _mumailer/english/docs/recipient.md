---
layout: documentation
order: 555
depth: 2
title: Recipient
---

# Class Recipient
{: .no_toc }

The **Recipient** class is used to configure a recipient which can be used as
sender, to, cc, bcc or reply-to in the message.

To see some usage examples you can look at the page
[Usage examples].

- TOC
{: toc }

---
## Constructor

```python
class Recipient(name: str,
                address: str)
```

#### Parameters

- **name**: optional name for the recipient.
- **address**: string recipient email address.

#### Usage example

```python
import mumailer

recipient = mumailer.Recipient(name='Muflone',
                               address='muflone@example.com')
message.sender = recipient
```

---

## Method parse

```python
Recipient.parse(address: str)
```

The static method **parse** can be used to create a new Recipient object from a
string representation in the form "Name email@address" or just
"email@address".

#### Parameters

- **address**: string recipient representation.

#### Returns

- The method returns a new Recipient object.

#### Usage example

```python
recipient = mumailer.Recipient.parse(address='Muflone Ovinis muflone@example.com')
message.reply_to = recipient
```

---

## Method parse_as_list

```python
Recipient.parse_as_list(addresses: list[str])
```

The static method **parse_as_list** can be used to get a list of Recipient
objects from a list of string representations in the form "Name email@address"
or just "email@address".

#### Parameters

- **addresses**: list of string recipient representation.

#### Returns

- The method returns a list of Recipient objects.

#### Usage example

```python
recipients = mumailer.Recipient.parse_as_list(addresses=[
    'Muflone Ovinis muflone@example.com',
    'foo@example.com'])
message.to = recipients
```

[Usage examples]: {% link _mumailer/english/examples/index.md %}
