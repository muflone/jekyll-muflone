---
layout: documentation
order: 553
depth: 2
title: Attachment
---

# Classe Attachment

La classe **Attachment** è utilizzata per configurare i dettagli di un allegato.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

## Costruttore

```python
class Attachment(filename: str,
                 content: bytes,
                 content_type: str = None)
```

#### Argomenti

- **filename**: nome del file per l'allegato nel messaggio.
- **content**: contenuto binario dell'allegato.
- **content_type**: tipo del contenuto per i dati allegati.

#### Esempio di utilizzo

```python
import mumailer

attachment = mumailer.Attachment(filename='hello.html',
                                 content=b'<html><body><h1>Hello world!</h1></body></html>',
                                 content_type='text/html')
```

---

## Metodo load_filename

```python
Attachment.load_filename(filename: str,
                         content_type: str)
```

Il metodo statico **load_filename** può essere utilizzato per caricare un
nuovo oggetto Attachment dal file attraverso il suo percorso. Il contenuto del
file sarà caricato in un nuovo oggetto Attachment.

#### Argomenti

- **filename**: percorso del file da caricare.
- **content_type**: tipo del contenuto per il file da allegare.

#### Restituisce

- Questo metodo restituisce un nuovo oggetto Attachment.

#### Esempio di utilizzo

```python
attachment = mumailer.Attachment.load_filename(filename='myfile.pdf',
                                               content_type='application/pdf')
message.add_attachment(attachment=attachment)
```

[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
