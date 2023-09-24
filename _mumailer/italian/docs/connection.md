---
layout: documentation
order: 551
depth: 2
title: Connection
nav_prefix: Classi
---

# Classe Connection

La classe **Connection** è utilizzata per stabilire la connessione al server
SMTP e per inviare i messaggi.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

## Costruttore

```python
class Connection(server: str,
                 port: int = 25,
                 username: str = None,
                 password: str = None)
```

#### Argomenti

- **server**: server SMTP a cui connettersi.
- **port**: porta del server SMTP a cui connettersi, generalmente molti server
  SMTP sono in ascolto sulle porte 25, 587 per traffico in chiaro o TLS oppure
  465 per connessioni cifrate SSL.
- **username**: utente di autenticazione SMTP.
- **password**: password di autenticazione SMTP per l'utente specificato.

#### Esempio di utilizzo

```python
import mumailer

connection = mumailer.Connection(server='<server>',
                                 port=587,
                                 username='<username>',
                                 password='<smtp password>'))
```

---

## Metodo set_encryption

```python
Connection.set_encryption(protocol: str = '',
                          ciphers: str = '')
```

Configura il protocollo di cifratura e le cifre.

#### Argomenti

- **protocol**: protocollo di cifratura da utilizzare, vedi la pagina [Cifratura].
- **ciphers**: cifre di cifratura disponibili per il protocollo scelto.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
connection.set_encryption(protocol='TLSv1_1',
                          ciphers='ALL:@SECLEVEL=1')
```

---

## Metodo connect

```python
Connection.connect(timeout: int = 30)
```

Stabilisce la connessione al server SMTP col metodo di cifratura
precedentemente configurato.

#### Argomenti

- **timeout**: tempo prima che la connessione venga annullata se il server non
  risponde nel numero di secondi specificato, predefinito 30 secondi.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
connection.connect(timeout=60)
```

---

## Metodo disconnect

```python
Connection.disconnect()
```

Disconnette dal server SMTP.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
connection.disconnect()
```

---

## Metodo noop

```python
Connection.noop()
```

Non esegue nulla, utilizzato soltanto per tenere la connessione attiva.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
connection.noop()
```

---

## Metodo send

```python
Connection.send(message: Message)
```

Invia un messaggio di posta.

#### Argomenti

- **message**: oggetto [Message] con i dettagli del messaggio da inviare.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
message = mumailer.Message(sender=Recipient('Muflone', 'muflone@example.com'),
                           to=[Recipient('Foo', 'foo@example.com')],
                           cc=[Recipient('Bar', 'bar@example.com')],
                           subject='Test e-mail',
                           body='<html><body><h1>Hello world!</h1></body></html>',
                           use_html=True)
connection.send(message=message)
```

[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
[SSL]: https://docs.python.org/3/library/ssl.html
[Cifratura]: {% link _mumailer/italian/docs/encryption.md %}
[Message]: {% link _mumailer/italian/docs/message.md %}
