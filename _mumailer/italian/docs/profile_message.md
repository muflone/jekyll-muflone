---
layout: documentation
order: 561
depth: 2
title: ProfileMessage
---

# Classe ProfileMessage

La classe **ProfileMessage** è ereditata dalla classe [YamlProfile] ed è
utilizzata per caricare le specifiche di messaggio da un file in formato YAML.

Il formato del file deve corrispondere alle specifiche indicate sotto.

Per osservare qualche esempio di utilizzo fare riferimento alla pagina
[Esempi di utilizzo].

## Costruttore

```python
class ProfileMessage(filename: str)
```

#### Parametri

- **filename**: nome del file YAML da caricare con le specifiche di messaggio.

#### Esempio di utilizzo

```python
import mumailer

profile = mumailer.ProfileMessage(filename='report.yaml')
```

---

## Metodo get_content_type

```python
ProfileMessage.get_content_type(index: int) -> str
```

Il metodo **get_content_type** può essere usato per ottere il content-type
per un allegato.

Fondamentalmente ottiene il content-type dalla lista content_types se ha valori
multipli altrimenti utilizzerà il primo valore.

#### Parametri

- **index**: indice dell'allegato per il quale ottenere il content-type.

#### Restituisce

- Il metodo restituisce una stringa.

---

## Specifiche del formato di file

Un file valido per ProfileMessage è un file YAML contenente una sezione
principale **MESSAGE** e i seguenti attributi.

Qualsiasi attributo utilizzato per indirizzo email permette di specificare il
solo indirizzo email (indirizzo@server) oppure
nome + indirizzo email (Nome indirizzo@server).

- **SENDER**: una stringa per l'indirizzo del mittente del messaggio
- **TO**: una lista di stringhe coi destinatari a cui inviare il messaggio
- **CC**: una lista di stringhe coi destinatari a cui inviare il messaggio in CC
- **BCC**: una lista di stringhe coi destinatari a cui inviare il messaggio in CCN
- **REPLY_TO**: una stringa con l'indirizzo usato per rispondere al messaggio
- **SUBJECT**: una stringa con l'oggetto del messaggio
- **BODY**: una stringa col testo del corpo del messaggio
- **BODY_FILE**: una stringa col nome del file contenente il corpo del messaggio
- **HTML**: un valore booleano (true/false) per specificare se usare HTML per
  il testo del corpo
- **DATE**: una data e ora (YYYY-MM-DD HH:mm:ss) per la data del messaggio
- **ATTACHMENTS**: una lista di stringhe coi file da allegare al messaggio
- **CONTENT_TYPES**: una stringa o una lista di stringhe per i content-type
  degli allegati. Vedi anche il metodo ProfileMessage.get_content_type
- **HEADERS**: una lista di elementi (nome=valore) contenente intestazioni
  aggiuntive da aggiungere al messaggio

[YamlProfile]: {% link _mumailer/italian/docs/yaml_profile.md %}
[Esempi di utilizzo]: {% link _mumailer/italian/examples/index.md %}
