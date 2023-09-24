---
layout: index
order: 100
title: Introduzione
---

**MuMailer** è un semplice agente di trasferimento di e-mail (MTA) per inviare
messaggi email da Python o da riga di comando, utilizzando profili multipli
per configurare i messaggi o i parametri SMTP, attraverso la programmazione a
oggetti e senza dover gestire i dettagli della connessione, le intestazioni,
il corpo o la codifica del testo per trasformare gli allegati.

# Utilizzo da codice Python

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

Il codice precedente preparerà un messaggio da *Muflone* e lo invierà a
*Foo*, aggiungendo *Bar* alla lista CC, utilizzando l'oggetto del messaggio
*Test e-mail* con il corpo HTML *Hello world!*.

La connessione SMTP sarà stabilita al server specificato sulla porta TCP 587
(il server deve essere in esecuzione) utilizzando l'autenticazione con utente
e password e cifrando utilizzando il protocollo SSL.

Per maggiori informazioni fare riferimento alla pagina [Documentazione]
e per alcuni esempi di utilizzo vedi la pagina [Esempi].

# Classe ProfileSMTP

Utilizzando i profili SMTP potrai personalizzare le impostazioni SMTP in file
YAML separati e caricarli quando è necessario inviare un messaggio, anziché
legarli al tuo codice.

Le impostazioni SMTP possono essere specificate in un file profilo come il
seguente:

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

È possibile caricare il file di impostazioni **ProfileSmtp** nel codice:

```python
from mumailer import Connection, ProfileSmtp

profile = ProfileSmtp(filename='profile-smtp.yaml')

connection = Connection(server=profile.server,
                        port=profile.port,
                        username=profile.username,
                        password=profile.password)
```

# Classe ProfileMessage

Similarmente, un profilo di messaggio può salvare le specifiche del messaggio
in file YAML separati e utilizzarle quando desideri inviare un messaggio.
Per esempio un report periodico dovrebbe essere sempre inviato agli stessi
destinatari, quindi è possibile evitare di scrivere gli indirizzi nel codice,
ma sarà possibile personalizzare le specifiche del messaggio quando necessario.

Le impostazioni di messaggio possono essere specificate in un file profilo
come il seguente:

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

È possibile caricare il file **ProfileMessage** e usarlo nel codice:

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

# Utilizzo da riga di comando

MuMailer può anche essere utilizzato da riga di comando per inviare messaggi,
utilizzando gli stessi argomenenti del codice Python:

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

L'esempio precedente invierà un messaggio da *Muflone* a *Foo*, aggiungendo
*Bar* alla lista CC, utilizzando l'oggetto *Test e-mail* con il corpo HTML
*Hello world!*.

La connessione SMTP sarà stabilita al server specificato sulla porta TCP 587
(il server deve essere in esecuzione) utilizzando l'autenticazione con utente
e password e cifrando utilizzando il protocollo TLS.

Alla stessa maniera sarà possibile specificare un file ProfileSMTP utilizzando
l'opzione `--profile-smtp` e un file ProfileMessage utilizzando l'opzione
`--profile-message`.

[Documentazione]: {% link _mumailer/italian/docs/index.md %}
[Esempi]: {% link _mumailer/italian/examples/index.md %}
