---
layout: documentation
order: 561
depth: 2
title: ProfileMessage
---

# Class ProfileMessage

The **ProfileMessage** class is inherited from the [YamlProfile] class
and is used to load the message specifications from a file in YAML format.

The file format must match the specifications indicated below.

To see some usage examples you can look at the page
[Usage examples].

## Constructor

```python
class ProfileMessage(filename: str)
```

#### Arguments

- **filename**: YAML filename to load the message specifications.

#### Usage example

```python
import mumailer

profile = mumailer.ProfileMessage(filename='report.yaml')
```

---

## Method get_content_type

```python
ProfileMessage.get_content_type(index: int) -> str
```

The method **get_content_type** can be used to get the content-type for
an attachment.

Basically it gets the content-type from the content_types list if it has
multiple values otherwise it will use the first value.

#### Arguments

- **index**: index of the attachment for which to get the content-type.

#### Returns

- The method returns a string.

---

## File format specifications

A valid ProfileMessage file is a YAML file containing a main section **MESSAGE**
and the following attributes.

Any attribute used for email address allows to specify the email address
alone (address@server) or
name + email address (Full name address@server).

- **SENDER**: a string for the address for the message sender
- **TO**: a list of strings for recipients to send the message
- **CC**: a list of strings for recipients to send the message in CC
- **BCC**: a list of strings for recipients to send the message in BCC
- **REPLY_TO**: a string with the address used to reply the message
- **SUBJECT**: a string with the message subject
- **BODY**: a string with the message body text
- **BODY_FILE**: a string with the message filename containing the body text
- **HTML**: a boolean value (true/false) to specify to use HTML for the body
  text
- **DATE**: a date and time (YYYY-MM-DD HH:mm:ss) for the message date
- **ATTACHMENTS**: a list of strings with the files to attach to the message
- **CONTENT_TYPES**: a string or a list of strings for the attachments
  content-type. See also the ProfileMessage.get_content_type method
- **HEADERS**: a list of items (name=value) containing additional headers to
  append to the message

[YamlProfile]: {% link _mumailer/english/docs/yaml_profile.md %}
[Usage examples]: {% link _mumailer/english/examples/index.md %}
