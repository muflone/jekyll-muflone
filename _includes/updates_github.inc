{% if page.category == 'italian' %}
  {% case include.type %}
    {% when 'pull' %}
## Nuova [pull request](https://github.com/{{ include.project }}/pull/{{ include.pull }}) su GitHub nel progetto **[{{ include.project }}](https://github.com/{{ include.project }}/)**
    {% when 'fixissue' %}
Sistemata la [segnalazione {{ include.issue }}](https://github.com/{{ include.project }}/issues/{{ include.issue }}) su GitHub nel progetto **[{{ include.project }}](https://github.com/{{ include.project }}/)**
  {% endcase %}
{% else %}
  {% case include.type %}
    {% when 'pull' %}
## New [pull request](https://github.com/{{ include.project }}/pull/{{ include.pull }}) on GitHub project **[{{ include.project }}](https://github.com/{{ include.project }}/)**
    {% when 'fixissue' %}
Fixed the [issue {{ include.issue }}](https://github.com/{{ include.project }}/issues/{{ include.issue }}) on GitHub project **[{{ include.project }}](https://github.com/{{ include.project }}/)**
  {% endcase %}
{% endif %}
