{% if page.category == 'italian' %}
  {% case include.type %}
    {% when 'new' %}
## Nuovo pacchetto nel repository di Arch Linux **[{{ include.pkgname }}](https://www.archlinux.org/packages/community/{{ include.arch }}/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
    {% when 'from_aur' %}
## Spostato da AUR al repository di Arch Linux il pacchetto **[{{ include.pkgname }}](https://www.archlinux.org/packages/community/{{ include.arch }}/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
Il pacchetto adesso si trova nei repository ufficiali di Arch Linux.
    {% when 'update' %}
## Aggiornato nel repository di Arch Linux il pacchetto **[{{ include.pkgname }}](https://www.archlinux.org/packages/community/{{ include.arch }}/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
      {% if include.pkgrel == 1 %}
Nuovo rilascio upstream {{ include.pkgver }}{{ include.comment }}.
      {% endif %}
  {% endcase %}
{% else %}
  {% case include.type %}
    {% when 'new' %}
## New package in the Arch Linux repository **[{{ include.pkgname }}](https://www.archlinux.org/packages/community/{{ include.arch }}/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
    {% when 'from_aur' %}
## Moved from AUR to the Arch Linux repository the package **[{{ include.pkgname }}](https://www.archlinux.org/packages/community/{{ include.arch }}/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
The package is now in the official Arch Linux repositories.
    {% when 'update' %}
## Updated in the official Arch Linux repository the package **[{{ include.pkgname }}](https://www.archlinux.org/packages/community/{{ include.arch }}/{{ include.pkgname }}/) {{ include.pkgver }}-{{ include.pkgrel }}**
      {% if include.pkgrel == 1 %}
New upstream release {{ include.pkgver }}{{ include.comment }}.
      {% endif %}
  {% endcase %}
{% endif %}
