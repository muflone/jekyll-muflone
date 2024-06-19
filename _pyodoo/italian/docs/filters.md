---
layout: documentation
order: 512
depth: 2
title: Filtri
---
# Filtri

Esistono diversi modi per filtrare i dati al fine di trovare i record desiderati
in un modello: i metodi `filter` e `search`. Il metodo `first` funziona in modo
simile a `filter`, mentre il metodo `count` restituisce semplicemente il numero
di record.

Per filtrare i dati, l'argomento `filters` dei metodi precedenti deve essere
specificato come un elenco combinato di:

- alcuni oggetti [BooleanOperator] da applicare ai valori successivi nell'elenco
  dei filtri. L'operatore ***NOT*** si applica all'oggetto Filter successivo,
  mentre gli operatori ***AND*** e ***OR*** si applicano ai due oggetti Filter
  successivi.
- alcuni oggetti [Filter]

È possibile definire un elenco di filtri utilizzando un elenco Python che
combina entrambi gli oggetti [BooleanOperator] e [Filter].

<blockquote><blockquote><blockquote><blockquote><blockquote><blockquote><p>
Se non vengono specificati operatori, verrà applicato un AND implicito a tutti
gli oggetti Filter.
</p></blockquote></blockquote></blockquote></blockquote></blockquote></blockquote>

## Elenco di filtri a campo singolo

Per creare un elenco di filtri per un singolo campo è possibile utilizzare:

```python
filters = [
  Filter('field1', CompareType.EQUAL, 'value1'),
]
```

## Elenco di filtri a due campi

Per creare un elenco di filtri con due campi è possibile utilizzare:

```python
filters = [
  BooleanOperator.AND,
  Filter('field1', CompareType.EQUAL, 'value1'),
  Filter('field2', CompareType.EQUAL, 'value2'),
]
```

## Elenco di filtri a più campi

Per creare un elenco di filtri con tre campi è necessario specificare due
operatori: il primo per combinare il primo oggetto Filter con il risultato
dell'operazione tra il secondo operatore con il secondo e il terzo oggetto
Filter:

```python
filters = [
  BooleanOperator.AND,
  Filter('field1', CompareType.EQUAL, 'value1'),  # A
  BooleanOperator.OR,
  Filter('field2', CompareType.EQUAL, 'value2'),  # B
  Filter('field3', CompareType.EQUAL, 'value3'),  # C
]
```

L'espressione precedente corrisponderà al record con `field1 = 'value1'` e a
quelli con `field2 = 'value2'` o `field3 = 'value3'`. Nel codice Python questo
sarebbe descritto come ***A and (B or C)***, che equivale a:

```python
field1 == 'value1' and (field2 == 'value2' or field3 == 'value3')
```

Se è necessario creare un elenco di filtri che combini i primi due filtri o un
altro filtro, è necessario modificare l'ordine degli oggetti BooleanOperator:

```python
filters = [
  BooleanOperator.AND,
  BooleanOperator.OR,
  Filter('field1', CompareType.EQUAL, 'value1'),  # A
  Filter('field2', CompareType.EQUAL, 'value2'),  # B
  Filter('field3', CompareType.EQUAL, 'value3'),  # C
]
```

L'elenco dei filtri precedenti verrà tradotto in ***(A or B) and C***, che
equivale a:

```python
(field1 == 'value1' or field2 == 'value2') and field3 == 'value3'
```

È possibile combinare più oggetti BooleanOperator con più oggetti Filter in base
alle proprie necessità.

## Negare un oggetto filtro

È possibile negare un oggetto Filter utilizzando `BooleanOperator.NOT` applicato
al filtro o all'espressione successiva, come nell'esempio seguente:

```python
filters = [
  BooleanOperator.AND,
  Filter('field1', CompareType.EQUAL, 'value1'),
  BooleanOperator.NOT,
  Filter('field2', CompareType.EQUAL, 'value2'),
]
```

[Filter]: {% link _pyodoo/italian/docs/pyodoo/filter.md %}
[BooleanOperator]: {% link _pyodoo/italian/docs/pyodoo/boolean_operator.md %}
