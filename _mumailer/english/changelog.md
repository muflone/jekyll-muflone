---
layout: changelog
order: 900
title: Changelog
---
# Version 0.5.0 (Nov 26 2023)

* Added main script which includes both profiles and
  command line options

# Version 0.4.4 (Nov 26, 2023)

* Added compatibility with Python 3.11
* Added encryption protocol TLS for latest TLS version
* Renamed Message method to_email_message to _to_email_message
* Removed unused Attachment charset
* Allowed also no encryption
* Removed use_ssl and use_tls and determine the connection type and TLS
  encryption from the encryption method

# Version 0.4.3 (Sep 24, 2022)

* Code cleanup

# Version 0.4.2 (Sep 23, 2022)

* Updated dependencies
* Code cleanup
* Added icons

# Version 0.4.1 (Jan 08, 2022)

* Fixed typo in the documentation

# Version 0.4.0 (Jan 08, 2022)

* Added custom headers to the Message

# Version 0.3.1 (Jan 07, 2022)

* Added command line script mumailer
* Moved from setup.py to setup.cfg and build

# Version 0.3.0 (Jan 06, 2022)

* Added ProfileSmtp for SMTP configuration files
* Added ProfileMessage to set message settings
* Added samples to the installed package

# Version 0.2.0 (Jan 03, 2022)

* Added basic usage example to README
* Added command line options for the samples

# Version 0.1.1 (Dec 26, 2021)

* Added PyPI badges

# Version 0.1.0 (Dec 26, 2021)

* Initial release
