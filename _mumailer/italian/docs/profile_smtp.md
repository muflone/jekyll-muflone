---
layout: documentation
order: 562
depth: 2
title: ProfileSMTP
---

# Classe ProfileSMTP

La classe **ProfileSMTP** è ereditata dalla classe [YamlProfile] ed è
utilizzata per caricare le specifiche della connessione da un file in formato YAML.

Il formato del file deve corrispondere alle specifiche indicate sotto.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

## Costruttore

```python
class ProfileSmtp(filename: str)
```

#### Parametri

- **filename**: nome del file YAML da caricare con le specifiche di connessione.

#### Esempio di utilizzo

```python
import mumailer

smtp = mumailer.ProfileSmtp(filename='myserver.yaml')
```

---

## Specifiche del formato di file

Un file valido per ProfileSMTP è un file YAML contenente una sezione
principale **SMTP** e i seguenti attributi.

- **SERVER**: una stringa con l'indirizzo del server SMTP
- **PORT**: un numero intero con la porta SMTP da utilizzare
- **USERNAME**: una stringa con l'utente usato per l'autenticazione SMTP
- **PASSWORD**: una stringa con la password usata per l'autenticazione SMTP
- **TIMEOUT**: un numero intero per il timeout in secondi per la connessione
- **ENCRYPTION**: una stringa per specificare il metodo di cifratura,
  vedi anche la pagina [Cifratura]
- **CIPHERS**: una stringa per le cifre di cifratura, per impostazioni avanzate

[YamlProfile]: {% link _mumailer/italian/docs/yaml_profile.md %}
[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
[Cifratura]: {% link _mumailer/italian/docs/encryption.md %}
