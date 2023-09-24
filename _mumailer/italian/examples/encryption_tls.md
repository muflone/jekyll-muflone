---
layout: examples
order: 603
depth: 2
title: Cifratura TLS
---
# Connessione utilizzando la cifratura TLS

```python
from mumailer import Connection, Message, Recipient

message = Message(sender=Recipient('Muflone', 'muflone@example.com'),
                  to=[Recipient('Foo', 'foo@example.com')],
                  cc=[Recipient('Bar', 'bar@example.com')],
                  subject='Test e-mail',
                  body='<html><body><h1>Hello world!</h1></body></html>',
                  use_html=True)
connection = Connection(server='<server>',
                        port=25,
                        username='<username>',
                        password='<smtp password>')
connection.set_encryption(encryption='TLS')
connection.connect()
connection.send(message)
connection.disconnect()
```

Il metodo di cifratura **TLS** stabilirà una connessione usando il protocollo
TLS, se supportato, sulla porta 25.
