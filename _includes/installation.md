{% case include.type %}

  {% when 'debian' %}
  <!-- Installation type for Debian and Ubuntu -->
# {{ site.data.translations[page.language].installation.debian.title }}
{{ site.data.translations[page.language].installation.debian.text1 }}
```
{{ site.data.translations[page.language].installation.debian.commands1 | replace: '$(PACKAGE)', site.data[page.product].lowername }}```

  {% when 'archlinux' %}
  <!-- Installation type for Arch Linux -->
# {{ site.data.translations[page.language].installation.archlinux.title }}
    {% if include.package %}
  <!-- Installation type for repository package -->
  {{ site.data.translations[page.language].installation.archlinux.package | replace: '$(PACKAGE)', include.package }}
    {% endif %}

    {% if include.aur %}
  <!-- Installation type for AUR package -->
  {{ site.data.translations[page.language].installation.archlinux.aur | replace: '$(PACKAGE)', include.aur }}
    {% endif %}

    {% if include.development %}
  <!-- Installation type for development AUR package -->
  {{ site.data.translations[page.language].installation.archlinux.development | replace: '$(PACKAGE)', include.development }}
    {% endif %}

    {% if include.download %}
  <!-- Installation type for downloadable .tar.xz -->
  {{ site.data.translations[page.language].installation.archlinux.text1 }}
```
{{ site.data.translations[page.language].installation.archlinux.commands1 | replace: '$(PACKAGE)', include.download }}```
    {% endif %}

  {% when 'source' %}
  <!-- Installation type for source code -->
# {{ site.data.translations[page.language].installation.source.title }}
{{ site.data.translations[page.language].installation.source.text1 | replace: '$(NAME)', site.data[page.product].name }}
```
{{ site.data.translations[page.language].installation.source.commands1 | replace: '$(PACKAGE)', site.data[page.product].lowername }}```
{{ site.data.translations[page.language].installation.source.text2 }}
>>> {{ site.data.translations[page.language].installation.source.text3 }}

  {% when 'remmina-plugin-builder' %}
  <!-- Installation type for source code using Remmina Plugin Builder -->
# {{ site.data.translations[page.language].installation.remmina_plugin_builder.title }}
{{ site.data.translations[page.language].installation.remmina_plugin_builder.text1 | replace: '$(NAME)', site.data[page.product].name }}
{{ site.data.translations[page.language].installation.remmina_plugin_builder.text2 | replace: '$(NAME)', site.data[page.product].name | replace: '$(LANGUAGE)', page.language }}
{{ site.data.translations[page.language].installation.remmina_plugin_builder.text3 | replace: '$(NAME)', site.data[page.product].name }}
```
{{ site.data.translations[page.language].installation.remmina_plugin_builder.commands3 | replace: '$(PACKAGE)', site.data[page.product].lowername }}```
{{ site.data.translations[page.language].installation.remmina_plugin_builder.text4 | replace: '$(NAME)', site.data[page.product].name }}
```
{{ site.data.translations[page.language].installation.remmina_plugin_builder.commands4 | replace: '$(PACKAGE)', site.data[page.product].lowername }}```
{{ site.data.translations[page.language].installation.source.text2 }}
>>> {{ site.data.translations[page.language].installation.source.text3 }}

  {% when 'index' %}
  <!-- Installation for index page -->
# {{ site.data.translations[page.language].installation.index.title }}
{{ site.data.translations[page.language].installation.index.text1 }}

{{ site.data.translations[page.language].installation.index.text2 | replace: '$(NAME)', site.data[page.product].name | replace: '$(GITHUB)', site.data[page.product].gitrepo }}
  {% else %}
  <!-- Unexpected installation type -->
# Unexpected type {{ type }}
{% endcase %}
