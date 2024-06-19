---
layout: changelog
order: 900
title: Cambiamenti
---
# Versione 0.7.2 (19 Agosto 2025)

* Gestita autenticazione non riuscita
* Applicati requisiti meno restrittivi
* Aggiunto decoratore _ignore_none_errors per molti metodi di Model
* Disabilitati i test poiché XML-RPC su demo.odoo.com risulta non disponibile
* Aggiunto il supporto a Python versione 3.13
* Aggiunte proprietà uid, partner_id, partner_name di Model

# Versione 0.7.1 (20 Giugno 2024)

* Aggiornamento dipendenze
* Corretti i dati sui test poiché il database demo è cambiato
* Aggiunte versioni Python aggiuntive per TravisCI

# Versione 0.7.0 (7 Ottobre 2023)

* Aggiunta classe PythonCode per eseguire codice Python
* Aggiunto esempio per PythonCode
* Aggiunti test per PythonCode

# Versione 0.6.0 (26 Giugno 2023)

* Added xlrd dependency
* Added requests dependency
* Added support for SqlExcelQuery
* Get the demo credentials following the https://demo.odoo.com/ redirects

# Versione 0.5.10 (3 Giugno 2023)

* Utilizza l'UID esistente se non autenticato in Model.get_model

# Versione 0.5.9 (17 Maggio 2023)

* Rimossi gli argomenti limit, offset e order da Model.get e Model.get_many

# Versione 0.5.8 (16 Maggio 2023)

* Aggiunti alcuni test su filter con CompareType
* Aggiunto CompareType.NOT_CONTAINS
* Aggiunto CompareType.LIKE
* Aggiunto CompareType.NOT_LIKE
* Aggiunto CompareType.ILIKE
* Aggiunto CompareType.NOT_ILIKE
* Aggiunto CompareType.RAW_LIKE
* Aggiunto CompareType.RAW_ILIKE
* Aggiunto CompareType.UNSET_OR_EQUAL
* Aggiunto CompareType.CHILD_OF
* Aggiunto CompareType.PARENT_OF
* Aggiunta compatibilità con Python 3.11

# Versione 0.5.7 (19 Marzo 2023)

* Aggiunto metodo first a Model per ottenere il primo risultato da filter

# Versione 0.5.6 (12 Febbraio 2023)

* Aggiunto argomento ignore_none_errors a Model per ignorare gli errori su valori nulli

# Versione 0.5.5 (5 Febbraio 2023)

* Aggiunto argomento authenticate su init di Model
* Aggiunto metodo do_read_many ad Api per ottenere record multipli per ID
* Aggiunto metodo get_many a Model method per ottenere più record per volta
* Cambiato il metodo update di Model per aggiornare più record per volta
* Rinominato il metodo set_order_by di Model in _set_order_by
* Rinominato il metodo set_pagination di Model in _set_pagination
* Rinominato il metodo set_options_language di Model in _set_options_language
* Aggiunto is_active ai metodi filter di Model

# Versione 0.5.4 (5 Febbraio 2023)

* Permessi record multipli su metodo delete di Model

# Versione 0.5.3 (24 Settembre 2022)

* Corretti controlli CI

# Versione 0.5.2 (24 Settembre 2022)

* Aggiunte icone
* Aggiunto pacchetto mancante pyodoo.v12
* Spostati esempi sotto la directory del pacchetto

# Versione 0.5.1 (22 Settembre 2022)

* Migrazione da setuptools a build

# Versione 0.5.0 (11 Settembre 2022)

* Aggiunta classe MessageSubType
* Aggiunto metodo do_post_message a Api
* Aggiunto metodo post_message a Model
* Aggiunto metodo post_message_as_note a Model
* Aggiunto metodo post_message_as_comment a Model
* Aggiunto metodo post_message_as_activity a Model
* Aggiunto metodo get_model a Model
* Aggiunto metodo get_model_data_reference a Model 
* Aggiunto metodo get_message_subtype_id a Model

# Versione 0.4.3 (10 Settembre 2022)

* Aggiunto metodo execute a Model

# Versione 0.4.2 (25 Agosto 2022)

* Aggiunto argomento order a Model

# Versione 0.4.1 (12 Giugno 2022)

* Intercettati gli errori durante l'eliminazione dei contatti
* Aggiunto Python 3.10 alle versioni supportate

# Versione 0.4.0 (12 Giugno 2022)

* Aggiunti risultati booleani ai metodi update e delete di Api e Model
* Aggiunto il metodo many_to_many_add a Model
* Aggiunto il metodo many_to_many_create a Model
* Aggiunto il metodo many_to_many_update a Model
* Aggiunto il metodo many_to_many_delete a Model
* Aggiunto il metodo many_to_many_remove a Model
* Aggiunto il metodo many_to_many_clear a Model
* Aggiunto il metodo many_to_many_replace a Model

# Versione 0.3.0 (7 Giugno 2022)

* Cambiato URL upstream in https
* Sostituito nose con pytest
* Spostati tutti i metodi di Model da Api a Model
* Aggiunto metodo count di Model
* Aggiunte opzioni al metodo do_delete di Api
* Aggiunte opzioni a tutti i metodi di Model
* Aggiunto limit e offset della paginazione a tutti i metodi di Model
* Aggiunto metodo get_fields di Model

# Versione 0.2.3 (21 Luglio 2021)

* Aggiunti alcuni esempi per utilizzo asincrono utilizzando awaitable

# Versione 0.2.2 (8 Giugno 2021)

* Aggiunto metodo all che restituisce tutte le righe nel modello
* Aggiunte proprietà per ottenere e impostare la lingua predefinita
* Aggiunto membro version col numero di versione

# Versione 0.2.1 (6 Giugno 2021)

* Aggiunto metodo authenticate per autenticare gli oggetti model
* Aggiunto ActiveStatusChoice al metodo find per trovare anche le righe attive o inattive durante la selezione
* Il metodo get restituisce sempre una riga singola oppure None
* Aggiungi test con nose

# Versione 0.2.0 (6 Giugno 2021)

* Aggiunto nome del modello alla classe Model e passato agli oggetti Api
* Ogni cosa verrà gestita dalla classe Model

# Versione 0.1.1 (6 Giugno 2021)

* Aggiunto supporto per Travis CI e Circle CI

# Versione 0.1.0 (6 Giugno 2021)

* Aggiunta API Contacts
* Aggiunta classe BooleanOperator per operazioni booleane in Odoo
* Aggiunta classe CompareType per confrontare valori nei filtri di Odoo
* Aggiunta classe Filter per filtri di Odoo
* Riscritta l'API aggiungendo metodi più generali
* Nuova classe ObjectModel per API generica per gli oggetti model
* Nuovo metodo filter per ObjectModel

# Versione 0.0.1 (4 Giugno 2021)

* Rilascio iniziale
