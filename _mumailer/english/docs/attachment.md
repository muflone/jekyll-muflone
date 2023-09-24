---
layout: documentation
order: 553
depth: 2
title: Attachment
---

# Class Attachment

The **Attachment** class is used to configure an attachment details.

To see some usage examples you can look at the page
[Usage examples].

## Constructor

```python
class Attachment(filename: str,
                 content: bytes,
                 content_type: str = None)
```

#### Arguments

- **filename**: filename for the attachment in the message.
- **content**: binary content for the attachment.
- **content_type**: content type for the attached data.

#### Usage example

```python
import mumailer

attachment = mumailer.Attachment(filename='hello.html',
                                 content=b'<html><body><h1>Hello world!</h1></body></html>',
                                 content_type='text/html')
```

---

## Method load_filename

```python
Attachment.load_filename(filename: str,
                         content_type: str)
```

The static method **load_filename** can be used to load a new Attachment object
from a file by its path. The file content will be loaded in a new Attachment
object.

#### Arguments

- **filename**: path of the file to load.
- **content_type**: content type for the file to attach.

#### Returns

- The method returns a new Attachment object.

#### Usage example

```python
attachment = mumailer.Attachment.load_filename(filename='myfile.pdf',
                                               content_type='application/pdf')
message.add_attachment(attachment=attachment)
```

[Usage examples]: {% link _mumailer/english/examples/index.md %}
