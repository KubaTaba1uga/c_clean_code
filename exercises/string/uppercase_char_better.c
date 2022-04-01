/* Exercise: */

/* accum("abcd") -> "A-Bb-Ccc-Dddd" */
/* accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy" */
/* accum("cwAt") -> "C-Ww-Aaa-Tttt" */
#include <stdio.h>
#include <stdlib.h>

int LOWER_MIN = 'a';
int LOWER_UPPER_DIFF = 'a' - 'A';

char *accum(char *string) {
  char tmp, *result;
  int i, j;

  result = (char *)malloc(1024 * sizeof(char));

  i = j = 0;

  while (string[i] != 0) {

    if (string[i] >= LOWER_MIN)
      result[j] = tmp = string[i] - LOWER_UPPER_DIFF;
    else
      result[j] = tmp = string[i];
    j++;

    for (int k = 0; k < i; k++, j++) {
      result[j] = tmp + LOWER_UPPER_DIFF;
    }
    i++;

    if (string[i] != 0)
      result[j] = '-';
    j++;
  }

  return result;
}

void show_result(char *result) { printf("%s\n", result); }

int main(void) {
  char *result = accum("abcd");
  show_result(result); // -> "A-Bb-Ccc-Dddd"

  result = accum("RqaEzty");
  show_result(result); // -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"

  result = accum("cwAt"); // -> "C-Ww-Aaa-Tttt"
  show_result(result);

  free(result);
  result = NULL;

  return 0;
}
