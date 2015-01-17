{% if page.category == 'italian' %}
  {% case include.weekday_number %}
    {% when 1 %}{% assign day_name = 'Lunedì' %}
    {% when 2 %}{% assign day_name = 'Martedì' %}
    {% when 3 %}{% assign day_name = 'Mercoledì' %}
    {% when 4 %}{% assign day_name = 'Giovedì' %}
    {% when 5 %}{% assign day_name = 'Venerdì' %}
    {% when 6 %}{% assign day_name = 'Sabato' %}
    {% when 7 %}{% assign day_name = 'Domenica' %}
  {% endcase %}
  {% case include.month_number %}
    {% when  1 %}{% assign month_name = 'Gennaio' %}
    {% when  2 %}{% assign month_name = 'Febbraio' %}
    {% when  3 %}{% assign month_name = 'Marzo' %}
    {% when  4 %}{% assign month_name = 'Aprile' %}
    {% when  5 %}{% assign month_name = 'Maggio' %}
    {% when  6 %}{% assign month_name = 'Giugno' %}
    {% when  7 %}{% assign month_name = 'Luglio' %}
    {% when  8 %}{% assign month_name = 'Agosto' %}
    {% when  9 %}{% assign month_name = 'Settembre' %}
    {% when 10 %}{% assign month_name = 'Ottobre' %}
    {% when 11 %}{% assign month_name = 'Novembre' %}
    {% when 12 %}{% assign month_name = 'Dicembre' %}
  {% endcase %}
# {{ day_name }} {{ include.day_number }} {{ month_name }} {{ include.year }}
{% else %}
  {% case include.weekday_number %}
    {% when 1 %}{% assign day_name = 'Monday' %}
    {% when 2 %}{% assign day_name = 'Tuesday' %}
    {% when 3 %}{% assign day_name = 'Wednesday' %}
    {% when 4 %}{% assign day_name = 'Thursday' %}
    {% when 5 %}{% assign day_name = 'Friday' %}
    {% when 6 %}{% assign day_name = 'Saturday' %}
    {% when 7 %}{% assign day_name = 'Sunday' %}
  {% endcase %}
  {% case include.month_number %}
    {% when  1 %}{% assign month_name = 'January' %}
    {% when  2 %}{% assign month_name = 'Febraury' %}
    {% when  3 %}{% assign month_name = 'March' %}
    {% when  4 %}{% assign month_name = 'April' %}
    {% when  5 %}{% assign month_name = 'May' %}
    {% when  6 %}{% assign month_name = 'June' %}
    {% when  7 %}{% assign month_name = 'July' %}
    {% when  8 %}{% assign month_name = 'August' %}
    {% when  9 %}{% assign month_name = 'September' %}
    {% when 10 %}{% assign month_name = 'October' %}
    {% when 11 %}{% assign month_name = 'November' %}
    {% when 12 %}{% assign month_name = 'December' %}
  {% endcase %}
# {{ day_name }} {{ include.year }}, {{ month_name }} {{ include.day_number }}
{% endif %}
