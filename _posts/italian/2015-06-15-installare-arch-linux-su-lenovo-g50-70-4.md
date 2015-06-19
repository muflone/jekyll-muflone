---
title: Installare Arch Linux su Lenovo G50-70 (parte 4 - installazione del sistema)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot
keywords: arch, linux, lenovo, ideapad, g50-70, rete, wifi, wlan, rfkill, pacstrap, install, packages
---

{: .center}
![arch-linux-prompt.png]

E' adesso possibile procedere all'installazione del sistema di base, nelle
partizioni montate in precedenza su **/mnt** e configurare il computer per
l'avvio dal nuovo sistema.

## Installazione dei pacchetti del sistema di base

    root@archiso ~ # pacstrap /mnt base
    ==> Creating install root at /mnt
    ==> Installing packages to /mnt
    :: Synchronizing package databases...
     core                             122.3 KiB   243K/s 00:01 [####################################] 100%
     extra                           1738.6 KiB   227K/s 00:08 [####################################] 100%
     community                          2.7 MiB   225K/s 00:12 [####################################] 100%
    :: There are 50 members in group base:
    :: Repository core
       1) bash  2) bzip2  3) coreutils  4) cryptsetup  5) device-mapper  6) dhcpcd  7) diffutils  8) e2fsprogs
       9) file  10) filesystem  11) findutils  12) gawk  13) gcc-libs  14) gettext  15) glibc  16) grep
       17) gzip  18) inetutils  19) iproute2  20) iputils  21) jfsutils  22) less  23) licenses  24) linux
       25) logrotate  26) lvm2  27) man-db  28) man-pages  29) mdadm  30) nano  31) netctl  32) pacman
       33) pciutils  34) pcmciautils  35) perl  36) procps-ng  37) psmisc  38) reiserfsprogs  39) s-nail
       40) sed  41) shadow  42) sysfsutils  43) systemd-sysvcompat  44) tar  45) texinfo  46) usbutils
       47) util-linux  48) vi  49) which  50) xfsprogs

    Enter a selection (default=all): 
    resolving dependencies...
    looking for conflicting packages...
    warning: dependency cycle detected:
    warning: ncurses will be installed before its bash dependency

    Packages (123) acl-2.2.52-2  archlinux-keyring-20150605-1  attr-2.4.47-1  ca-certificates-20150402-1 
                   ca-certificates-cacert-20140824-2  ca-certificates-mozilla-3.19.1-1
                   ca-certificates-utils-20150402-1  cracklib-2.9.4-1  curl-7.42.1-1  db-5.3.28-2
                   dbus-1.8.18-1  expat-2.1.0-4  gdbm-1.11-1  glib2-2.44.1-1  gmp-6.0.0-2 gnupg-2.1.5-1
                   gnutls-3.4.1-1  gpgme-1.5.4-1  groff-1.22.3-3  hwids-20150129-1  iana-etc-2.30-5
                   iptables-1.4.21-3  kbd-2.0.2-1  keyutils-1.5.9-1  kmod-20-1  krb5-1.13.1-1
                   libaio-0.3.110-1  libarchive-3.1.2-8  libassuan-2.2.0-1  libcap-2.24-2  libdbus-1.8.18-1
                   libffi-3.2.1-1  libgcrypt-1.6.3-2  libgpg-error-1.19-1  libidn-1.30-1  libksba-1.3.3-1
                   libldap-2.4.40-2  libpipeline-1.4.0-1  libsasl-2.1.26-7  libseccomp-2.2.0-1
                   libssh2-1.5.0-1  libsystemd-219-6  libtasn1-4.5-1  libtirpc-0.3.1-1  libunistring-0.9.5-1
                   libusb-1.0.19-1  libutil-linux-2.26.2-1  linux-api-headers-4.0-1
                   linux-firmware-20150527.3161bfa-1  lz4-130-1  lzo-2.09-1  mkinitcpio-18-2
                   mkinitcpio-busybox-1.21.1-2  mpfr-3.1.2.p11-1  ncurses-5.9-7  nettle-3.1.1-1  npth-1.2-1
                   openresolv-3.7.0-1  openssl-1.0.2.c-1  p11-kit-0.23.1-2  pacman-mirrorlist-20150531-1
                   pam-1.2.0-1  pambase-20130928-1  pcre-8.37-2  pinentry-0.9.1-1  popt-1.16-7  pth-2.0.7-5
                   readline-6.3.008-1  systemd-219-6  thin-provisioning-tools-0.4.1-1  tzdata-2015d-1
                   xz-5.2.1-1  zlib-1.2.8-4  bash-4.3.039-1  bzip2-1.0.6-5  coreutils-8.23-2
                   cryptsetup-1.6.6-1  device-mapper-2.02.116-1  dhcpcd-6.9.0-1  diffutils-3.3-2
                   e2fsprogs-1.42.12-2  file-5.22-1  filesystem-2015.02-1  findutils-4.4.2-6  gawk-4.1.3-1
                   gcc-libs-5.1.0-4  gettext-0.19.4-1  glibc-2.21-4  grep-2.21-2  gzip-1.6-1
                   inetutils-1.9.3-1  iproute2-4.0.0-2  iputils-20140519.fad11dc-1  jfsutils-1.1.15-4
                   less-471-1  licenses-20140629-1  linux-4.0.5-1  logrotate-3.8.9-1  lvm2-2.02.116-1
                   man-db-2.7.1-1  man-pages-4.00-1  mdadm-3.3.2-2  nano-2.4.1-1  netctl-1.10-2
                   pacman-4.2.1-1  pciutils-3.3.1-1  pcmciautils-018-7  perl-5.20.2-1  procps-ng-3.3.10-2
                   psmisc-22.21-2  reiserfsprogs-3.6.24-1  s-nail-14.8.1-1  sed-4.2.2-3  shadow-4.2.1-3
                   sysfsutils-2.1.0-9  systemd-sysvcompat-219-6  tar-1.28-1  texinfo-5.2-3  usbutils-008-1
                   util-linux-2.26.2-1  vi-1:070224-1  which-2.21-1  xfsprogs-3.2.2-1

    Total Download Size:   166.57 MiB
    Total Installed Size:  512.80 MiB

    :: Proceed with installation? [Y/n] 
    :: Retrieving packages ...
     linux-api-headers-4.0-1-x86_64   757.5 KiB   229K/s 00:03 [####################################] 100%
     tzdata-2015d-1-any               213.5 KiB   226K/s 00:01 [####################################] 100%
      ...

    (123/123) checking keys in keyring                         [####################################] 100%
    (123/123) checking package integrity                       [####################################] 100%
    (123/123) loading package files                            [####################################] 100%
    (123/123) checking for file conflicts                      [####################################] 100%
    (123/123) checking available disk space                    [####################################] 100%
    (  1/123) installing linux-api-headers                     [####################################] 100%
    (  2/123) installing tzdata                                [####################################] 100%
      ...
    (123/123) installing xfsprogs                              [####################################] 100%
    pacstrap /mnt base  21.48s user 1.69s system 80% cpu 28.886 total

## Completare l'installazione di base

Per inizializzare il file **/etc/fstab** con i riferimenti alle nuove partizioni
eseguire il comando **genfstab**.

L'argomento **-L** è usato per utilizzare le etichette (Label) dei file system,
usate durante la formattazione delle partizioni. In alternativa è possibile
utilizzare l'argomento **-U** che identifica l'uso degli UUID (Universally
Unique IDentifier).

    root@archiso ~ # genfstab -L -p /mnt >> /mnt/etc/fstab 

## Accedere alla nuova root e configurare il sistema

Sarà adesso possibile accedere alla nuova installazione prima del riavvio per
completare alcune messe a punto iniziali.

    root@archiso ~ # arch-chroot /mnt
    sh-4.3# 

## Configurazione del nome del computer

Assegnare quindi un nome al computer, col quale il sistema sarà identificato
all'interno della rete.

    sh-4.3# echo arch-lenovo > /etc/hostname

## Impostazione del fuso orario

Specificare quindi il fuso orario italiano, in questo caso **Europe/Rome**,
utile per traslare l'orologio di sistema nell'orario corrente.

    sh-4.3# ln -sf /usr/share/zoneinfo/Europe/Rome /etc/localtime

## Configurazione del locale

Il locale si occupa della traduzione dei programmi e di una serie di impostazioni
linguistiche.

All'interno del file **/etc/locale.gen** sono presenti tutti i locale disponibili,
basterà modificare questo file (ad esempio con **nano /etc/locale.gen**)
togliendo i simboli # per attivare un layout.

L'istruzione sottostante attiva direttamente la lingua italiana senza dover
modificare manualmente il file locale.gen.

    sh-4.3# sed -i 's/^#it_IT.UTF-8/it_IT.UTF-8/' /etc/locale.gen
    
    sh-4.3# echo LANG=it_IT.UTF-8 > /etc/locale.conf
    
    sh-4.3# locale-gen 
    Generating locales...
      it_IT.UTF-8... done
    Generation complete.

## Configurazione della tastiera italiana

Affinché venga caricata la tastiera lingua italiana ad ogni riavvio è necessario
indicare il layout di tastiera nel file **/etc/vconsole.conf**.

    sh-4.3# echo KEYMAP=it > /etc/vconsole.conf

## Installazione dei pacchetti per la configurazione di rete

L'immagine di installazione del sistema operativo contiene al suo interno gli
strumenti per la
[configurazione della rete Wi-Fi]({% post_url italian/2015-06-09-installare-arch-linux-su-lenovo-g50-70-2 %})
ma l'installazione minimale non include questi strumenti, per cui è necessario
installarli esplicitamente.

    sh-4.3# pacman -S dialog wpa_supplicant rfkill iw
    resolving dependencies...
    looking for conflicting packages...

    Packages (5) libnl-3.2.25-1  dialog-1:1.2_20150528-1  rfkill-0.5-1  wpa_supplicant-1:2.3-1  iw-3.17-1

    Total Download Size:   1.09 MiB
    Total Installed Size:  3.42 MiB

    :: Proceed with installation? [Y/n] 
    :: Retrieving packages ...
     dialog-1:1.2_20150528-1-x86_64   167.6 KiB   237K/s 00:01 [####################################] 100%
     libnl-3.2.25-1-x86_64            262.1 KiB   226K/s 00:01 [####################################] 100%
     wpa_supplicant-1:2.3-1-x86_64    625.7 KiB   224K/s 00:03 [####################################] 100%
     rfkill-0.5-1-x86_64                6.5 KiB   922K/s 00:00 [####################################] 100%
     iw-3.17-1-x86_64                  52.4 KiB   257K/s 00:00 [####################################] 100%
    (5/5) checking keys in keyring                             [####################################] 100%
    (5/5) checking package integrity                           [####################################] 100%
    (5/5) loading package files                                [####################################] 100%
    (5/5) checking for file conflicts                          [####################################] 100%
    (5/5) checking available disk space                        [####################################] 100%
    (1/5) installing dialog                                    [####################################] 100%
    (2/5) installing libnl                                     [####################################] 100%
    (3/5) installing wpa_supplicant                            [####################################] 100%
    Optional dependencies for wpa_supplicant
        wpa_supplicant_gui: wpa_gui program
    (4/5) installing rfkill
    (5/5) installing iw

## Impostazione della password di root

L'utente **root** fino a questo momento è rimasto senza password, è bene
configurare da subito una password da assegnargli. Dopo il comando **passwd**
scrivere la password desiderata e ripeterla. **Non saranno mostrati asterischi**
durante la digitazione della password, è necessario scriverla alla cieca quando
richiesta.

    sh-4.3# passwd
    Enter new UNIX password: 
    Retype new UNIX password: 
    passwd: password updated successfully


[arch-linux-prompt.png]: /resources/articles/2015-06/arch-linux-prompt.png
