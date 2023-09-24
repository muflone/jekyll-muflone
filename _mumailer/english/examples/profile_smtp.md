---
layout: examples
order: 605
depth: 2
title: ProfileSMTP
---
# Using ProfileSMTP

The profile-smtp.yaml file will contain the following text:
```yaml
SMTP:
  SERVER: <SMTP server>
  PORT: 587
  USERNAME: <username>
  PASSWORD: <smtp password>
  TIMEOUT: 30
  ENCRYPTION: TLSv1_2
  CIPHERS:
```

```python
from mumailer import Connection, Message, ProfileSmtp, Recipient

message = Message(sender=Recipient('Muflone', 'muflone@example.com'),
                  to=[Recipient('Foo', 'foo@example.com')],
                  cc=[Recipient('Bar', 'bar@example.com')],
                  subject='Test e-mail',
                  body='<html><body><h1>Hello world!</h1></body></html>',
                  use_html=True)
profile = ProfileSmtp(filename='profile-smtp.yaml')
connection = Connection(server=profile.server,
                        port=profile.port,
                        username=profile.username,
                        password=profile.password)
connection.set_encryption(encryption=profile.encryption)
connection.connect()
connection.send(message)
connection.disconnect()
```

The connection settings will be loaded from the profile-smtp.yaml file and
passed to the connection object.
