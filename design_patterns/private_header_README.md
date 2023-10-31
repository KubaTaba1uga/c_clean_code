Create a public include(s) that has some public "myheader.h", which has whatever is needed by 3rd party users to know/see/include to use the library. Then somewhere in source dir I would have so called private header which is called something like "xmyinclude.h" which includes corresponding public header and declares whatever private stuff is needed and that should not clutter public space. Then my corresponding source file includes my private header. I also tend to structure my source files (.c) one source file per public function instead of lumping stuff in o e .c file "per header".

Static vs Inline?
Static may be use to narrow namespaces to translation unit.
