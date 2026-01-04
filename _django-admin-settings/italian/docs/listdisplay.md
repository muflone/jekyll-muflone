---
layout: documentation
order: 531
depth: 2
title: ListDisplay
nav_prefix: Modelli
---
# Modello ListDisplay

## Descrizione

Il modello **ListDisplay** consente di definire l'attributo *[list_display]*
dei modelli di Django Admin per la definizione delle colonne da mostrare su
Django Admin.

{: .center }
![Elenco delle colonne](/resources/django-admin-settings/archive/latest/italian/listdisplay.png)

Nell'esempio qui sopra mostrato, sono state visualizzate tutte le colonne
esistenti per il modello *ListDisplayAdmin*.

>>>>> Dopo la modifica del modello ListDisplay sarà necessario riavviare
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
[list_display]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/#django.contrib.admin.ModelAdmin.list_display
