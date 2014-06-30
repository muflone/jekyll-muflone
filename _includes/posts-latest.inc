    <ul>
{% assign count = 0 %}
{% for post in site.posts %}
  {% if include.filter == nil or post.category contains include.filter %}
    {% assign count = count | plus: 1 %}
    {% if count <= include.count %}
      <li>
      {% if post.category contains 'italian' %}
        <img src="/resources/index/16-italian.png">
      {% else %}
        <img src="/resources/index/16-english.png">
      {% endif %}
        <a href="{{ site.prefix }}{{ post.url }}">{{ post.title }}</a>
        ({{ post.date | date_to_string }})
        <div class="entry">{{ post.summary }}</div>
      </li>
    {% endif %}
  {% endif %}
{% endfor %}
    </ul>