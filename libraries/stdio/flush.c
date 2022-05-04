/* `fflush` function delivers any unwritten data for  */
/* 	a specified stream to the host environment. */
#include <stdio.h>
#include <unistd.h>

void print_char_by_char(char *p) {
  while (*p != 0) {
    fputc(*p++, stdout);
    fflush(stdout);
    usleep(100000);
  }
}

void print_line(char *p) {
  while (*p != 0) {
    fputc(*p++, stdout);
    usleep(200000);
  }
}

int main(void) {
  char mike_0[] = "Who are U?\n";
  char noe_0[] = "I'm the chosen one.\n";
  char mike_1[] = "Are U the one that i dreamed about?\n";
  char noe_1[] = "That wasn't a dream. This is.\n";

  print_char_by_char(mike_0);

  print_line(noe_0);

  print_char_by_char(mike_1);

  print_line(noe_1);

  return 0;
}
