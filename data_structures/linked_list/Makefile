CC      = gcc
CFLAGS  = -g -std=c17 -Wall
RM      = rm -f


default: all

all: LinkedList

LinkedList: linked_list_example.c linked_list.c
	$(CC) $(CFLAGS) -o linked_list_example.out linked_list_example.c linked_list.c

clean veryclean:
	$(RM) *.out
