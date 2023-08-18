---
layout: documentation
order: 534
depth: 2
title: Filters
---
# Filters

It's possible to apply one or more filters to extract or transform the desired
results.

The allowed filters for the option `FILTERS` are the following:

| Nome          | Descrizione                                                                                           |
|:--------------|:------------------------------------------------------------------------------------------------------|
| STARTS        | The item must begin with the specified string                                                         |
| NOT STARTS    | The item must not begin with the specified string                                                     |
| ENDS          | The item must end with the specified string                                                           |
| NOT ENDS      | The item must not end with the specified string                                                       |
| CONTAINS      | The item must contain the specified string                                                            |
| NOT CONTAINS  | The item must not contain the specified string                                                        |
| REGEX         | The item must match the specified regular expression string                                           |
| NOT REGEX     | The item must not match the specified regular expression string                                       |
| TRIM          | Removes spaces or the specified characters from both left and right                                   |
| LTRIM         | Removes spaces or the specified characters from the left                                              |
| RTRIM         | Removes spaces or the specified characters from the right                                             |
| PREPEND       | Prepend (insert at the start) the specified text                                                      |
| APPEND        | Append (insert at the end) the specified text                                                         |
| REMOVE        | Remove from the item the specified text                                                               |
| REMOVE LEFT   | Remove from the item the matching string from the start                                               |
| REMOVE RIGHT  | Remove from the item the matching string from the end                                                 |
| REPLACE       | Replace from the item the specified text with a new pattern (specified using WITH:)                   |
| REVERSE       | Reverse the item text                                                                                 |
| UPPER         | Makes the item uppercase                                                                              |
| LOWER         | Makes the item lowercase                                                                              |
| LEFT          | Return the first leftmost characters                                                                  |
| RIGHT         | Return the first rightmost characters                                                                 |
| REGEX REPLACE | Replace from the item a pattern using a regular expression with a new pattern (specified using WITH:) |
| REGEX SEARCH  | Return the first regular expression match                                                             |
| JSON DICT     | Return the value from a JSON dict with the specified key                                              |
| JSON LIST     | Return the value from a JSON list with the specified index                                            |

>>>>>> See the [Filters page]({% link _watchpage/english/examples/filters.md %})
>>>>>> on the [Usage examples]({% link _watchpage/english/examples/index.md %}) section.
