/* The full list of file creation flags and file status */
/*	can be found by command:	  `man open` */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

  // read and write permissions for owner, groups and all others users
  int fd = creat(path, 0666);
  if (fd == -1)
    printf("File creation failed: %s\n", strerror(errno));
  else
    printf("Created file: %s\n", path);

  close(fd);
}
