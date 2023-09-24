---
layout: documentation
order: 563
depth: 2
title: YamlProfile
---

# Class YamlProfile

The **YamlProfile** class is the base class for loading YAML files and it's
basically used to get options from the file.

To see some usage examples you can look at the page
[Usage examples].

## Constructor

```python
class YamlProfile(filename: str)
```

#### Arguments

- **filename**: YAML filename to load the specifications.

#### Usage example

```python
import mumailer

yaml = mumailer.YamlProfile(filename='myfile.yaml')
```

---

## Method get_option

```python
YamlProfile.get_option(option: str, default: Any = None) -> Any:
```

The method **get_option** can be used to get an option from the YAML file
by the option name and giving optionally a default value if the option is
missing.

#### Arguments

- **option**: option name
- **default**: default value for missing option

#### Returns

- The method returns the data from the YAML file

[Usage examples]: {% link _mumailer/english/examples/index.md %}
