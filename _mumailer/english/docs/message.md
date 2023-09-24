---
layout: documentation
order: 552
depth: 2
title: Message
---

# Class Message

The **Message** class is used to configure the message details, recipients,
content, format and attachments.

To see some usage examples you can look at the page
[Usage examples].

## Constructor

```python
class Message(sender: Recipient,
              subject: str,
              body: str,
              to: Optional[list[Recipient]] = None,
              cc: Optional[list[Recipient]] = None,
              bcc: Optional[list[Recipient]] = None,
              reply_to: Optional[Recipient] = None,
              use_html: bool = False,
              date: Optional[datetime.datetime] = None,
              attachments: Optional[list[Attachment]] = [],
              headers: Optional[list[Header]] = [])
```

#### Arguments

- **sender**: [Recipient] object to set as sender for the message.
- **subject**: subject text for the message.
- **body**: body text for the message.
- **to**: list of [Recipient] objects to send to message to.
- **cc**: list of [Recipient] objects to add to the message in CC.
- **bcc**: list of [Recipient] objects to add to the message in BCC.
- **reply_to**: [Recipient] object to set as receiver for the replies.
- **use_html**: specifies if to treat the body as HTML or plain text.
- **date**: [datetime] object with the date and time specification.
- **attachments**: list of [Attachment] objects to attach to the message.
- **headers**: list of [Header] objects to include as additional message
  headers.

You can also instance the object by passing only the *sender*, *subject* and
*body* arguments and later set the other fields, just by using their names.

Additional headers are generally not needed until your SMTP server needs them
for particular reasons, or you want to specify additional information in the
message headers.

#### Usage example

```python
import mumailer

message = mumailer.Message(sender=Recipient('Muflone', 'muflone@example.com'),
                           to=[Recipient('Foo', 'foo@example.com')],
                           subject='Test e-mail',
                           body='<html><body><h1>Hello world!</h1></body></html>',
                           use_html=True)
message.cc = [mumailer.Recipient('Bar', 'bar@example.com')]
message.bcc = [mumailer.Recipient('Hidden', 'me@example.com')]
```

---

## Method add_attachment

```python
Message.add_attachment(attachment: Attachment)
```

The **add_attachment** method is used to add another [Attachment] object to
the attachments list.

#### Arguments

- **attachment**: [Attachment] object to append.

#### Returns

- The method returns none.

#### Usage example

```python
attachment = mumailer.Attachment.load_filename(filename='myfile.pdf',
                                               content_type='application/pdf')
message.add_attachment(attachment=attachment)
```

---

## Method add_header

```python
Message.add_header(header: Header)
```

The **add_header** method is used to add another [Header] object to
the headers list.

#### Arguments

- **header**: [Header] object to append.

#### Returns

- The method returns none.

#### Usage example

```python
header = mumailer.Header(name='X-Mailer',
                         value='MuMailer')
message.add_header(header=header)
```

[Usage examples]: {% link _mumailer/english/examples/index.md %}
[Recipient]: {% link _mumailer/english/docs/recipient.md %}
[Attachment]: {% link _mumailer/english/docs/attachment.md %}
[Header]: {% link _mumailer/english/docs/header.md %}
[datetime]: https://docs.python.org/3/library/datetime.html#datetime.datetime
