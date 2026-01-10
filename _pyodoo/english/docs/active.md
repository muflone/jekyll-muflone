---
layout: documentation
order: 513
depth: 2
title: Active records
---
# Active records

Some Odoo models can use a field `active` to specify if a record is active
or has been archived, still present but marked as
hidden.

The records with `active` field set are considered archived and automatically
hidden from any list and they are not presented anymore in the Odoo UI until
explicitly requested (using `active=False` or using `active_test`
special context).

Some [Model] methods (like [all], [find], [filter] and others) include a
[ActiveStatusChoice] parameter named `is_active` which is used to specify
whether to include or exclude the archived records.

- The default value for the parameter is_active is
  **ActiveStatusChoice.NOT_SET** which uses the default Odoo value, usually
  to hide the archived records.
- To include only the active records you can specify the value
  **ActiveStatusChoice.ACTIVE** which explicitly hide the archived records.
- At the opposite, to include only the archived records and hiding the active
  ones you can specify the value **ActiveStatusChoice.INACTIVE**.
- To include both active and archived records you can specify the value
  **ActiveStatusChoice.BOTH**.

[Model]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}
[all]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-all
[find]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-find
[filter]: {% link _pyodoo/english/docs/pyodoo/v12/model.md %}#method-filter
[ActiveStatusChoice]: {% link _pyodoo/english/docs/pyodoo/active_status_choice.md %}
