---
layout: documentation
order: 512
depth: 2
title: ADMIN_SITE_HEADER
---
# Descrizione

L'impostazione **ADMIN_SITE_HEADER** consente di personalizzare l'intestazione
del sito di Django Admin e il titolo che sarà mostrato alla richiesta di login.
È possibile specificare la variabile all'interno del file `settings.py` e
assegnare il titolo che si desidera assegnare alle pagine.

# Esempio

```python
ADMIN_SITE_HEADER = 'Header'
```

{: .center }
![Intestazioni](/resources/django-admin-settings/archive/latest/italian/headers.png)
