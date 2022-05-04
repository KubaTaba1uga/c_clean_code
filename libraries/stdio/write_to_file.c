/* The full list of file creation flags and file status */
/*	can be found by command:	  `man open` */
#include <stdio.h>
#include <string.h>

#include "utils.h"

#define WORD_SIZE 24

int main(void) {
  char path_prefix[] = "/tmp/";
  size_t path_size = (size_t)WORD_SIZE + sizeof(path_prefix);
  char path[path_size];
  size_t word_size = (size_t)WORD_SIZE;

  char word[word_size];

  create_random_word(word, word_size);

  sprintf(path, "%s%s", path_prefix, word);

  FILE *my_file = fopen(path, "w+b");
  if (!my_file) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  create_random_word(word, word_size);
  word[word_size - 2] = '\n';
  word[word_size - 1] = '\0';

  unsigned int count = fwrite(word, sizeof(char), word_size, my_file);
  if (count != word_size)
    perror("File writing failed");
  else
    printf("File path: %s\n", path);

  if (fclose(my_file) == EOF) {
    fputs("Failed to close file\n", stderr);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
