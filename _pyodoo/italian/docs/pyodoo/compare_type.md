---
layout: documentation
order: 533
depth: 2
title: CompareType
---

# Classe CompareType

La classe **CompareType** è utilizzata per confrontare un campo con valori e
comporre un filtro.

Non è necessario istanziare questa classe poiché i suoi membri possono essere 
utilizzati direttamente specificando i membri di classe.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

## Membri

### EQUAL

```python
EQUAL = '='
```

Il valore del campo confrontato deve essere esattamente uguale al valore.

### NOT_EQUAL

```python
NOT_EQUAL = '!='
```

Il valore del campo confrontato deve essere diverso dal valore.

### GREATER

```python
GREATER = '>'
```

Il valore del campo confrontato deve essere maggiore del valore.

### GREATER_EQ

```python
GREATER_EQ = '>='
```

Il valore del campo confrontato deve essere maggiore o uguale al valore.

### LOWER

```python
LOWER = '<'
```

Il valore del campo confrontato deve essere minore del valore.

### LOWER_EQ

```python
LOWER_EQ = '<='
```

Il valore del campo confrontato deve essere minore o uguale al valore.

### IN

```python
IN = 'in'
```

Il valore del campo confrontato deve essere uno dei valori.

### NOT_IN

```python
NOT_IN = 'not in'
```

Il valore del campo confrontato non deve essere uno dei valori.

### CONTAINS

```python
CONTAINS = 'ilike'
```

Il valore del campo confrontato deve contenere il valore.

### CONTAINS_NOT

```python
CONTAINS_NOT = 'not ilike'
```

Il valore del campo confrontato non deve contenere il valore.

### NOT_CONTAINS

```python
NOT_CONTAINS = 'not ilike'
```

Il valore del campo confrontato non deve contenere il valore.
È un sinonimo di CONTAINS_NOT.

### LIKE

```python
LIKE = 'like'
```

Il valore del campo confrontato deve essere simile al valore.
Nel caso di valori alfanumerici sarà automaticamente aggiunto % a inizio e fine
affinché il valore sia ricercato in qualsiasi punto del valore del campo.

### NOT_LIKE

```python
NOT_LIKE = 'not like'
```

Il valore del campo confrontato non deve essere simile al valore.
Nel caso di valori alfanumerici sarà automaticamente aggiunto % a inizio e fine
affinché il valore sia ricercato in qualsiasi punto del valore del campo.

### ILIKE

```python
ILIKE = 'ilike'
```

Il confronto sarà simile a LIKE ma il valore del campo dovrà avere la stessa
corrispondenza di lettere maiuscole e minuscole.

### NOT_ILIKE

```python
NOT_ILIKE = 'not ilike'
```

Il confronto sarà simile a NOT_LIKE ma il valore del campo dovrà avere la stessa
corrispondenza di lettere maiuscole e minuscole.

### RAW_LIKE

```python
RAW_LIKE = '=like'
```

Il confronto sarà simile a LIKE ma non saranno aggiunti % a inizio e fine del
valore e quindi sarà possibile effettuare ricerche con corrispondenze più
precise.

### RAW_ILIKE

```python
RAW_ILIKE = '=ilike'
```

Il confronto sarà simile a ILIKE ma non saranno aggiunti % a inizio e fine del
valore e quindi sarà possibile effettuare ricerche con corrispondenze più
precise.

### UNSET_OR_EQUAL

```python
UNSET_OR_EQUAL = '=?'
```

Il confronto sarà simile a EQUAL ma sarà soddisfatto anche se il valore del
campo fosse None o False.

### CHILD_OF

```python
CHILD_OF = 'child_of'
```

Il valore del campo confrontato dovrà essere un figlio discendente del valore.
Il funzionamento si basa sulle gerarchie, ad esempio con le categorie dei
prodotti.

### PARENT_OF

```python
PARENT_OF = 'parent_of'
```

Il valore del campo confrontato dovrà essere un genitore ascendente del valore.
Il funzionamento si basa sulle gerarchie, ad esempio con le categorie dei
prodotti.

[Esempi di utilizzo]: {% link _pyodoo/italian/examples/index.md %}
