/* To set up dmalloc tool execute: */
/* 	dmalloc -l <logfile name> -i 100 high */

/* To execute check the file execute: */
/* 	gcc -D MALLOC <file name> -o <output file> -l dmalloc */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* `dmalloc` dependency */
#include <dmalloc.h>

void usage(char *msg) {
  fprintf(stderr, "%s", msg);
  free(msg);
}

int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 4) {
    // error message won't be longer than 80 characters
    char *errmsg = (char *)malloc(80 * sizeof(char));
    sprintf(errmsg,
            "Sorry %s\nUsage caesar secret_file keys_file [output_file]\n",
            getenv("USER"));
    usage(errmsg);
    // free already realesed memory
    free(errmsg);
    dmalloc_shutdown();
    exit(EXIT_FAILURE);
  }
  dmalloc_shutdown();
  exit(EXIT_SUCCESS);
}
