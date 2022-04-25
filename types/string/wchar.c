/* This data type is used as the base type for wide character strings.  */
/* In other words, arrays of objects of this type are the equivalent of  */
/* char[] for multibyte character strings. The type is defined in wchar.h. */

/* The ISO C90 standard, where wchar_t was introduced, does not say */
/* anything specific about the representation. It only requires that this */
/* type is capable of storing all elements of the basic character set.  */
/* Therefore it would be legitimate to define wchar_t as char, */
/* which might make sense for embedded systems. */

/* In the GNU C Library wchar_t is always 32 bits wide and, therefore,  */
/* capable of representing all UTF-8, UTF-16, UTF-32 values.  */

#include <locale.h>
#include <wchar.h>

void show_wchar(wchar_t *a, char *repr) {
  wprintf(L"\n\nhexadecimal value of %s: ", repr);
  wchar_t *a_cp = a;
  while (*a_cp != 0) {
    wprintf(L"%x ", *a_cp++);
  }

  // `%ls` means this is wide string
  wprintf(L"\nrepresentation value of %s: %ls\n", repr, a);
}

int main(void) {
  // specify encoding related to used characters
  setlocale(LC_ALL, "pl_PL.UTF-8");

  // `L` before '' means this is wide character
  wchar_t word[] = {L'ź', L'd', L'ź', L'b', L'ł', L'o', L'\0'};
  show_wchar(word, "word");

  // `L` before "" means this is wide string
  wchar_t *a = L"ź";
  show_wchar(a, "a");

  wchar_t *b = L"d";
  show_wchar(b, "b");

  wchar_t *c = L"ź";
  show_wchar(c, "c");

  wchar_t *d = L"b";
  show_wchar(d, "d");

  wchar_t *e = L"ł";
  show_wchar(e, "e");

  wchar_t *f = L"o";
  show_wchar(f, "f");

  return 0;
}
