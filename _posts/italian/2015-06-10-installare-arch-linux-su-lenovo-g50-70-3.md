---
title: Installare Arch Linux su Lenovo G50-70 (parte 3 - partizionamento del disco)
category: italian
tags:
  - arch linux
  - documentation
summary: Installare Arch Linux su Lenovo IdeaPad G50-70 con UEFI e Secure Boot
keywords: arch, linux, lenovo, ideapad, g50-70, partizionamento, disco, swap, ext4, file system, formattazione, parted, gdisk
---

{: .center}
![arch-linux-prompt.png]

Il processo di installazione di Arch Linux è differente dal processo di installazione
di altre distribuzioni GNU/Linux come Debian, Ubuntu, OpenSUSE o Fedora. Si
tratta infatti di un'installazione manuale del sistema operativo minimale che
richiede ogni singola messa a punto prima di fornire un sistema completo e
usabile.

Per ulteriori dettagli sul processo di installazione consultare la guida online
[Beginner's guide]{:target="_blank"}.

-----

#Partizionamento iniziale

Il ridimensionamento della partizione di Windows per far posto alle nuove
partizioni per Arch Linux non viene trattato in questa guida e va eseguito prima
di procedere all'installazione di Arch Linux.

Personalmente ho utilizzato **[gParted]{:target="_blank"}** per ridurre la
dimensione di Windows 8 e spostarla alla fine del disco, dove le prestazioni
del disco sono più lente rispetto la parte iniziale dello stesso disco.

Se non vi è necessità di spostare la partizione di Windows ma soltanto di
ridurla è possibile utilizzare la gestione disco di Windows.

##Partizionamento iniziale visto da Gestione disco

{: .center}
![windows-gestione-disco.png]

##Partizionamento iniziale visto da gdisk

    root@archiso ~ # gdisk -l /dev/sda
    GPT fdisk (gdisk) version 1.0.0

    Partition table scan:
      MBR: protective
      BSD: not present
      APM: not present
      GPT: present

    Found valid GPT with protective MBR; using GPT.
    Disk /dev/sda: 1953525168 sectors, 931.5 GiB
    Logical sector size: 512 bytes
    Disk identifier (GUID): D351D50F-EC1E-4048-9ED6-9A076FAA0298
    Partition table holds up to 128 entries
    First usable sector is 34, last usable sector is 1953525134
    Partitions will be aligned on 2048-sector boundaries
    Total free space is 1671431533 sectors (797.0 GiB)

    Number  Start (sector)    End (sector)  Size       Code  Name
       1            2048         2050047   1000.0 MiB  2700  Basic data partition
       2         2050048         2582527   260.0 MiB   EF00  EFI system partition
       3         2582528         4630527   1000.0 MiB  ED01  Basic data partition
       4         4630528         4892671   128.0 MiB   0C01  Microsoft reserved ...
       5      1676320768      1840160767   78.1 GiB    0700  Basic data partition
       6      1840160768      1922080767   39.1 GiB    0700  Basic data partition
       7      1922080768      1953523711   15.0 GiB    2700  Basic data partition

##Partizionamento iniziale visto da parted

    root@archiso ~ # parted -l /dev/sda
    Model: ATA WDC WD10JPCX-24U (scsi)
    Disk /dev/sda: 1000GB
    Sector size (logical/physical): 512B/4096B
    Partition Table: gpt
    Disk Flags: 

    Number  Start   End     Size    File system     Name                          Flags
     1      1049kB  1050MB  1049MB  ntfs            Basic data partition          hidden, diag
     2      1050MB  1322MB  273MB   fat32           EFI system partition          boot, hidden, esp
     3      1322MB  2371MB  1049MB  fat32           Basic data partition          hidden
     4      2371MB  2505MB  134MB                   Microsoft reserved partition  msftres
     5      858GB   942GB   83.9GB  ntfs            Basic data partition          msftdata
     6      942GB   984GB   41.9GB  ntfs            Basic data partition          msftdata
     7      984GB   1000GB  16.1GB  ntfs            Basic data partition          hidden, diag

-----

#Aggiunta delle partizioni necessarie

Per il partizionamento del disco sarà utilizzato il comando parted

    root@archiso ~ # parted /dev/sda
    GNU Parted 3.2
    Using /dev/sda
    Welcome to GNU Parted! Type 'help' to view a list of commands.
    (parted)

##Creazione della partizione root

La **partizione root** conterrà tutti i dati del sistema operativo, i programmi,
kernel, librerie e i dati variabili come log, liste dei pacchetti e altro.

Sarà creata una partizione da **30 GB**, più che sufficiente per le normali
esigenze.

    (parted) mkpart
    Partition name?  []? 
    File system type?  [ext2]? ext4
    Start? 2505M
    End? 33225M

    (parted) print
    Model: ATA WDC WD10JPCX-24U (scsi)
    Disk /dev/sda: 1000GB
    Sector size (logical/physical): 512B/4096B
    Partition Table: gpt
    Disk Flags: 

    Number  Start   End     Size    File system     Name                          Flags
     1      1049kB  1050MB  1049MB  ntfs            Basic data partition          hidden, diag
     2      1050MB  1322MB  273MB   fat32           EFI system partition          boot, hidden, esp
     3      1322MB  2371MB  1049MB  fat32           Basic data partition          hidden
     4      2371MB  2505MB  134MB                   Microsoft reserved partition  msftres
     8      2505MB  33.2GB  30.7GB  ext4
     5      858GB   942GB   83.9GB  ntfs            Basic data partition          msftdata
     6      942GB   984GB   41.9GB  ntfs            Basic data partition          msftdata
     7      984GB   1000GB  16.1GB  ntfs            Basic data partition          hidden, diag

    (parted) name 8 "Arch Linux root"

##Creazione della partizione home

La **partizione home** conterrà tutti i dati personali dell'utente, i file
scaricati, le preferenze e tutto quanto non provenga direttamente
dall'installazione dei pacchetti del software.

Sarà creata una partizione di **117 GB**, l'esigenza reale dipende
dall'utilizzatore.

    (parted) mkpart
    Partition name?  []? 
    File system type?  [ext2]? ext4
    Start? 33.2G
    End? 150G

    (parted) print
    Model: ATA WDC WD10JPCX-24U (scsi)
    Disk /dev/sda: 1000GB
    Sector size (logical/physical): 512B/4096B
    Partition Table: gpt
    Disk Flags: 

    Number  Start   End     Size    File system     Name                          Flags
     1      1049kB  1050MB  1049MB  ntfs            Basic data partition          hidden, diag
     2      1050MB  1322MB  273MB   fat32           EFI system partition          boot, hidden, esp
     3      1322MB  2371MB  1049MB  fat32           Basic data partition          hidden
     4      2371MB  2505MB  134MB                   Microsoft reserved partition  msftres
     8      2505MB  33.2GB  30.7GB  ext4            Arch Linux root
     9      33.2GB  150GB   117GB   ext4
     5      858GB   942GB   83.9GB  ntfs            Basic data partition          msftdata
     6      942GB   984GB   41.9GB  ntfs            Basic data partition          msftdata
     7      984GB   1000GB  16.1GB  ntfs            Basic data partition          hidden, diag

    (parted) name 9 "Home"

##Creazione della partizione swap

La **partizione swap** fornisce un'area di memoria volatile aggiuntiva alla
memoria RAM, per scaricare su disco parti di memoria inutilizzate e per offrire
quindi una capacità di memoria di dimensioni superiori, naturalmente al costo
delle prestazioni, essendo il disco rigido assai più lento della RAM.

Verrà creata una partizione swap di **6 GB**, la stessa quantità di memoria
della RAM, al fine di permettere la conservazione della RAM su swap, utile per
l'operazione di sospensione (detta anche ibernazione).

    (parted) mkpart                                                           
    Partition name?  []? 
    File system type?  [ext2]? linux-swap
    Start? 852G
    End? 858G

    (parted) print
    Model: ATA WDC WD10JPCX-24U (scsi)
    Disk /dev/sda: 1000GB
    Sector size (logical/physical): 512B/4096B
    Partition Table: gpt
    Disk Flags: 

    Number  Start   End     Size    File system     Name                          Flags
     1      1049kB  1050MB  1049MB  ntfs            Basic data partition          hidden, diag
     2      1050MB  1322MB  273MB   fat32           EFI system partition          boot, hidden, esp
     3      1322MB  2371MB  1049MB  fat32           Basic data partition          hidden
     4      2371MB  2505MB  134MB                   Microsoft reserved partition  msftres
     8      2505MB  33.2GB  30.7GB  ext4            Arch Linux root
     9      33.2GB  150GB   117GB   ext4
    10      852GB   858GB   6276MB  linux-swap(v1)
     5      858GB   942GB   83.9GB  ntfs            Basic data partition          msftdata
     6      942GB   984GB   41.9GB  ntfs            Basic data partition          msftdata
     7      984GB   1000GB  16.1GB  ntfs            Basic data partition          hidden, diag

    (parted) name 10 "Swap 6 GB"

##Verifica del partizionamento con parted

Al termine delle operazioni verificare il partizionamento ottenuto. Per ogni
partizione creata eseguire il comando **align-check optimal** per verificare
che la partizione sia allineata correttamente.

Un errato allineamento delle partizioni può causare un forte degrado delle
prestazioni, soprattutto in fase di scrittura dei dati. Per ulteriori informazioni:
[Linux on 4KB-sector disks: Practical advice]{:target="_blank"} e
[Transition to Advanced Format 4K Sector Hard Drives]{:target="_blank"}.

    (parted) print                                                            
    Model: ATA WDC WD10JPCX-24U (scsi)
    Disk /dev/sda: 1000GB
    Sector size (logical/physical): 512B/4096B
    Partition Table: gpt
    Disk Flags: 

    Number  Start   End     Size    File system     Name                          Flags
     1      1049kB  1050MB  1049MB  ntfs            Basic data partition          hidden, diag
     2      1050MB  1322MB  273MB   fat32           EFI system partition          boot, hidden, esp
     3      1322MB  2371MB  1049MB  fat32           Basic data partition          hidden
     4      2371MB  2505MB  134MB                   Microsoft reserved partition  msftres
     8      2505MB  33.2GB  30.7GB                  Arch Linux root
     9      33.2GB  150GB   117GB                   Home
    10      852GB   858GB   6276MB  linux-swap(v1)  Swap 6 GB
     5      858GB   942GB   83.9GB  ntfs            Basic data partition          msftdata
     6      942GB   984GB   41.9GB  ntfs            Basic data partition          msftdata
     7      984GB   1000GB  16.1GB  ntfs            Basic data partition          hidden, diag

    (parted) align-check optimal 8
    8 aligned

    (parted) align-check optimal 9
    9 aligned

    (parted) align-check optimal 10
    10 aligned

    (parted) quit

##Verifica del partizionamento con gdisk

Eseguire le stesse verifiche con gdisk confermerà che tutte le partizioni sono
allineate correttamente.

    root@archiso ~ # gdisk /dev/sda
    GPT fdisk (gdisk) version 1.0.0

    Partition table scan:
      MBR: protective
      BSD: not present
      APM: not present
      GPT: present

    Found valid GPT with protective MBR; using GPT.

    Command (? for help): p
    Disk /dev/sda: 1953525168 sectors, 931.5 GiB
    Logical sector size: 512 bytes
    Disk identifier (GUID): D351D50F-EC1E-4048-9ED6-9A076FAA0298
    Partition table holds up to 128 entries
    First usable sector is 34, last usable sector is 1953525134
    Partitions will be aligned on 2048-sector boundaries
    Total free space is 1375544685 sectors (655.9 GiB)

    Number  Start (sector)    End (sector)  Size       Code  Name
       1            2048         2050047   1000.0 MiB  2700  Basic data partition
       2         2050048         2582527   260.0 MiB   EF00  EFI system partition
       3         2582528         4630527   1000.0 MiB  ED01  Basic data partition
       4         4630528         4892671   128.0 MiB   0C01  Microsoft reserved ...
       5      1676320768      1840160767   78.1 GiB    0700  Basic data partition
       6      1840160768      1922080767   39.1 GiB    0700  Basic data partition
       7      1922080768      1953523711   15.0 GiB    2700  Basic data partition
       8         4892672        64892927   28.6 GiB    8300  Arch Linux root
       9        64892928       292968447   108.8 GiB   8300  Home
      10      1664063488      1676320767   5.8 GiB     8200  Swap 6 GB

    Command (? for help): v

    No problems found. 1371098477 free sectors (653.8 GiB) available in 3
    segments, the largest of which is 1371095040 (653.8 GiB) in size.

    Command (? for help): q

-----

#Formattazione delle nuove partizioni

Dopo il partizionamento è necessario formattare le nuove partizioni come segue:

##Formattazione della partizione root

Per la partizione root sarà riservato l'1% dello spazio (**-m 1**) all'utente
root, ciò per evitare che un uso errato di un log possa riempire completamente
la partizione.

    root@archiso ~ # mke2fs -L Root -m 1 /dev/sda8 
    mke2fs 1.42.12 (29-Aug-2014)
    Creating filesystem with 7500032 4k blocks and 1875968 inodes
    Filesystem UUID: 2cce8139-2aa7-415a-811a-0830dd16614b
    Superblock backups stored on blocks: 
      32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208, 
      4096000

    Allocating group tables: done
    Writing inode tables: done
    Writing superblocks and filesystem accounting information: done

##Formattazione della partizione home

Per la partizione home non sarà necessario riservare spazio all'utente root,
pertanto verrà indicata la percentuale dello 0% (**-m 0**).

    root@archiso ~ # mke2fs -L Home -m 0 /dev/sda9
    mke2fs 1.42.12 (29-Aug-2014)
    Creating filesystem with 28509440 4k blocks and 7135232 inodes
    Filesystem UUID: d96414ef-54eb-42e6-acab-612a9689c7b4
    Superblock backups stored on blocks: 
      32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208, 
      4096000, 7962624, 11239424, 20480000, 23887872

    Allocating group tables: done
    Writing inode tables: done
    Writing superblocks and filesystem accounting information: done

##Formattazione della partizione swap

    root@archiso ~ # mkswap -L "Swap_6_GB" /dev/sda10
    Setting up swapspace version 1, size = 5.9 GiB (6275723264 bytes)
    LABEL=Swap_6_GB, UUID=6290142a-f101-4e39-acbd-71dc33d259eb

-----

#Montaggio delle nuove partizioni

Prima di procedere al montaggio effettivo delle partizioni è necessario conoscere
quale sia la partizione contenente i file di avvio di Windows, la cosiddetta
**EFI System Partition** ([ESP]{:target="_blank"}).

Utilizzare il comando **blkid** per conoscere l'elenco delle partizioni
disponibili, con alcuni dettagli:

    root@archiso ~ # blkid
    /dev/sda1: LABEL="WINRE_DRV" UUID="12D02132D0211E0B" TYPE="ntfs" PARTLABEL="Basic data partition" PARTUUID="c714930a-c127-4c77-af04-c6039c287a09"
    /dev/sda2: LABEL="SYSTEM_DRV" UUID="2223-7318" TYPE="vfat" PARTLABEL="EFI system partition" PARTUUID="9ec6d731-187b-49bc-9c96-0ac6b5c1ff39"
    /dev/sda3: LABEL="LRS_ESP" UUID="7627-2E57" TYPE="vfat" PARTLABEL="Basic data partition" PARTUUID="3b3d4cf2-708b-404b-9efb-6e3c36eb5138"
    /dev/sda4: PARTLABEL="Microsoft reserved partition" PARTUUID="c00b39af-21fe-4e8b-bd6e-3f273e495df9"
    /dev/sda5: LABEL="Windows8_OS" UUID="FC9459FD522A6F69" TYPE="ntfs" PARTLABEL="Basic data partition" PARTUUID="9e2ce587-2013-44b4-ae94-d47e68644c6d"
    /dev/sda6: LABEL="LENOVO" UUID="02986FF1986FE1A1" TYPE="ntfs" PARTLABEL="Basic data partition" PARTUUID="260417ff-f9bc-4891-9eba-767261b7b911"
    /dev/sda7: LABEL="PBR_DRV" UUID="A26E2E086E2DD637" TYPE="ntfs" PARTLABEL="Basic data partition" PARTUUID="363328b1-2ac2-498a-89f0-6ecf748eba13"
    /dev/sda8: LABEL="Root" UUID="2cce8139-2aa7-415a-811a-0830dd16614b" TYPE="ext2" PARTLABEL="Arch Linux root" PARTUUID="c373fa58-8231-41ed-a8df-18e146c34b74"
    /dev/sda9: LABEL="Home" UUID="d96414ef-54eb-42e6-acab-612a9689c7b4" TYPE="ext2" PARTLABEL="Home" PARTUUID="f8c71f05-6f81-49bd-89f4-922e71981068"
    /dev/sda10: LABEL="Swap_6_GB" UUID="6290142a-f101-4e39-acbd-71dc33d259eb" TYPE="swap" PARTLABEL="Swap 6 GiB" PARTUUID="5eb12670-289d-4ab2-98d6-fad7317b4e02"
    /dev/sdb1: LABEL="ARCH_201506" UUID="B2C1-A2B9" TYPE="vfat" PARTUUID="001381f5-01"
    /dev/loop0: TYPE="squashfs"
    /dev/loop1: UUID="a0b8124e-507a-4c5a-bfc9-79e306898aa2" TYPE="ext4"
    /dev/mapper/arch_airootfs: UUID="a0b8124e-507a-4c5a-bfc9-79e306898aa2" TYPE="ext4"

L'ESP predefinita in questo computer è la partizione /dev/sda2, mentre la
partizione /dev/sda3 contiene i file di avvio del sistema di ripristino di Lenovo
(LRS_ESP = Lenovo Recovery System ESP).

Per ulteriori dettagli sul significato delle varie partizioni consultare la
pagina [Lenovo Yoga Pro 2 Partition Cleanup]{:target="_blank"}.

E' infine possibile montare le nuove partizioni root, boot e home.

    root@archiso ~ # mount /dev/sda8 /mnt
    root@archiso ~ # mkdir /mnt/boot
    root@archiso ~ # mount /dev/sda2 /mnt/boot 
    root@archiso ~ # mkdir /mnt/home          
    root@archiso ~ # mount /dev/sda9 /mnt/home 

[arch-linux-prompt.png]: /resources/articles/2015-06/arch-linux-prompt.png
[windows-gestione-disco.png]: /resources/articles/2015-06/windows-gestione-disco.png

[Beginner's guide]: https://wiki.archlinux.org/index.php/Beginners%27_guide
[gParted]: http://gparted.org/
[Linux on 4KB-sector disks: Practical advice]: http://www.ibm.com/developerworks/linux/library/l-4kb-sector-disks/
[Transition to Advanced Format 4K Sector Hard Drives]: http://www.seagate.com/tech-insights/advanced-format-4k-sector-hard-drives-master-ti/
[ESP]: https://en.wikipedia.org/wiki/EFI_System_partition
[Lenovo Yoga Pro 2 Partition Cleanup]: http://www.lionhack.com/2013/12/25/lenovo-yoga-2-pro-partitions/
