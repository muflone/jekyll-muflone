---
layout: documentation
order: 555
depth: 2
title: Recipient
---

# Classe Recipient
{: .no_toc }

La classe **Recipient** è utilizzata per configurare un contatto che può essere
utilizzato come sender, to, cc, bcc o reply-to nel messaggio.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

- TOC
{: toc }

---
## Costruttore

```python
class Recipient(name: str,
                address: str)
```

#### Parametri

- **name**: nome opzionale per il contatto.
- **address**: stringa dell'indirizzo email del contatto.

#### Esempio di utilizzo

```python
import mumailer

recipient = mumailer.Recipient(name='Muflone',
                               address='muflone@example.com')
message.sender = recipient
```

---

## Metodo parse

```python
Recipient.parse(address: str)
```

Il metodo statico **parse** può essere utilizzato per creare un nuovo oggetto
Recipient dalla rappresentazione stringa nella forma "Nome indirizzo@email"
oppure soltanto "indirizzo@email".

#### Parametri

- **address**: stringa con la rappresentazione del contatto.

#### Restituisce

- Questo metodo restituisce un nuovo oggetto Recipient.

#### Esempio di utilizzo

```python
recipient = mumailer.Recipient.parse(address='Muflone Ovinis muflone@example.com')
message.reply_to = recipient
```

---

## Metodo parse_as_list

```python
Recipient.parse_as_list(addresses: list[str])
```

Il metodo statico **parse_as_list** può essere utilizzato per ottenere una lista
di oggetti Recipient da una lista di rappresentazioni nella forma
"Nome indirizzo@email" oppure soltanto "indirizzo@email".

#### Parametri

- **addresses**: lista di stringhe di rappresentazione dei contatti.

#### Restituisce

- Questo metodo restituisce una lista di oggetti Recipient.

#### Esempio di utilizzo

```python
recipients = mumailer.Recipient.parse_as_list(addresses=[
    'Muflone Ovinis muflone@example.com',
    'foo@example.com'])
message.to = recipients
```

[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
