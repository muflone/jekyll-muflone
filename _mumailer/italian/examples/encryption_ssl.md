---
layout: examples
order: 602
depth: 2
title: Cifratura SSL
---
# Connessione utilizzando la cifratura SSL

```python
from mumailer import Connection, Message, Recipient

message = Message(sender=Recipient('Muflone', 'muflone@example.com'),
                  to=[Recipient('Foo', 'foo@example.com')],
                  cc=[Recipient('Bar', 'bar@example.com')],
                  subject='Test e-mail',
                  body='<html><body><h1>Hello world!</h1></body></html>',
                  use_html=True)
connection = Connection(server='<server>',
                        port=465,
                        username='<username>',
                        password='<smtp password>')
connection.set_encryption(encryption='SSLv23')
connection.connect()
connection.send(message)
connection.disconnect()
```

Il metodo di cifratura **SSLv23** stabilirà una connessione usando il protocollo
SSL, se supportato, sulla porta 465.
