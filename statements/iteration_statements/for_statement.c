#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Replace `n` first chars in string using `replacement` char.
char *replace_str(char *str, int n, char replacement) {
  char *str_p = str;

  for (
      // Initialize loop counter.
      int i = 0;
      // Specify controlling condition.
      i < n;
      // Increment the counter after the loop execution .
      i++)
    *str_p++ = replacement;

  return str;
}

int main(void) {
  char *name = "Raymond";

  // Dynamic allocation is required, because
  //	string literals during compilation are
  //	placed in read-only memory.
  char *name_cp = (char *)malloc(sizeof(char) * (strlen(name) + 1));
  // Add one place to string for the null terminator `\0`,
  //	as strlen don't count it.

  strcpy(name_cp, name);

  printf("Before: %s\n", name_cp);

  name_cp = replace_str(name_cp, 2, 'Y');

  printf("  After: %s\n", name_cp);

  free(name_cp);

  return 0;
}
