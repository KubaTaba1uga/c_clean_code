#include <locale.h>
#include <stdio.h>
#include <uchar.h>

void show_char16(char16_t *a, char *repr) {
  char16_t *a_cp = a;

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

  // `u` before '' means this is two bytes character
  char16_t word[] = {u'ź', u'd', u'ź', u'b', u'ł', u'o', u'\0'};
  show_char16(word, "word");

  // `u` before "" means this is string of two bytes characters
  char16_t *a = u"ź";
  show_char16(a, "a");

  char16_t *b = u"d";
  show_char16(b, "d");

  char16_t *c = u"ź";
  show_char16(c, "c");

  char16_t *d = u"b";
  show_char16(d, "d");

  char16_t *e = u"ł";
  show_char16(e, "e");

  char16_t *f = u"o";
  show_char16(f, "f");
}
