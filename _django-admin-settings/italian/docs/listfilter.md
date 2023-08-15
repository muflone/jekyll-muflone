---
layout: documentation
order: 533
depth: 2
title: ListFilter
---
# Modello ListFilter

## Descrizione

Il modello **ListFilter** consente di definire l'attributo *[list_filter]*
dei modelli di Django Admin per la definizione dei filtri da configurare.

{:.center}
![Elenco dei filtri](/resources/django-admin-settings/archive/latest/italian/listfilter.png)

Nell'esempio qui sopra mostrato, sono stati configurati i filtri sui campi
**is_active** e **model** per i modelli *ListDisplayAdmin*, *ListDisplayLinkAdmin*
e *ListFilterAdmin*.

>>>>> Dopo la modifica del modello ListFilter sarà necessario riavviare
>>>>> l'applicazione Django per ricaricare le nuove impostazioni.

>>>>>> Se non venisse definito nessun filtro saranno usati i filtri presenti
>>>>>> sul modello di Django. Se tutti i filtri definiti risultano disattivati
>>>>>> allora verranno rimossi anche i filtri predefiniti presenti sul modello.

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
[list_filter]: https://docs.djangoproject.com/en/stable/ref/contrib/admin/#django.contrib.admin.ModelAdmin.list_filter
