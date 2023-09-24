---
layout: examples
order: 604
depth: 2
title: ProfileMessage
---
# Con ProfileMessage

Il file profile-message.yaml conterrà il testo seguente:
```yaml
MESSAGE:
  SENDER: Muflone muflone@example.com
  TO:
    - Foo foo@example.com
  CC:
    - Bar bar@example.com
  SUBJECT: Test e-mail
  BODY: <html><body><h1>Hello world!</h1></body></html>
  HTML: true
  ATTACHMENTS:
    - README.md
    - LICENSE
  CONTENT_TYPES:
    - text/plain
    - application/octet-stream
- HEADERS:
    - X-Mailer=MuMailer
    - X-MuMailer-Profile=message.yaml
```

```python
from mumailer import Connection, Message, ProfileMessage, Recipient

profile = ProfileMessage(filename='profile-message.yaml')
message = Message(sender=Recipient.parse(profile.sender),
                  reply_to=Recipient.parse(profile.reply_to),
                  to=Recipient.parse_as_list(profile.to),
                  cc=Recipient.parse_as_list(profile.cc),
                  bcc=Recipient.parse_as_list(profile.bcc),
                  subject=profile.subject,
                  body=profile.body,
                  use_html=profile.use_html,
                  headers=Header.parse_as_list(profile.headers))
connection = Connection(server='<server>',
                        port=25,
                        username='<username>',
                        password='<smtp password>')
connection.set_encryption(encryption='TLS')
connection.connect()
connection.send(message)
connection.disconnect()
```

Le impostazioni del message saranno caricate dal file profile-message.yaml
e passate all'oggetto message.
