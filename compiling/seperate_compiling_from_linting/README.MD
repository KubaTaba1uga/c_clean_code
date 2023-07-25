If you’ve just made a change to one or two of your source code files, it’s
a waste to recompile every source file for your program.

If you tell the compiler to save the object code it generates into a file, it
shouldn’t need to recreate it unless the source code changes. If a file does
change, you can recreate the object code for that one file and then pass
the whole set of object files to the compiler so they can be linked.

Compile the source into object files
```
gcc -c *.c
```

Link them together
```
gcc *.o -o launch
```

OK, so now you have a compiled program, just like before.
But you also have a set of object files that are ready to be
linked together if you need them again. So if you change just
one of the files, you’ll only need to recompile that single file
and then relink the program:
```
gcc -c thruster.c
```
```
gcc *.o -o launch
```
