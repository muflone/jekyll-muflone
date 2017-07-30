{% case include.type %}
  {% when 'index' %}
<!-- License for the index page -->
# {{ site.data.translations[page.language].license.title }}
{{ site.data.translations[page.language].license.text1 | replace: '$(NAME)', site.data[page.product].name | replace: '$(GITHUB)', site.data[page.product].gitrepo }}
{{ site.data.translations[page.language].license.text2 }}
  {% when 'download' %}
<!-- License for the download page -->
# {{ site.data.translations[page.language].downloads.title }}
{{ site.data.translations[page.language].license.text1 | replace: '$(NAME)', site.data[page.product].name | replace: '$(GITHUB)', site.data[page.product].gitrepo }}
  {% else %}
<!-- Unexpected license type -->
# Unexpected type {{ type }}
{% endcase %}