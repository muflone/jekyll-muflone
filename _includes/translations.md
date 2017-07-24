{% case include.type %}
  {% when 'index' or 'languages' %}
<!-- Translations for the index and languages pages -->
# {{ site.data.translations[page.language].translations.title }}
{{ site.data.translations[page.language].translations.text1 | replace: '$(NAME)', site.data[page.product].name }}
{% if site.data[page.product].translations %}
  <ul>
{% for translation in site.data[page.product].translations %}
    <li>{{ site.data.translations[page.language].languages[translation] }}</li>
{% endfor %}
  </ul>
{% endif %}
{{ site.data.translations[page.language].translations.text2 | replace: '$(NAME)', site.data[page.product].name }}

{{ site.data.translations[page.language].translations.text3 | replace: '$(NAME)', site.data[page.product].name | replace: '$(TRANSIFEX)', site.data[page.product].translations_repo | replace: '$(GITHUB)', site.data[page.product].gitrepo }}

  {% else %}
<!-- Unexpected translations type -->
# Unexpected type {{ type }}
{% endcase %}