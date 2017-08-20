---
layout: default
order: 6
title: MBROLA engine
---
# Introduction

Gespeaker supports two different speech engines: **espeak**, the default native
and **[MBROLA]**, an extra engine that offers more realistic voices.

It's possible to read the page
[Demo voices]({% link _gespeaker/english/demo.md %})
to listen some examples of both speech engines.

To use **espeak** no configuration is needed at all, Gespeaker will use it
natively, just to select the desired language and to set the voice settings.

# Installation of MBROLA

To use MBROLA install the package ```mbrola``` first and then install at least
one MBROLA voice like for example ```mbrola-en1``` or ```mbrola-us3```
(the exact package name to install depends from the distribution).

# MBROLA usage

{:.center}
![Preferences window for MBROLA](/resources/gespeaker/archive/latest/english/mbrola.png)

After installing the required packages check in the preferences window the
MBROLA voices tab to verify that the path of the voices is that where they were
installed and click the **Refresh** button to search the voices in the new path.
The default path for the MBROLA voices is ```/usr/share/mbrola```.

After installing the MBROLA voices or after changing the voices path a restart
of Gespeaker is needed to see the new voices.

{: target="_blank" }
[MBROLA]: http://tcts.fpms.ac.be/synthesis/