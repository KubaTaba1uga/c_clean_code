/* Take input like `1 2` and  */
/* 	recognize `1` and `2`. */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
char *find_number(char *line, int *results) {

  *results = atoi(line);
  while (*line != ' ') {
    line++;
    if (*line == '\0')
      break;
  }

  return line;
}

void check_are_numbers(int a[2]) {
  const char *error_msg = "Wrong format";
  if (!a[0] || !a[1])
    puts(error_msg);
}

int main(void) {
  int line_len = 4, results[2] = {0, 0};
  char line[line_len];
  line[line_len - 1] = '\0';

  while (!results[0] || !results[1]) {
    scanf("%[^\n]%*c", line);
    char *line_cp = line;
    for (int i = 0; i < 2; ++i) {
      line_cp = find_number(line_cp, &results[i]);
    }
    check_is_numbers(results);
  }
}
