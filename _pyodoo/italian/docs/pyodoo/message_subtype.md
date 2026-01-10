---
layout: documentation
order: 535
depth: 2
title: MessageSubType
---

# Classe MessageSubType

La classe **MessageSubType** è utilizzata per specificare il sottotipo di
messaggio da inviare alle righe del modello.

Non è necessario istanziare questa classe poiché i suoi membri possono essere 
utilizzati direttamente specificando i membri di classe.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

## Membri

### ACTIVITY

```python
ACTIVITY = 'mt_activities'
```

Il messaggio sarà una nuova attività.

### COMMENT

```python
COMMENT = 'mt_comment'
```

Il messaggio sarà un commento per tutti i follower del documento.

### NOTE

```python
NOTE = 'mt_note'
```

Il messaggio sarà una nuova nota.

[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
