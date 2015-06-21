{% include set-language.inc %}
{% if language == 'italian' %}
{%   assign iubenda_policy=site.iubenda_policy_it %}
{%  else %}
{%   assign iubenda_policy=site.iubenda_policy_en %}
{% endif %}
<a href="//www.iubenda.com/privacy-policy/{{ iubenda_policy }}" target="_blank" class="iubenda-white iubenda-embed" title="Privacy Policy">Privacy Policy</a>
{% if false %}
<script type="text/javascript">(function (w,d) {var loader = function () {var s = d.createElement("script"), tag = d.getElementsByTagName("script")[0]; s.src = "/resources/iubenda.js"; tag.parentNode.insertBefore(s,tag);}; if(w.addEventListener){w.addEventListener("load", loader, false);}else if(w.attachEvent){w.attachEvent("onload", loader);}else{w.onload = loader;}})(window, document);</script>
{% endif %}
