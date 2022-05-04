#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char name[] = "test.txt";
  char name_2[] = "super_test.txt";

  FILE *my_file = fopen(name, "w");
  if (!my_file) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  // ​0​ upon success or non-zero value on error
  if (rename(name, name_2)) {
    perror("File renaming failed");
    return EXIT_FAILURE;
  }

  // ​0​ upon success or non-zero value on error
  if (remove(name_2)) {
    perror("File deleting failed");
    return EXIT_FAILURE;
  }

  if (fclose(my_file) == EOF) {
    fputs("Failed to close file:", stderr);
    return EXIT_FAILURE;

    return EXIT_SUCCESS;
  }
}
