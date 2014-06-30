    <ul>
{% for post in site.posts offset: 0 limit: 100 %}
  {% if include.filter == nil or post.category contains include.filter %}
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
{% endfor %}
    </ul>