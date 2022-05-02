CC      = gcc
CFLAGS  = -g -std=c17 -Wall -l safec
RM      = rm -f


default: all

all: Create_file Write_to_file Read_file_char_by_char

Create_file:  create_file.c utils.c
	$(CC) $(CFLAGS) -o create_file.out create_file.c utils.c

Write_to_file:  write_to_file.c utils.c
	$(CC) $(CFLAGS) -o write_to_file.out write_to_file.c utils.c

Read_file_char_by_char: read_file_char_by_char.c
	$(CC) $(CFLAGS) -o read_file_char_by_char.out read_file_char_by_char.c

Read_file_line_by_line: read_file_line_by_line.c
	$(CC) $(CFLAGS) -o read_file_line_by_line.out read_file_line_by_line.c


clean veryclean:
	$(RM) *.out
