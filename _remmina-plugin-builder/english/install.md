---
layout: default
order: 201
title: Installation
---
# Build process

Unlike other softwares **Remmina Plugin Builder** is not meant to be installed
and run on your machine but it provides a development environment to build
plugins for Remmina.

Its purpose is to ease the process of building Remmina plugins, which at the
actual stage, would require the whole Remmina source code to simply build a plugin.
Using Remmina Plugin Builder the build process will simply require the plugin
source code files to be put into a specific folder and compile it with few commands.

# Prepare for the build

The prepare process simply needs the extraction of Remmina Plugin Builder source
code using:

```
cd "~/folder with the downloaded file"
mkdir build
tar xvzf "file name.tar.gz" -C build
cd build/remmina-plugin-builder-*
```

# Compile the plugin

Then you need to put the plugin source code into the **remmina-plugin-to-build**
folder and compile everything using:

```
cmake -DCMAKE_INSTALL_PREFIX=/usr .
make
```

If the previous commands don't return any errors you should read something like:

```
Scanning dependencies of target PLUGIN-NAME
[100%] Building C object remmina-plugin-to-build/PLUGIN-NAME/..o
Linking C shared library PLUGIN-NAME.so
[100%] Built target PLUGIN-NAME
```

The compiled plugin library can be found under
**remmina-plugin-to-build/PLUGIN-NAME** folder.

# Install the plugin

If you want to automatically install the plugin in your system you can use:
```
sudo make install
```

# Package the plugin

If you want to package the plugin instead of intall it in your system you can use:

```
make DESTDIR=FOLDER install
```

You should see something similar to:

```
[100%] Built target PLUGIN-NAME
Install the project...
-- Install configuration: "Release"
-- Installing: PACKAGE/usr/lib/remmina/plugins/PLUGIN-NAME.so
-- Installing: PACKAGE/usr/share/icons/hicolor/16x16/emblems/PLUGIN-NAME.png
-- Installing: PACKAGE/usr/share/icons/hicolor/22x22/emblems/PLUGIN-NAME.png
```

Finally you'll find the plugin library under the specified destination folder.
It's up to you to complete the rest of the package itself.

# Cleanup

After the installation/package phase the whole build folder can be removed.
