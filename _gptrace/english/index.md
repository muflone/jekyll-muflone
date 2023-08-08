---
layout: index
order: 100
title: Introduction
---
**gpTrace** is a free GTK+ application to trace the activities of an external
process.
You just need only to select an external application to launch, click on the
**Execute** button and view the results.
Every syscall (call to a operating system function) will be shown and every
external process will be traced in the gpTrace window.

{:.center}
![Main window](/resources/gptrace/archive/latest/english/main.png)
          
It's also possible to select which syscalls to intercept to include or exclude
in order to limit the results.

{:.center}
![Main window with expanded list](/resources/gptrace/archive/latest/english/expanded.png)

For each intercepted syscall you can see how many times a call is made.

{:.center}
![Counts page](/resources/gptrace/archive/latest/english/counts.png)

You can also see a list of any requested file from the application, regardless
of its existance.

{:.center}
![Files page](/resources/gptrace/archive/latest/english/files.png)

If the requested application makes use of external multiple processes you can
see the list of any processes, including some basic information.

{:.center}
![Processes](/resources/gptrace/archive/latest/english/processes.png)
