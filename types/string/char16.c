#include <uchar.h>

 
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
  setlocale(LC_ALL, "");

  // `L` before '' means this is wide character
  wchar_t word[] = {L'ź', L'd', L'ź', L'b', L'ł', L'o'};
  show_wchar(word, "word");

  // `L` before "" means this is wide string
  wchar_t *a = L"ź";
  show_wchar(a, "a");

  wchar_t *b = L"d";
  show_wchar(b, "bł");

  wchar_t *c = L"ź";
  show_wchar(c, "c");

  wchar_t *d = L"b";
  show_wchar(d, "d");

  wchar_t *e = L"ł";
  show_wchar(e, "e");

  wchar_t *f = L"o";
  show_wchar(f, "f");
}

