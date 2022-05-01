CC      = gcc
CFLAGS  = -g -std=c17 -Wall -l safec
RM      = rm -f


default: all

all: Create_file Write_to_file

Create_file:  create_file.c utils.c
	$(CC) $(CFLAGS) -o create_file.out create_file.c utils.c

Write_to_file:  write_to_file.c utils.c
	$(CC) $(CFLAGS) -o write_to_file.out write_to_file.c utils.c


clean veryclean:
	$(RM) *.out
