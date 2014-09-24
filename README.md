trace
=====

Simple macro to trace information, currently for Qt language
but easily portable to C or C++


How to use
==========

TRACE(int lvl, QString className, QString message);

Add some macro everywhere in your project defining:

 - a lvl which currently is MAJOR, MEDIUM or MINOR.

 - the className which can be set manually or using 
   QObject::objectName() if the class you are writing
   in inherits QObject.

 - your custom message.


Results
=======

Each execution of you program generate one loging file
with some lines like this:

[...]
Sep 24 2014 at 12:15:18
in file:../trace/main.cpp at line:10
classA: Medium trace to log
[...]