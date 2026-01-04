---
layout: documentation
order: 554
depth: 2
title: Header
---

# Classe Header
{: .no_toc }

La classe **Header** è utilizzata per configurare un'intestazione di messaggio
aggiuntiva.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

- TOC
{: toc }

---
## Costruttore

```python
class Header(name: str,
             value: str)
```

#### Parametri

- **name**: nome dell'intestazione.
- **value**: valore stringa assegnata all'intestazione.

#### Esempio di utilizzo

```python
import mumailer

header = mumailer.Header(name='X-Mailer',
                         value='MuMailer')
message.add_header(header=header)
```

---

## Metodo parse

```python
Header.parse(header: str)
```

Il metodo statico **parse** può essere utilizzato per creare un nuovo oggetto
Header dalla rappresentazione stringa nella forma Nome=Valore.

#### Parametri

- **header**: stringa con la rappresentazione dell'intestazione.

#### Restituisce

- Questo metodo restituisce un nuovo oggetto Header.

#### Esempio di utilizzo

```python
header = mumailer.Header.parse(header='X-Spam=0'))
message.add_header(header=header)
```

---

## Metodo parse_as_list

```python
Header.parse_as_list(headers: list[str])
```

Il metodo statico **parse_as_list** può essere utilizzato per ottenere una lista
di oggetti Header da una lista di rappresentazioni nella forma Nome=Valore.

#### Parametri

- **headers**: lista di stringhe di rappresentazione dell'intestazione.

#### Restituisce

- Questo metodo restituisce una lista di oggetti Header.

#### Esempio di utilizzo

```python
headers = mumailer.Header.parse_as_list(headers=['X-Mailer=MuMailer',
                                                 'X-Spam=0'])))
message.headers.extend(headers)
```

[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
