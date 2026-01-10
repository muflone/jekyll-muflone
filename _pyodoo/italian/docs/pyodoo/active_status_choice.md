---
layout: documentation
order: 531
depth: 2
title: ActiveStatusChoice
nav_prefix: Package pyodoo
---

# Classe ActiveStatusChoice

La classe **ActiveStatusChoice** è utilizzata per specificare il comportamento
per l'argomento active in molti metodi, per determinare se includere o escludere
i record inattivi, quelli con campo active=False.

Non è necessario istanziare questa classe poiché i suoi membri possono essere 
utilizzati direttamente specificando i membri di classe.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

## Membri

### NOT_SET

```python
NOT_SET = None
```

I record col campo active non saranno inclusi nell'operazione filter, lasciando
quindi al modello la scelta se includerli o escluderli. Questo è il comportamento
predefinito se il valore non è specificato.

### ACTIVE

```python
ACTIVE = True
```

Soltanto i record con stato active=True verranno inclusi nel filtro.

### INACTIVE

```python
INACTIVE = False
```

Soltanto i record con stato active=False verranno inclusi nel filtro.

### BOTH

```python
BOTH = [True, False]
```

Sia i record con active=True che active=False saranno inclusi nel filtro.

[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
