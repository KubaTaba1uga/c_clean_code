/* `realloc` increases or decreases the size of  */
/* 	previously allocated storage. If there is*/
/*	not enough memory, null pointer is  */
/*	returned. */
/* If null pointer is returned orginal pointer */
/*	has to be freed. Otherwise orginal */
/*	pointer is freed after reallocation auto- */
/*	matically and new storage is created. */

#include <stdio.h>
/* `realloc` dependency */
#include <stdlib.h>
#include <string.h>

char *str_append(char *dest, char *value) {
  size_t dest_len = strlen(dest);
  size_t value_len = strlen(value);

  // Add one place for string termination
  char *new_str = realloc(dest, (dest_len + value_len + 1) * sizeof(char));
  if (new_str == NULL) {
    free(dest);
    return NULL;
  }

  char *new_str_cp = new_str;

  new_str_cp += dest_len;
  strcpy(new_str_cp, value);
  new_str_cp += value_len;
  *new_str_cp++ = '\0';

  return new_str;
}

int main(void) {
  char *name = "Jakub";

  char *name_cp = (char *)calloc(strlen(name), sizeof(char));
  if (!name_cp)
    return EXIT_FAILURE;

  strcpy(name_cp, name);

  printf("%s\n", name_cp);

  name_cp = str_append(name_cp, " Buczynski");
  if (!name_cp)
    return EXIT_FAILURE;

  printf("%s\n", name_cp);

  free(name_cp);

  return EXIT_SUCCESS;
}
