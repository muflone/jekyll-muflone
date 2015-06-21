{% include set-language.inc %}
{% if language == 'italian' %}
{%    assign iubenda_policy=site.iubenda_policy_it %}
{%    assign cookies_message="Questo sito web utilizza i cookie per semplificare e personalizzare l'esperienza di navigazione. I cookie memorizzano informazioni utili sul computer per aiutarci a migliorare l'efficienza e la rilevanza del nostro sito. In alcuni casi sono essenziali per il corretto funzionamento del sito. L'accesso a questo sito implica il consenso all'utilizzo dei cookie." %}
{%    assign cookies_dismiss="Nascondi" %}
{%    assign cookies_learnmore="Leggi l'informativa completa" %}
{%  else %}
{%    assign iubenda_policy=site.iubenda_policy_en %}
{%    assign cookies_message="This website uses cookies to make your browsing experience more convenient and personal. Cookies store useful information on your computer to help us improve the efficiency and relevance of our site for you. In some cases, they are essential to making the site work properly. By accessing this site, you consent to the use of cookies." %}
{%    assign cookies_dismiss="Hide" %}
{%    assign cookies_learnmore="More info" %}
{%  endif %}
<!-- Begin Cookie Consent plugin by Silktide - http://silktide.com/cookieconsent -->
<script type="text/javascript">
    window.cookieconsent_options = {"message":"{{ cookies_message }}","dismiss":"{{ cookies_dismiss }}","learnMore":"{{ cookies_learnmore }}","link":"https://www.iubenda.com/privacy-policy/{{ iubenda_policy }}","theme":"dark-top"};
</script>

<script type="text/javascript" src="/resources/cookieconsent2-1.0.4/cookieconsent.js"></script>
<!-- End Cookie Consent plugin -->
