---
layout: documentation
order: 535
depth: 2
title: MessageSubType
---

# Class MessageSubType

The **MessageSubType** class is used to specify the message sub-type to post
to model rows.

This class is not required to be instanced as its members can be directly used
by specifying the class members.

To see some usage examples you can look at the page
[Usage examples].

## Members

### ACTIVITY

```python
ACTIVITY = 'mt_activities'
```

The message will be a new activity.

### COMMENT

```python
COMMENT = 'mt_comment'
```

The message will be a comment for all the document's followers.

### NOTE

```python
NOTE = 'mt_note'
```

The message will be a new note.

[Usage examples]: {% link _pyodoo/english/examples/index.md %}
