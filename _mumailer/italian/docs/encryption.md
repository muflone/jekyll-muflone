---
layout: documentation
order: 571
depth: 2
title: Cifratura
nav_prefix: Strutture
---

# ENCRYPTION_PROTOCOLS

Il dizionario **ENCRYPTION_PROTOCOLS** è usato per identificare i metodi di
cifratura utilizzati per comunicare col server SMTP.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

#### Valori permessi

- **SSLv23**:
  In origine per il protocollo SSL, sulle versioni di Python moderne è lo
  stesso di TLS.
- **TLS_CLIENT**:
  Negozia automaticamente la versione di protocollo più elevata che sia il
  client che il server supportano, e configura il contesto della connessione
  lato client.
- **TLS_SERVER**:
  Negozia automaticamente la versione di protocollo più elevata che sia il
  client che il server supportano, e configura il contesto della connessione
  lato server.
- **TLS**:
  Sceglie la versione di protocollo più elevata che sia il client che il server
  supportano, valido sia per cifratura TLS che SSL.
- **TLSv1**:
  Sceglie il protocollo TLS versione 1.0 come sistema di cifratura.
- **TLSv1_1**:
  Sceglie il protocollo TLS versione 1.1 come sistema di cifratura.
- **TLSv1_2**:
  Sceglie il protocollo TLS versione 1.2 come sistema di cifratura.

[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
