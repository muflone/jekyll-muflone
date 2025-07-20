---
layout: documentation
order: 551
depth: 2
title: Connection
nav_prefix: Classes
---

# Class Connection

The **Connection** class is used to establish the connection to the SMTP
server and to send the messages to it.

To see some usage examples you can look at the page
[Usage examples].

## Constructor

```python
class Connection(server: str,
                 port: int = 25,
                 username: str = None,
                 password: str = None)
```

#### Parameters

- **server**: SMTP server to which to connect.
- **port**: SMTP server port to which to connect, usually most SMTP servers
  listen to ports 25, 587 for plain text traffic or TLS or 465 for SSL
  encrypted connections.
- **username**: SMTP authentication user.
- **password**: SMTP authentication password for the specified user.

#### Usage example

```python
import mumailer

connection = mumailer.Connection(server='<server>',
                                 port=587,
                                 username='<username>',
                                 password='<smtp password>'))
```

---

## Method set_encryption

```python
Connection.set_encryption(protocol: str = '',
                          ciphers: str = '')
```

Configure the encryption protocol and ciphers.

#### Parameters

- **protocol**: encryption protocol to use, see the [Encryption] page.
- **ciphers**: encryption available ciphers for the selected protocol.

#### Returns

- The method returns none.

#### Usage example

```python
connection.set_encryption(protocol='TLSv1_1',
                          ciphers='ALL:@SECLEVEL=1')
```

---

## Method connect

```python
Connection.connect(timeout: int = 30)
```

Establish the connection to the SMTP server with the encryption method
previously configured.

#### Parameters

- **timeout**: timeout before the connection is aborted if the server doesn't
  reply in the specified amount of seconds, defaults to 30 seconds.

#### Returns

- The method returns none.

#### Usage example

```python
connection.connect(timeout=60)
```

---

## Method disconnect

```python
Connection.disconnect()
```

Disconnect from the SMTP server.

#### Returns

- The method returns none.

#### Usage example

```python
connection.disconnect()
```

---

## Method noop

```python
Connection.noop()
```

Don't execute anything, only used to keep alive the connection.

#### Returns

- The method returns none.

#### Usage example

```python
connection.noop()
```

---

## Method send

```python
Connection.send(message: Message)
```

Send a mail message.

#### Parameters

- **message**: [Message] object with the message details to send.

#### Returns

- The method returns none.

#### Usage example

```python
message = mumailer.Message(sender=Recipient('Muflone', 'muflone@example.com'),
                           to=[Recipient('Foo', 'foo@example.com')],
                           cc=[Recipient('Bar', 'bar@example.com')],
                           subject='Test e-mail',
                           body='<html><body><h1>Hello world!</h1></body></html>',
                           use_html=True)
connection.send(message=message)
```

[Usage examples]: {% link _mumailer/english/examples/index.md %}
[SSL]: https://docs.python.org/3/library/ssl.html
[Encryption]: {% link _mumailer/english/docs/encryption.md %}
[Message]: {% link _mumailer/english/docs/message.md %}
