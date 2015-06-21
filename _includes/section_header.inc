{% include header.inc section=page.layout title_prefix=include.module.name %}
  </head>
  <body>
    <header>
      <div class="inner">
        <a href="index.html"><img src="/resources/{{ page.layout }}/archive/latest/icon128.png" style="width: 128px; height: 128px; padding-right: 20px;" align="left"></a>
        <h1>{{ include.module.name }}</h1>
        <h2>{{ page.title }}</h2>
        <a href="{{ include.module.gitrepo }}" class="button"><small>{% if page.language == 'italian' %}Guarda il progetto su{% else %}View project on{% endif %}</small>GitHub</a>
      </div>
    </header>

    <div id="content-wrapper">
      <div class="inner clearfix">
        <section id="main-content">
