<!DOCTYPE html>
<html>
  <head>
    <meta charset='utf-8'>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
{% if page.keywords %}
    <meta name="keywords" content="{{ page.keywords }}">
{% endif %}
{% if page.summary %}
    <meta name="description" content="{{ page.summary }}">
{% endif %}
    <meta name="author" content="Fabio Castelli">
    <link rel="shortcut icon" href="/resources/{{ include.section }}/favicon.ico" type="image/x-icon">
    <link rel="icon" href="/resources/{{ include.section }}/favicon.ico" type="image/x-icon">
    <link rel="author" href="https://plus.google.com/+FabioCastelli"/>
    <link rel="stylesheet" type="text/css" href="/theme/architects-fonts.css" >
    <link rel="stylesheet" type="text/css" href="/theme/stylesheet.css" media="screen" />
    <link rel="stylesheet" type="text/css" href="/theme/pygment_trac.css" media="screen" />
    <link rel="stylesheet" type="text/css" href="/theme/print.css" media="print" />
    <link rel="stylesheet" type="text/css" href="/theme/stylesheet2.css" media="screen" />

    <!--[if lt IE 9]>
    <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->
{% if page.require_jquery %}
  {% include jquery.inc %}
{% endif %}
{% if page.require_jquery_iontabs %}
  {% include jquery_iontabs.inc %}
{% endif %}
{% if page.require_jquery_collapse %}
  {% include jquery_collapse.inc %}
{% endif %}
{% include cookie-consent.inc %}
    <title>{% if include.title_prefix %}{{ include.title_prefix }} - {% endif %}{{ page.title }}</title>
