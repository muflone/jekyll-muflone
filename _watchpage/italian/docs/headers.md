---
layout: documentation
order: 535
depth: 2
title: Headers
---
# Headers

È possibile aggiungere alla richiesta una o più intestazioni HTTP se il sito
ne avesse bisogno per il suo funzionamento.

Ogni intestazione può essere aggiunta nella forma:

```yaml
Nome: Valore
```

Per esempio per modificare lo User-Agent per il singolo obiettivo è possibile
usare questa specifica:

```yaml
HEADERS:
  User-Agent: 'Mozilla Firefox 115'
```
