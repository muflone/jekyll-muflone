---
title: Welcome Jekyll
category: english
tags:
  - jekyll
  - documentation
  - archlinux
---

Since its creation this website was built using [**Jekyll**](http://jekyllrb.com),
a blog aware static website creator.

I won't deeply explain how to use Jekyll, it's plenty of websites and
documentation on the web.

Basically what you need is to install first **Ruby** then install a couple of
gems needed to run Jekyll.

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

The first command will update any existing Ruby gems, the second one will
install jekyll, along as with all its dependencies.

A quick start website can be created simply executing:
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

Then browsing the URL [http://localhost:4000/](http://localhost:4000/) will show
your brand new website created by Jekyll.

<div class="warning">If the <strong>jekyll</strong> command cannot be found you
may need to add the gems directory (<strong>~/.gems/ruby/VERSION/bin</strong>)
to your path.</div>

<div>&nbsp;</div>

<div class="tip">An alternative method (which I prefer) is to create a bash alias:
{% highlight bash %}
alias jekyll ~/.gems/ruby/VERSION/bin/jekyll
{% endhighlight %}
</div>

The directories structure automatically created for you will be the following:
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

The file **_config.yml** is the main website configuration file and it will
contain both system and user defined variables to be used in any other webpage.

The **_includes** folder will contain code that you wish to include inside
another by using the include tag. This is useful to avoid rewrite the same code
for multiple pages or sections.
In the default website will be provided three snippets of page called footer,
header and head.

The **_layouts** folder will contain the layouts for the pages, like an empty
schema for the others page. You can have a layout for home page, a different
layout for the other pages, a different layout for blog posts and so on.
The layouts are the keys to design your website and they will host some
placeholder tags that will be replaced by the main content to render a webpage.

The **_posts** folder will contain all your articles that will later produce
the static webpages.

The **_site** folder will contain the website produced by joining all the parts
and this is the contents you will need to upload to your server.
When you'll browse your local website by surfing the http://localhost:4000/ URL
you will see what's inside the **_site** folder, you will not see any jekyll
file, neither any file inside _layouts, _include or _posts folders but the
resulted website by combining these contents.