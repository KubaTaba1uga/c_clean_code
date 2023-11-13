`-save-temps`

The advantage of this option over -E is that it is easy to add it to any build script, without interfering much in the build itself:

`gcc -save-temps -c -o main.o main.c`
