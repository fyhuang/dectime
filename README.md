dectime
=======

Tiny decimal time printer and converter. The [decimal time measurement](http://en.wikipedia.org/wiki/Decimal_time) used is 1000ths of a day (000-999). 000 = midnight, 500 = noon. Compile with:

~~~
g++ -o dectime dectime.cpp
~~~

`dectime` can print out the current time as a decimal timestamp, or it can convert a decimal timestamp to HH:MM:SS format:

~~~
dectime
# 500

dectime 500
# 12:00:00

dectime 850
# 20:24:00 (i.e. 8:24 PM)
~~~

To include `dectime` output in your bash prompt, use `\$(dectime)`, e.g.:

~~~
export PS1="\u@\h \$(dectime) \W\$ "
~~~
