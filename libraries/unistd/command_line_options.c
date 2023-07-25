/* Program for rocket launching. */

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char ch;
  char *engine_count;
  bool awesomness;
  int i;

  while ((ch = getopt(argc, argv,
                      /* Options `a` and `e` are valid. */
                      /* Option `e` needs an argument. */
                      "ae:")) != EOF) {
    switch (ch) {
    case 'e':
      // `optarg` stands for -e argument
      engine_count = optarg;
      break;
    case 'a':
      awesomness = true;
      break;
    }
  }

  /* Make sure already read options are excluded. */
  argc -= optind;
  argv += optind;

  if (engine_count)
    printf("Starting %s engines\n", engine_count);

  if (awesomness)
    puts("Awesomness mode activated");

  fputs("Launching rockets to", stdout);
  for (i = 0; i < argc; i++)
    fprintf(stdout, " %s", argv[i]);
  fputs("\n", stdout);

  return 0;
}
