CC      = gcc
CFLAGS  = -g -std=c17 -Wall
RM      = rm -f


default: all

all: Exercise

Exercise: solution.c dependency.c task.c utils.c
	$(CC) $(CFLAGS) -o solution.out solution.c dependency.c task.c utils.c

clean veryclean:
	$(RM) *.out
