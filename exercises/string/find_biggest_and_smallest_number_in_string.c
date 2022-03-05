/* Exercise: */
/*	high_and_low("1 2 3 4 5")  // return "5 1" */
/*	high_and_low("1 2 -3 4 5") // return "5 -3" */
/*	high_and_low("1 9 3 4 -5") // return "9 -5" */

#include <stdio.h>
/* `atoi` dependency */
#include <stdlib.h>

void increment_i(int *i) {
  int j = *i;
  *i = j + 1;
}

void fill_string(char *empty_string, int max, int min) {
  sprintf(empty_string, "%d %d", max, min);
}

int get_number(char *string, int *string_i) {
  char number[1000] = "";

  int number_i = 0;

  while (string[*string_i] != ' ' && string[*string_i] != 0) {
    number[number_i] = string[*string_i];
    number_i++;
    increment_i(string_i);
  }

  return atoi(number);
}

void high_and_low(char *string, char *result) {
  int i, high, low;

  i = 0;

  high = low = get_number(string, &i);

  while (string[i] != 0) {
    if (string[i] != ' ') {

      int number = get_number(string, &i);

      high = number > high ? number : high;

      low = number < low ? number : low;

    } else {
      /* Skip whitespace */
      increment_i(&i);
    }
  }

  fill_string(result, high, low);

  printf("%s\n", result);
}

int main(void) {
  char result[100];
  high_and_low("1 2 3 4 5", result);
  high_and_low("1 9 3 4 -5", result); // return "9 -5" */;
}
