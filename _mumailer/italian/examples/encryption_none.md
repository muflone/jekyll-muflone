---
layout: examples
order: 601
depth: 2
title: Senza cifratura
---
# Connessione senza cifratura

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
connection.connect()
connection.send(message)
connection.disconnect()
```

Senza metodo di cifratura la connessione verrà stabilita non cifrata,
se supportato, sulla porta 25.
