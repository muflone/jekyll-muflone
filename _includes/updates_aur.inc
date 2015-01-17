{% if page.category == 'italian' %}
  {% case include.type %}
    {% when 'new' %}
## Nuovo pacchetto in AUR **[{{ include.pkgname }}](https://aur.archlinux.org/packages/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
    {% when 'update' %}
## Aggiornato il pacchetto in AUR **[{{ include.pkgname }}](https://aur.archlinux.org/packages/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
      {% if include.pkgrel == 1 %}
Nuovo rilascio upstream {{ include.pkgver }}{{ include.comment }}.
      {% endif %}
    {% when 'adopt' %}
## Adottato il pacchetto in AUR **[{{ include.pkgname }}](https://aur.archlinux.org/packages/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
    {% when 'remove' %}
## Rimosso il pacchetto in AUR **{{ include.pkgname }}**
  {% endcase %}
{% else %}
  {% case include.type %}
    {% when 'new' %}
## New AUR package **[{{ include.pkgname }}](https://aur.archlinux.org/packages/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
    {% when 'update' %}
## Updated AUR package **[{{ include.pkgname }}](https://aur.archlinux.org/packages/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
      {% if include.pkgrel == 1 %}
New upstream release {{ include.pkgver }}{{ include.comment }}.
      {% endif %}
    {% when 'adopt' %}
## Adopted AUR package **[{{ include.pkgname }}](https://aur.archlinux.org/packages/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
    {% when 'remove' %}
## Removed AUR package **{{ include.pkgname }}**
  {% endcase %}
{% endif %}
