#include <locale.h>
#include <stdio.h>
#include <uchar.h>

void show_char32(char32_t *a, char *repr) {
  char32_t *a_cp = a;

  printf("hexadecimal values of %s: ", repr);
  while (*a_cp != 0)
    printf("%x ", *a_cp++);

  printf("\nrepresentation value of %s: ", repr);
  while (*a != 0)
    // %C means print multibyte char
    printf("%C", *a++);

  puts("\n");
}

int main(void) {
  setlocale(LC_ALL, "");

  // `U` before '' means this is four bytes character
  char32_t word[] = {U'ź', U'd', U'ź', U'b', U'ł', U'o', U'\0'};
  show_char32(word, "word");

  // `U` before "" means this is string of four bytes characters
  char32_t *a = U"ź";
  show_char32(a, "a");

  char32_t *b = U"d";
  show_char32(b, "d");

  char32_t *c = U"ź";
  show_char32(c, "c");

  char32_t *d = U"b";
  show_char32(d, "d");

  char32_t *e = U"ł";
  show_char32(e, "e");

  char32_t *f = U"o";
  show_char32(f, "f");
}
