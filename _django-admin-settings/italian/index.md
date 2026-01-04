---
layout: index
order: 100
title: Introduzione
---
**Django Admin Settings** è un'applicazione Django per configurare alcuni aspetti
dell'interfaccia di amministrazione di [Django Admin].

{: .center }
![Elenco delle colonne](/resources/django-admin-settings/archive/latest/italian/listdisplay.png)

Attraverso i modelli **ListDisplay** e **ListDisplayLink** sarà possibile
configurare le liste dei record in Django Admin.

{: .center }
![Elenco dei filtri](/resources/django-admin-settings/archive/latest/italian/listfilter.png)

Utilizzando il modello **ListFilter** sarà possibile definire quali filtri
sono disponibili sul pannello laterale.

# Documentazione

La documentazione delle impostazioni e dei modelli di Django Admin Settings sono
presenti nella [sezione Documentazione]({% link _django-admin-settings/italian/docs/index.md %}).

{: target="_blank" .external }
[Django Admin]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/

# Attivazione

L'applicazione può essere aggiunta a qualsiasi progetto esistente, semplicemente
installando il pacchetto e quindi aggiungendo l'applicazione alla variabile
`INSTALLED_APPS` nelle impostazioni del progetto Django:

```python
INSTALLED_APPS = [
    'django_admin_settings',
    ...
]
```
