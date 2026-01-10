---
layout: documentation
order: 513
depth: 2
title: Record attivi
---
# Record attivi

Alcuni modelli Odoo possono utilizzare un campo `active` per specificare se un
record è attivo o è stato archiviato, ancora presente ma contrassegnato come
nascosto.

I record con il campo `active` impostato sono considerati archiviati e
automaticamente nascosti da qualsiasi elenco e non vengono più visualizzati
nell'interfaccia utente di Odoo fino a quando non viene richiesto esplicitamente
(utilizzando `active=False` o utilizzando `active_test` contesto speciale).

Alcuni metodi di [Model] (come [all], [find], [filter] e altri) includono un
parametro [ActiveStatusChoice] denominato `is_active` che viene utilizzato per
specificare se includere o escludere i record archiviati.


- Il valore predefinito per il parametro is_active è
  **ActiveStatusChoice.NOT_SET** che utilizza il valore predefinito di Odoo,
  solitamente per nascondere i record archiviati.
- Per includere solo i record attivi è possibile specificare il valore
  **ActiveStatusChoice.ACTIVE** che nasconde esplicitamente i record archiviati.
- Al contrario, per includere solo i record archiviati e nascondere quelli
  attivi è possibile specificare il valore **ActiveStatusChoice.INACTIVE**.
- Per includere sia i record attivi che quelli archiviati è possibile
  specificare il valore **ActiveStatusChoice.BOTH**.

[Model]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}
[all]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-all
[find]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-find
[filter]: {% link _pyodoo/italian/docs/pyodoo/v12/model.md %}#method-filter
[ActiveStatusChoice]: {% link _pyodoo/italian/docs/pyodoo/active_status_choice.md %}
