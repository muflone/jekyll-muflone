---
layout: documentation
order: 563
depth: 2
title: YamlProfile
---

# Classe ProfileSMTP
{: .no_toc }

La classe **ProfileSMTP** è la classe base per il caricamento di file YAML ed
è fondamentalmente usata per ottenere opzioni dal file.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

- TOC
{: toc }

---
## Costruttore

```python
class YamlProfile(filename: str)
```

#### Parametri

- **filename**: nome del file YAML da caricare con le specifiche.

#### Esempio di utilizzo

```python
import mumailer

yaml = mumailer.YamlProfile(filename='myfile.yaml')
```

---

## Metodo get_option

```python
YamlProfile.get_option(option: str, default: Any = None) -> Any:
```

Il metodo **get_option** può essere utilizzato per ottenere un'opzione dal file
YAML dal nome dell'opzione e fornendo opzionalmente un valore predefinito se
l'opzione è mancante.

#### Parametri

- **option**: nome dell'opzione
- **default**: valore predefinito se l'opzione è mancante

#### Restituisce

- Il metodo restituisce i dati dal file YAML

[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
