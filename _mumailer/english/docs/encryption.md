---
layout: documentation
order: 571
depth: 2
title: Encryption
nav_prefix: Structure
---

# ENCRYPTION_PROTOCOLS

The **ENCRYPTION_PROTOCOLS** dictionary is used to identify the allowed
encryption methods to use to communicate with the SMTP server.

To see some usage examples you can look at the page
[Usage examples].

#### Allowed values

- **SSLv23**:
  Once for SSL protocol, for modern Python versions it's the same of
  TLS.
- **TLS_CLIENT**:
  Auto-negotiate the highest protocol version that both the client and server
  support, and configure the context client-side
  connections.
- **TLS_SERVER**:
  Auto-negotiate the highest protocol version that both the client and server
  support, and configure the context server-side
  connections.
- **TLS**:
  Selects the highest protocol version that both the client and server support,
  valid for both TLS and SSL encryption.
- **TLSv1**:
  Selects TLS version 1.0 as the channel encryption protocol.
- **TLSv1_1**:
  Selects TLS version 1.1 as the channel encryption protocol.
- **TLSv1_2**:
  Selects TLS version 1.2 as the channel encryption protocol.

[Usage examples]: {% link _mumailer/english/examples/index.md %}
