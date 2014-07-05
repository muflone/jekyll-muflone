---
title: File di inclusione e passaggio di argomenti
category: italian
tags:
  - jekyll
  - documentation
summary: File di inclusione e passaggio di argomenti.
---

Questa è la terza parte di una serie di articoli su 
[**Jekyll**](http://jekyllrb.com/), un generatore di siti web statici con
funzionalità di blog.
Durante la [prima parte]({% post_url italian/2014-06-30-benvenuto-jekyll %}) ho
presentato l'avvio rapido per create un sito web autogenerato minimale
utilizzando Jekyll mentre nella [seconda parte]({% post_url italian/2014-07-01-pagine-e-post %})
sono state mostrate le differenze tra pagine e post.

Ovunque più pagine o post richiedessero parti comuni di codice, anche con lievi
differenze nel loro utilizzo, un'ottima soluzione è quella di porre il codice
comune all'interno di un file di inclusione.

Ogni file salvato nella cartella **_include** potrà essere incluso all'interno
di un'altra pagina o post utilizzando:

{% highlight bash %}
{{ "{%" }} include nome_del_file %}
{% endhighlight %}

L'intero codice sarà copiato all'interno della pagina come se fosse stato
scritto all'interno della pagina. Ovviamente il file incluso può avere a sua
volta altre inclusioni oppure altri tag liquidi.

Se osserviamo il contenuto del file **_layouts/page.html** possiamo vedere:

{% highlight html %}
---
layout: default
---
<div class="post">

  <header class="post-header">
    <h1>{{ "{{" }} page.title }}</h1>
  </header>

  <article class="post-content">
  {{ "{{" }} content }}
  </article>

</div>
{% endhighlight %}

Il file predefinito **_layouts/post.html** invece contiene:
{% highlight html %}
---
layout: default
---
<div class="post">

  <header class="post-header">
    <h1>{{ "{{" }} page.title }}</h1>
    <p class="meta">{{ "{{" }} page.date | date: "%b %-d, %Y" }}{{ "{%" }} if page.author %} • {{ "{{" }} page.author }}{{ "{%" }} endif %}{{ "{%" }} if page.meta %} • {{ "{{" }} page.meta }}{{ "{%" }} endif %}</p>
  </header>

  <article class="post-content">
  {{ "{{" }} content }}
  </article>

</div>
{% endhighlight %}

I due file sono molto simili, eccetto una singola riga il loro contenuto è il
medesimo. Questi due file sono degli ottimi candidati per utilizzare un tag di
inclusione col vantaggio di avere una singola copia del codice ed evitare
ridondanze e al contempo rendendo la manutenzione del codice più semplice ed
uniforme a qualsiasi cambiamento del codice che potrebbe avvenire. Se si ha
una singola copia del codice, un singolo cambiamento o una correzione saranno
automaticamente applicate a tutte le pagine che usano lo stesso file incluso.

Per gestire la riga differente tra i due file è possibile utilizzare un semplice
controllo per escludere tale riga dalla pagina ottenuta, semplicemente passando
un argomento al file incluso, quindi creiamo un nuovo file chiamato
**_include/post_content.html**:
{% highlight html %}
<div class="post">

  <header class="post-header">
    <h1>{{ "{{" }} page.title }}</h1>
{{ "{%" }} if include.meta_paragraph %}
    <p class="meta">{{ "{{" }} page.date | date: "%b %-d, %Y" }}{{ "{%" }} if page.author %} • {{ "{{" }} page.author }}{{ "{%" }} endif %}{{ "{%" }} if page.meta %} • {{ "{{" }} page.meta }}{{ "{%" }} endif %}</p>
{{ "{%" }} endif %}
  </header>

  <article class="post-content">
  {{ "{{" }} content }}
  </article>

</div>
{% endhighlight %}

Il valore **include.meta_paragraph** sarà passato al file incluso e se tale
valore sarà vero (_true_) allora il paragrafo sarà aggiunto alla pagina,
altrimenti non sarà scritto affatto.

Quindi cambiamo il contenuto del file **_layouts/page.html** in:
{% highlight html %}
---
layout: default
---
{{ "{%" }} include post_content.html meta_paragraph=false %}
{% endhighlight %}

All'interno del file incluso **meta_paragraph** diverrà **include.meta_paragraph**
e sarà controllato per produrre od omettere il paragrafo non comune.

Il file **_layouts/post.html** conterrà invece:
{% highlight html %}
---
layout: default
---
{{ "{%" }} include post_content.html meta_paragraph=true %}
{% endhighlight %}

Et voilà, entrambi i file adesso sono similari e basta una singola copia del
codice per gestire entrambe le impaginazioni.