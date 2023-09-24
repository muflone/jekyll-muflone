---
layout: index
order: 100
title: Introduction
---

**MuMailer** is a simple mail transfer agent (MTA) to send email messages from
Python or from command line, using multiple profiles to configure messages or
SMTP parameters, programming in Object-Oriented way and without having to
handle the connection details, the headers, the body or the text encoding to
transform the attachments.

# Usage from Python code

```python
from mumailer import Connection, Message, Recipient

message = Message(sender=Recipient('Muflone', 'muflone@example.com'),
                  to=[Recipient('Foo', 'foo@example.com')],
                  cc=[Recipient('Bar', 'bar@example.com')],
                  subject='Test e-mail',
                  body='<html><body><h1>Hello world!</h1></body></html>',
                  use_html=True)
connection = Connection(server='<server>',
                        port=587,
                        username='<username>',
                        password='<smtp password>')
connection.connect()
connection.send(message)
connection.disconnect()
```

The previous code will prepare a message from *Muflone* and will send the
message to *Foo*, adding *Bar* to the CC list, using the subject
*Test e-mail* with the HTML body *Hello world!*.

The SMTP connection will be established to the specified server on the TCP
port 587 (the server must be running) using username and password authentication
and encrypted using the SSL protocol.

For more information please refer to the [Documentation]
page and for some usage examples please see the [Examples] page.

# ProfileSMTP class

Using the SMTP profiles you can customize the SMTP settings in separated YAML
files and load them when you need to send a message, instead of wiring them in
your code.

The SMTP settings can be specified in a profile file like the
following:

```yaml
SMTP:
  SERVER: <SMTP server>
  PORT: 587
  USERNAME: <username>
  PASSWORD: <password>
  TIMEOUT: 30
  ENCRYPTION: TLSv1_2
  CIPHERS:
```

You can load the **ProfileSmtp** file settings and use them in the code:

```python
from mumailer import Connection, ProfileSmtp

profile = ProfileSmtp(filename='profile-smtp.yaml')

connection = Connection(server=profile.server,
                        port=profile.port,
                        username=profile.username,
                        password=profile.password)
```

# ProfileMessage class

Similarly, a message profile can save the message specifications in separated
YAML files and use them when you want to send a message.
For example a periodic report should always be sent to the same recipients, so
you could avoid to write the addresses in your code, but you can simply
customize the message specification when you need.

The message settings can be set specified in a profile file like the
following:

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

You can load the **ProfileMessage** file settings and use them in the code:

```python
from mumailer import Header, Message, ProfileMessage, Recipient

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
```

# Usage from command line

MuMailer can also be used from the command line to send messages, using the
same arguments for the Python code:

```shell
mumailer \
  --server '<server>' \
  --port 587 \
  --encryption TLS \
  --username '<username>' \
  --password '<smtp password>' \
  --sender 'Muflone muflone@example.com' \
  --to 'Foo foo@example.com' \
  --cc 'Bar bar@example.com' \
  --subject 'Test e-mail' \
  --body '<html><body><h1>Hello world!</h1></body></html>' \
  --html
```

The previous example will send a message from *Muflone* to *Foo*, adding *Bar*
to the CC list, using the subject *Test e-mail* with the HTML body
*Hello world!*.

The SMTP connection will be established to the specified server on the TCP
port 587 (the server must be running) using username and password authentication
and encrypted using the TLS protocol.

At the same way you can specify a ProfileSMTP file using the `--profile-smtp`
option and a ProfileMessage file using the `--profile-message`
option.

[Documentation]: {% link _mumailer/english/docs/index.md %}
[Examples]: {% link _mumailer/english/examples/index.md %}
