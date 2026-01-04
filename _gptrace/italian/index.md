---
layout: index
order: 100
title: Introduzione
---
**gpTrace** è un'applicazione libera basata sulle GTK+ per tracciare le
attività di un processo esterno.
Basterà scegliere il programma esterno da eseguire, premere il pulsante
**Esegui** ed osservare i risultati dell'operazione.
Ogni syscall (chiamata a funzione del sistema operativo) sarà mostrata ed ogni
processo esterno avviato sarà tracciato nella finestra di gpTrace.

{: .center }
![Finestra principale](/resources/gptrace/archive/latest/italian/main.png)
          
E' possibile decidere quali syscall intercettare per includere o escludere per
limitare i risultati.

{: .center }
![Finestra principale con elenco espanso](/resources/gptrace/archive/latest/italian/expanded.png)

Per ciascuna syscall intercettata si potrà vedere quante chiamate sono state
effettuate.

{: .center }
![Scheda Conteggi](/resources/gptrace/archive/latest/italian/counts.png)

Sarà anche possibile vedere un elenco di tutti i file richiesti
dall'applicazione, indipendentemente dalla loro esistenza.

{: .center }
![Scheda Files](/resources/gptrace/archive/latest/italian/files.png)

Se l'applicazione richiesta fa uso di processi multipli esterni sarà possibile
vedere l'elenco dei processi, incluse alcune informazioni basilari.

{: .center }
![Scheda Processi](/resources/gptrace/archive/latest/italian/processes.png)
