---
layout: documentation
order: 532
depth: 2
title: BooleanOperator
---

# Classe BooleanOperator

La classe **BooleanOperator** è utilizzata per combinare filtri multipli per il
metodo filter nella classe Model, per specificare se il prossimo filtro sarà
negato o altrimenti se i due filtri seguenti saranno combinati con And/Or.

Non è necessario istanziare questa classe poiché i suoi membri possono essere 
utilizzati direttamente specificando i membri di classe.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

## Membri

### NOT

```python
NOT = '!'
```

Il filtro seguente verrà negato e quindi restituirà True nel caso in cui il
risultato sia False e viceversa.

### AND

```python
AND = '&'
```

I due filtri successi saranno combinati con un And booleano. Questo è il
predefinito anche se l'operatore non è specificato e due filtri sono combinati.

### OR

```python
OR = '|'
```

I due filtri successi saranno combinati con un Or booleano.

[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
