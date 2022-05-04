#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

int main(void) {
  char file_name[] = "signals.txt";

  FILE *file_stream = fopen(file_name, "r");
  if (!file_stream) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }
  int i = 0;
  int r;
  int signal_no;
  char signal_short[5];
  char signal_desc[25];

  do {
    r = fscanf(file_stream, "%i %4s %24[^\n]\n", &signal_no, signal_short,
               signal_desc);

    if (r == 3)
      printf("Signal: %i\nName: %s\nDescription: %s\n\n", signal_no,
             signal_short, signal_desc);
    else if (r != EOF) {
      printf("File reading error in line: %i\n", i);
      break;
    } else
      break;

  } while (++i);

  if (fclose(file_stream) == EOF) {
    fputs("Failed to close file:", stderr);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
