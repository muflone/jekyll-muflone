---
layout: documentation
order: 552
depth: 2
title: ListDisplayLink
---
# Modello ListDisplayLink

## Descrizione

Il modello **ListDisplayLink** consente di definire l'attributo *[list_display_links]*
dei modelli di Django Admin per definire quali campi nell'elenco dei record sono
cliccabili per accedere ai record su Django Admin.

{:.center}
![Colonne cliccabili](/resources/django-admin-settings/archive/latest/italian/listdisplaylink.png)

Nell'esempio qui sopra mostrato, sono state rese cliccabili le colonne **id** e
**\_\_str\_\_** dei modelli *ListDisplayAdmin*, *ListDisplayLinkAdmin* e *ListFilterAdmin*.

>>>>> Dopo la modifica del modello ListDisplayLink sarà necessario riavviare
>>>>> l'applicazione Django per ricaricare le nuove impostazioni.

## Campi

All'interno del modello sono presenti i seguenti campi:

| Nome            | Tipologia              | Descrizione                                               |
|:----------------|:-----------------------|:----------------------------------------------------------|
| **id**          | Intero (automatico)    | Identifica univocamente il record all'interno del modello |
| **\_\_str\_\_** | Carattere (automatico) | Mostra una breve descrizione del record del modello       |
| **model**       | Carattere              | Indica il nome del modello admin da configurare           |
| **field**       | Carattere              | Indica il nome del campo del modello admin da configurare |
| **order**       | Intero                 | Stabilisce l'ordine numerico dei campi da configurare     |
| **is_active**   | Booleano               | Consente di attivare o disattivare il campo configurato   |

{: target="_blank" .external }
[list_display_links]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/#django.contrib.admin.ModelAdmin.list_display_links
