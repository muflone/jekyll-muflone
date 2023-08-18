---
layout: documentation
order: 535
depth: 2
title: Headers
---
# Headers

It's possible to add to the request one or more HTTP headers if the website
would need to work properly.

Each header can be specified in this way:

```yaml
Name: Value
```

For example to change the User-Agent for the specific target you can use this
specification:

```yaml
HEADERS:
  User-Agent: 'Mozilla Firefox 115'
```
