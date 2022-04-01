#include <stdio.h>
#include <stdlib.h>
void show_file_fail(char *file_name) {
  printf("file %s could not be opened\n", file_name);
}

void show_file_success(char *operation, char *file_name) {
  printf("%s on %s performed successfully\n", operation, file_name);
}

int main(void) {
  int exit_code = 0; // Initially assume a succesfull exit code

  char *file1_name = "file1";
  FILE *file1 = fopen(file1_name, "w");
  if (file1 == NULL) {
    exit_code = -1;
    show_file_fail(file1_name);
    goto RETURN_EXIT_CODE;
  } else
    show_file_success("read", file1_name);

  char *file2_name = "file2";
  FILE *file2 = fopen(file2_name, "w");
  if (file2 == NULL) {
    exit_code = -1;
    show_file_fail(file2_name);
    goto CLOSE_FILE1;
  } else
    show_file_success("write", file2_name);

// Close all file descriptors
CLOSE_FILE2:
  puts("file2 closed");
  fclose(file2);
CLOSE_FILE1:
  puts("file1 closed");
  fclose(file1);

RETURN_EXIT_CODE:
  return exit_code;
}
