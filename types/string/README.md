GCC has several flags that allow You to configure character sets.

`-fexec-characterset=<characterset>`
Sets the execution characterset that's used to interpret string and
character constants. The default is 'UTF-8'.

`-fwide-exec-charset=<characterset>`
Sets the execution characterset that's used to interpret wide string
and wide character constants. The default is 'UTF-32' or 'UTF-16'.

`-finput-characterset=<characterset>`
Sets the input characterset, used for translation from the character 
set of the input file to the source character set used by GCC.	     