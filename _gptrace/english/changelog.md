---
layout: changelog
order: 900
title: Changelog
---
# Version 0.6.2 (Oct 1, 2022)

* Fixed Italian translation

# Version 0.6.1 (Aug 22, 2022)

* Translations update
* Updated Dutch translation

# Version 0.6.0 (Aug 12, 2022)

* Dropped AppMenu
* Ported to Python 3 and migrated to modern app
* Moved the program path to header bar
* Show only a button at once for Start and Stop process
* Rename Intercepted syscalls to Selected syscalls

![Main window for gpTrace 0.6.0](/resources/gptrace/archive/v0.6.0/english/expanded.png)

# Version 0.5.0 (Jul 11, 2021)

* Ported to Python 3
* Added support for Travis CI and Circle CI
* New Lithuanian translation by Moo
* New Dutch translation by Heimen Stoffels

# Version 0.4.2 (Sep 6, 2014)

* New Bulgarian translation by sahwar

# Version 0.4.1 (Aug 24, 2014)

* Interface cleanup

# Version 0.4.0 (Aug 24, 2014)

* Added Processes page

![Processes page for gpTrace 0.4.0](/resources/gptrace/archive/v0.4.0/english/processes.png)

# Version 0.3.0 (Aug 17, 2014)

* Added Files page

![Files page for gpTrace 0.3.0](/resources/gptrace/archive/v0.3.0/english/files.png)

# Version 0.2.0 (Aug 16, 2014)

* Added Counts page
* Added settings to show only called syscalls in Counts page

![Counts page for gpTrace 0.2.0](/resources/gptrace/archive/v0.2.0/english/counts.png)

# Version 0.1.4 (Aug 9, 2014)

* Code cleanup
* Added create-translations.sh to rebuild translations files
* Updated translations

![Main window for gpTrace 0.1.4](/resources/gptrace/archive/v0.1.4/english/expanded.png)

# Version 0.1.3 (Jun 22, 2014)

* Added GtkBuilderLoader class
* Moved all the Gtk widget references and moved to the GtkBuilderLoader
* Updated project homepage URL
* Added ignore/unignore menu items to add/remove a syscall from the list of the syscalls to intercept

![About dialog for gpTrace 0.1.3](/resources/gptrace/archive/v0.1.3/english/about.png)

# Version 0.1.2 (Jun 2, 2014)

* Added filtering menu to hide or show only the selected syscall

# Version 0.1.1 (Jun 2, 2014)

* Replaced the GtkButtonFileChooser with a GtkEntry and a GtkButton

![Main window for gpTrace 0.1.1](/resources/gptrace/archive/v0.1.1/english/main.png)

# Version 0.1.0 (May 4, 2014)

* First public release

![Main window for gpTrace 0.1.0](/resources/gptrace/archive/v0.1.0/english/main.png)

# Version 0.0.6 (May 1, 2014)

* Added a button to start and cancel tracing. The tracing is not automatically anymore started when a file is executed
* Added menu item to clear the result list immediately
* Added option item to automatically clear the results on tracing startup

# Version 0.0.5 (Apr 28, 2014)

* Added format column
* Added option menu to set column visibility

# Version 0.0.4 (Apr 27, 2014)

* Added selected intercepted syscalls count
* Main window closing speed-up by hiding it immediately
* Moved the debugger options from SyscallTracer to MainWindow

# Version 0.0.3 (Apr 26, 2014)

* Automatic save and restore of intercepted syscalls list
* Added selection of syscalls with filename/pathname arguments and socket related
* Added forked process support

# Version 0.0.2 (Apr 21, 2014)

* Added a list for syscalls to intercept
* Added PID and IP (Instruction Pointer) column in the results list

# Version 0.0.1 (Apr 13, 2014)

* Initial release
