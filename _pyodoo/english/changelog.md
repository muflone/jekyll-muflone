---
layout: changelog
order: 900
title: Changelog
---
# Version 0.7.2 (Aug 19, 2025)

* Handle authentication unsuccessful
* Applied less strict requirements
* Added decorator _ignore_none_errors for many Model methods
* Disable tests as demo.odoo.com XML-RPC seems unavailable
* Added supported Python version 3.13
* Added Model properties uid, partner_id, partner_name

# Version 0.7.1 (Jun 20, 2024)

* Bumped dependencies
* Fixed tests data as the database demo has changed
* Added extra Python versions for TravisCI

# Version 0.7.0 (Oct 7, 2023)

* Added PythonCode class to execute a Python code
* Added sample for PythonCode
* Added tests for PythonCode

# Version 0.6.0 (Jun 26, 2023)

* Aggiunta dipendenza xlrd
* Aggiunta dipendenza requests
* Aggiunto il supporto a SqlExcelQuery
* Ottenute le credenziali demo seguendo i redirect di https://demo.odoo.com/

# Version 0.5.10 (Jun 3, 2023)

* Use the existing UID if not authenticated in Model.get_model

# Version 0.5.9 (May 17, 2023)

* Removed limit, offset and order arguments from Model.get and Model.get_many

# Version 0.5.8 (May 16, 2023)

* Added some tests for filter with CompareType
* Added CompareType.NOT_CONTAINS
* Added CompareType.LIKE
* Added CompareType.NOT_LIKE
* Added CompareType.ILIKE
* Added CompareType.NOT_ILIKE
* Added CompareType.RAW_LIKE
* Added CompareType.RAW_ILIKE
* Added CompareType.UNSET_OR_EQUAL
* Added CompareType.CHILD_OF
* Added CompareType.PARENT_OF
* Added compatibility with Python 3.11

# Version 0.5.7 (Mar 19, 2023)

* Added Model method first to get the first result from filter

# Version 0.5.6 (Feb 12, 2023)

* Added argument ignore_none_errors to Model to ignore errors about None values

# Version 0.5.5 (Feb 5, 2023)

* Added authenticate argument to Model init
* Added Api method do_read_many to get multiple records by ID
* Added Model method get_many to get multiple records at once
* Changed the Model update method to update multiple records at once
* Renamed Model method set_order_by to _set_order_by
* Renamed Model method set_pagination to _set_pagination
* Renamed Model method set_options_language to _set_options_language
* Added is_active filter Model methods

# Version 0.5.4 (Feb 5, 2023)

* Allowed multiple records for the Model method delete

# Version 0.5.3 (Sep 24, 2022)

* Fixed CI checks

# Version 0.5.2 (Sep 24, 2022)

* Added icons
* Added missing pyodoo.v12 package
* Moved samples under the package dir

# Version 0.5.1 (Sep 22, 2022)

* Moved from setuptools to build

# Version 0.5.0 (Sep 11, 2022)

* Added class MessageSubType
* Added Api method do_post_message
* Added Model method post_message
* Added Model method post_message_as_note
* Added Model method post_message_as_comment
* Added Model method post_message_as_activity
* Added Model method get_model
* Added Model method get_model_data_reference
* Added Model method get_message_subtype_id

# Version 0.4.3 (Sep 10, 2022)

* Added Model method execute

# Version 0.4.2 (Aug 25, 2022)

* Added order argument to Model

# Version 0.4.1 (Jun 12, 2022)

* Catch errors during contacts deletion
* Added Python 3.10 to supported versions

# Version 0.4.0 (Jun 12, 2022)

* Added boolean results for Api and Model methods for update and delete
* Added method many_to_many_add to Model
* Added method many_to_many_create to Model
* Added method many_to_many_update to Model
* Added method many_to_many_delete to Model
* Added method many_to_many_remove to Model
* Added method many_to_many_clear to Model
* Added method many_to_many_replace to Model

# Version 0.3.0 (Jun 7, 2022)

* Changed upstream URL to https
* Replaced nose with pytest
* Moved all the Model methods from Api to Model
* Added Model method count
* Added options to Api method do_delete
* Added options to every Model method
* Added pagination's limit and offset arguments to every Model method
* Added Model method get_fields

# Version 0.2.3 (Jul 21, 2021)

* Added some samples for async usages using awaitable

# Version 0.2.2 (Jun 8, 2021)

* Added method all which returns all the rows in the model
* Added properties for get and set the default language
* Added version member with the version number

# Version 0.2.1 (Jun 6, 2021)

* Added authenticate method to authenticate model objects
* Added ActiveStatusChoice to method find to get also active or inactive rows during the selection
* The method get always returns a single row or None
* Added nose tests

# Version 0.2.0 (Jun 6, 2021)

* Added the model name to the Model class and passed to the Api objects
* Everything will be managed by the Model class

# Version 0.1.1 (Jun 6, 2021)

* Added support for Travis CI and Circle CI

# Version 0.1.0 (Jun 6, 2021)

* Added Contacts API
* Added BooleanOperator class for boolean operations in Odoo
* Added CompareType class for comparing values in Odoo filters
* Added Filter class for Odoo filters
* Rewrote the API adding more general methods
* New ObjectModel class for generic API for model objects
* New method filter for ObjectModel

# Version 0.0.1 (Jun 4, 2021)

* Initial release
