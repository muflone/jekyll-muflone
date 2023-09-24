---
layout: examples
order: 601
depth: 2
title: No Encrytion
---
# Connection using no Encryption

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

With no encryption method the connection will be established unencrypted,
if supported, on the port 25.
