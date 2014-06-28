{% if page.category %}
  {% assign language = page.category %}
{% else %}
  {% assign language = page.language %}
{% endif %}