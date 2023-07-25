# make knows which files changed and which require recompilation.

source.o: source.c shared.c shared.h
	gcc -c source.c

shared.o: shared.c shared.h
	gcc -c shared.c

start: source.o shared.o
	gcc source.o shared.o -o start
