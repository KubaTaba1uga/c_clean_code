#include <stdio.h>

/* String literals are kept in read-only memory. */
/* To modify string literal one needs to copy it first. */
/* To avoid common string literal errors use them with */
/* `constant` key word.     */

int main() {

  /* BAD CODE! */
  char *bad_string_literal = "ABC";
  /* GOOD CODE! */
  const char *string_literal = "ABC";

  /* GOOD CODE! BUT TRICKY! */
  /* In fact below declaration, puts "ABC" in read-only */
  /* memory. Then copies it and assigns to array variable. */
  char string_literal_cp[] = "ABC";
  /* That's why it can be modified.' */
  string_literal_cp[1] = 'X';

  puts(bad_string_literal);
  puts(string_literal);
  puts(string_literal_cp);

  return 0;
}
