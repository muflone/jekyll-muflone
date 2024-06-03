---
layout: changelog
order: 900
title: Changelog
---
# Version 0.8.6 (Aug 2, 2015)

* Updated translations

# Version 0.8.5 (Oct 4, 2014)

* Updated translations

# Version 0.8.4 (Sep 6, 2014)

* Updated translations

# Version 0.8.3 (Aug 31, 2014)

* Updated translations
* New Arabic translation by M I
* New Vietnamese translation by Anh Phan
* New Turkish translation by Necdet Yücel

# Version 0.8.2 (Oct 17, 2010)

* Removed the plugins amsn, emesene, kopete, pidgin, telepathy
  They were moved to another source repository for separated maintenance and
  versioning
* Added handlepaths to EspeakFrontend.py
* If the specified MBROLA folder doesn't exist fallback to the default path
* Switch to the new mbrola and espeak versions
* New German translation by Heinrich Schwietering
* New Faroese translation by Gunleif Joensen
* Fixed handling of broken symlinks for amsn and emesene plugins

# Version 0.8.1 (Jun 26, 2010)

* New bulgarian translation by Svetoslav Stefanov
* User configuration moved in XDG_CONFIG_HOME instead of previous hardcoded
  folder (sorry for your saved settings)
* New plugins architecture
* Moved dbus, save voice settings, save window size, welcome message in external
  plugins
* New command-line features
* Stop previous play on quit (moved on external plugin)
* New plugins: debug, save window position
* New plugins minimal configuration in preferences dialog
* New Telepathy, Pidgin, Emesene, Kopete and aMSN plugins

# Version 0.8 (Jun 13, 2010)

* Moved translators from .po files to doc/translators
* New Polish translation by Andrey J
* New DBUS interface to interact from external apps
* Fixed minimum words gap from 5 to 0 in main UI

![About dialog for Gespeaker 0.8](/resources/gespeaker/archive/v0.8/english/about.png)

# Version 0.7 (Dic 13, 2009)

* New handlepaths module to reflect the changed directory structure
* New setup.py for distutils installation
* New packaging following the Debian policy

![About dialog for Gespeaker 0.7](/resources/gespeaker/archive/v0.7/english/about.png)

# Version 0.6 (Jul 18, 2009)

* Fixed audio testing localized string
* An error message is now shown if the audio player is not found instead of
  quietly ignore the error
* New spanish translation provided by David Prieto
* New MBROLA support with more realistic voices
* Added MBROLA voices to languages list
* Tabbed preferences dialog for new MBROLA support
* Moved language, voice type and variants to base settings and pitch, volume,
  speed and gap sliders to advanced settings upon suggestion of frandavid100
* Added automatic txt extension on saving text file
* Added automatic wav extension on saving WAVE file 
  This was causing weird noises on playing the recorded track if it wasn't a
  .wav filename

![Main window for Gespeaker 0.6](/resources/gespeaker/archive/v0.6/english/main.jpg)

![Preferences window for MBROLA for Gespeaker 0.6](/resources/gespeaker/archive/v0.6/english/mbrola.jpg)

# Version 0.5 (Jun 30, 2009)

* Added an extender separator for settings to allow maximum usage of the window
  with the text
* Added filters for load/save text dialogs
* Added support for recording the audio track to wave
* Added a statusbar showing the active record mode
* Added preferences dialog
* Added preferences save and reload for welcome message, window size, voice
  settings and expander status
* Added support for audio frontend: ```ALSA``` (aplay), ```PulseAudio```
  (paplay) and user customized player command, with audio command test
* Added voice variants by scanning ```/usr/share/espeak-data/voices/!v```
  folder for extra voice variants
* Fixed stock icon for ```DialogFileOpenSave```

![Main window for Gespeaker 0.5](/resources/gespeaker/archive/v0.5/english/main.png)

![Preferences window for Gespeaker 0.5](/resources/gespeaker/archive/v0.5/english/preferences.png)

# Version 0.4 (Jun 20, 2009)

* Added ```SubprocessWrapper.Popen``` to wrap subprocess.Popen in order to
  support python versions prior to 2.6 which don't have the delete argument on
  object creation
* Added ```TempfileWrapper.NamedTemporaryFile``` to wrap tempfile's Popen
  object in order to support python versions prior to 2.6 which don't have
  terminate and send_signal methods
  Actually no more used, left for future usage
* Now Gespeaker works with python version 2.4 and higher
* Temporary file for output to speech is created at program start so new
  temporary files are no longer created after each play
* Included pause and resume features
* New icon and logo, kindly provided by MIX
* New french translation provided by Emmanuel

![Main window for Gespeaker 0.4](/resources/gespeaker/archive/v0.4/english/main.png)

# Version 0.3 (Jun 18, 2009)

* Used only for testing, never released
* Added support for voice type (male/female) via +12 for female voice
* Removed escaped text substitution with a more secure temporary file with the
  text to play
* Substituted direct shell piping with more secure subprocess' piping
* Better control of external calls, now both espeak and player execution are
  polled for exitcode and terminated if requested
* Added documentation and artists parameters to ```DialogAbout```

# Version 0.2 (Jun 14, 2009)

* Changed UI layout according to
  [GNOME 2.32 HIG specifications][GNOME HIG specifications]
* Fixed ```DialogAbout.set_icon_from_file``` icon usage, which was wrongly
  hardcoded
* Symlinked copyright file to ```/usr/share/doc/gespeaker/copyright```

![Main window for Gespeaker 0.2](/resources/gespeaker/archive/v0.2/english/main.png)

# Version 0.1 (Jun 13, 2009)

* Initial release

![Main window for Gespeaker 0.1](/resources/gespeaker/archive/v0.1/english/main.jpg)

{: target="_blank" .external }
[GNOME HIG specifications]: https://developer.gnome.org/hig-book/2.32/design-window.html.en
