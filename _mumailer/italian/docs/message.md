---
layout: documentation
order: 552
depth: 2
title: Message
---

# Classe Message
{: .no_toc }

La classe **Message** è utilizzata per configurare i dettagli del messaggio,
i destinatari, il contenuto, il formato e gli allegati.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

- TOC
{: toc }

---
## Costruttore

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

#### Parametri

- **sender**: oggetto [Recipient] per impostare il mittente del messaggio.
- **subject**: testo dell'oggetto del messaggio.
- **body**: testo del corpo del messaggio.
- **to**: lista di oggetti [Recipient] a cui inviare il messaggio.
- **cc**: lista di oggetti [Recipient] da aggiungere al messaggio in CC.
- **bcc**: lista di oggetti [Recipient] da aggiungere al messaggio in BCC.
- **reply_to**: oggetto [Recipient] da impostare come ricevente delle risposte.
- **use_html**: specifica se trattare il corpo come HTML o semplice testo.
- **date**: oggetto [datetime] con la specifica di data e ora.
- **attachments**: lista di oggetti [Attachment] da allegare al messaggio.
- **headers**: lista di oggetti [Header] da includere come intestazioni
  aggiuntive del messaggio.

È possibile anche istanziare l'oggetto passando soltanto i parametri *sender*,
*subject* e *body* e impostare dopo gli altri campi, usando il loro nome.

Le intestazioni aggiuntive generalmente non sono necessarie fintanto che il
server SMTP le richiedesse per ragioni particolari, oppure se si desidera
specificare informazioni nelle intestazioni del messaggio.

#### Esempio di utilizzo

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

## Metodo add_attachment

```python
Message.add_attachment(attachment: Attachment)
```

Il metodo **add_attachment** è utilizzato per aggiungere un altro oggetto
[Attachment] alla lista degli allegati.

#### Parametri

- **attachment**: oggetto [Attachment] da aggiungere.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
attachment = mumailer.Attachment.load_filename(filename='myfile.pdf',
                                               content_type='application/pdf')
message.add_attachment(attachment=attachment)
```

---

## Metodo add_header

```python
Message.add_header(header: Header)
```

Il metodo **add_header** è utilizzato per aggiungere un altro oggetto [Header]
alla lista di intestazioni.

#### Parametri

- **header**: oggetto [Header] da aggiungere.

#### Restituisce

- Il metodo non restituisce nulla.

#### Esempio di utilizzo

```python
header = mumailer.Header(name='X-Mailer',
                         value='MuMailer')
message.add_header(header=header)
```

[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
[Recipient]: {% link _mumailer/italian/docs/recipient.md %}
[Attachment]: {% link _mumailer/italian/docs/attachment.md %}
[Header]: {% link _mumailer/italian/docs/header.md %}
[datetime]: https://docs.python.org/3/library/datetime.html#datetime.datetime
