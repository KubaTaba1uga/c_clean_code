#include <stdio.h>

int main(
    // number of arguments
    int argc,
    // arguments as array of strings
    char *argv[]) {

  /* first argv element is always the file name. */
  for (int i = 0; i < argc; i++)
    printf("%s \n", argv[i]);

  return 0;
}
