---
title: Benvenuto Jekyll
category: italian
tags:
  - jekyll
  - documentation
  - archlinux
---

Sin dalla sua creazione questo sito web &egrave; stato prodotto utilizzando
[**Jekyll**](http://jekyllrb.com), un generatore di siti web statici con
funzionalit&agrave; di blog.

Non spiegher&ograve; dettagliatamente come utilizzare Jekyll, &egrave; pieno di
siti web e documentatzione sul web.

Fondamentalmente il necessario &egrave; installare prima **Ruby**, quindi
installare un paio di *gemme* necessarie per eseguire Jekyll.

{% highlight bash %}
gem update
# Updating installed gems
gem install jekyll therubyracer
# Fetching: liquid-2.6.1.gem (100%)
# Successfully installed liquid-2.6.1
# Fetching: fast-stemmer-1.0.2.gem (100%)
# Building native extensions.  This could take a while...
# Successfully installed fast-stemmer-1.0.2
# Fetching: kramdown-1.4.0.gem (100%)
# Successfully installed kramdown-1.4.0
# ...
# 34 gems installed
{% endhighlight %}

Il primo comando aggiorner&agrave; qualunque gemma Ruby esistente, il secondo
installer&agrave; jekyll, assieme a tutte le sue dipendenze.

Un sito web rapido pu&ograve; essere creato semplicemente eseguendo:
{% highlight bash %}
jekyll new mywebsite
# New jekyll site installed in /home/muflone/mywebsite.
cd mywebsite
jekyll serve
# Configuration file: /home/muflone/mywebsite/_config.yml
#             Source: /home/muflone/mywebsite
#        Destination: /home/muflone/mywebsite/_site
#       Generating... 
#                     done.
# Configuration file: /home/muflone/mywebsite/_config.yml
#     Server address: http://0.0.0.0:4001/
#   Server running... press ctrl-c to stop.
{% endhighlight %}

Quindi navigando all'URL [http://localhost:4000/](http://localhost:4000/) 
sar&agrave; mostrando il nuovo sito web creato da Jekyll.

<div class="warning-it">Se il comando <strong>jekyll</strong> non pu&ograve; essere
trovato potrebbe essere necessario aggiungere la cartella gems
(<strong>~/.gems/ruby/VERSION/bin</strong>) al percorso.</div>

<div>&nbsp;</div>

<div class="tip-it">Un metodo alternativo (che preferisco) &egrave; quello di
creare un alias bash:
{% highlight bash %}
alias jekyll ~/.gems/ruby/VERSION/bin/jekyll
{% endhighlight %}
</div>

La struttura delle cartella automaticamente create sar&agrave; la seguente:
{% highlight bash %}
mywebsite
├── about.md
├── _config.yml
├── css
│   └── main.css
├── feed.xml
├── .gitignore
├── _includes
│   ├── footer.html
│   ├── header.html
│   └── head.html
├── index.html
├── _layouts
│   ├── default.html
│   ├── page.html
│   └── post.html
├── _posts
│   └── 2014-06-29-welcome-to-jekyll.markdown
└── _site
{% endhighlight %}

Il file **_config.yml** &egrave; il file di configurazione principale del
sito e conterr&agrave; sia le variabili di sistema che quelle definite
dall'utente per utilizzare all'interno di qualsiasi altra pagina web.

La cartella **_includes** conterr&agrave; il codice che si desidera includere
all'interno di un altro utilizzando il tag include. Questo &egrave; utile per
evitare di riscrivere lo stesso codice pi&ugrave; volte per pagine o sezioni.
Nel sito predefinito saranno forniti tre pezzetti di pagina chiamati footer,
header ed head.

La cartella **_layouts** conterr&agrave; le impaginazioni per le pagine, una
sorta di schema vuoto per altre pagine. E' possibile avere un'impaginazione per
la pagina iniziale e una differente per le altre pagine o un'impaginazione
differente per gli articoli del blog e cos&igrave; via.
Le impaginazioni sono la chiave per disegnare il sito web ed ospiteranno alcuni
tag segnaposto che saranno sostituiti dal contenuto principale per ottenere
una pagina web.

La cartella **_posts** conterr&agrave; tutti gli articoli che successivamente
produrranno le pagine web statiche.

La cartella **_site** conterr&agrave; il sito web prodotto dall'unione di tutte
le parti ed &egrave; questo il contenuto da caricare sul server.
Quando si navigher&agrave; il sito web locale all'indirizzo http://localhost:4000/
sar&agrave; mostrato il contenuto della cartella **_site**, non sar&agrave;
mostrato nessun file di jekyll, n&egrave; alcun file delle cartelle _layouts,
_include o _posts ma il sito risultante dalla combinazione di questi contenuti.