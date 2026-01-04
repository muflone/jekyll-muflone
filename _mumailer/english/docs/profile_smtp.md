---
layout: documentation
order: 562
depth: 2
title: ProfileSMTP
---

# Class ProfileSMTP
{: .no_toc }

The **ProfileSMTP** class is inherited from the [YamlProfile] class
and is used to load the connection specifications from a file in YAML format.

The file format must match the specifications indicated below.

To see some usage examples you can look at the page
[Usage examples].

- TOC
{: toc }

---
## Constructor

```python
class ProfileSmtp(filename: str)
```

#### Parameters

- **filename**: YAML filename to load the connection specifications.

#### Usage example

```python
import mumailer

smtp = mumailer.ProfileSmtp(filename='myserver.yaml')
```

---

## File format specifications

A valid ProfileSMTP file is a YAML file containing a main section **SMTP**
and the following attributes.

- **SERVER**: a string with the SMTP server address
- **PORT**: an integer number with the SMTP port to use
- **USERNAME**: a string with the username used for SMTP authentication
- **PASSWORD**: a string with the password used for SMTP authentication
- **TIMEOUT**: an integer number for the connection timeout in seconds
- **ENCRYPTION**: a string specifying the encryption method,
  see also the [Encryption] page
- **CIPHERS**: a string with the encryption ciphers, for advanced settings

[YamlProfile]: {% link _mumailer/english/docs/yaml_profile.md %}
[Usage examples]: {% link _mumailer/english/examples/index.md %}
[Encryption]: {% link _mumailer/english/docs/encryption.md %}
