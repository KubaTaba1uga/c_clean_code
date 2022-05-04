/* fopen_s implementation used in this example is from: */
/* 	https://github.com/rurban/safeclib */
/* to compile using gcc add: `-l safec` */
#include <safeclib/safe_lib.h>
#include <safeclib/safe_str_lib.h>

void print_error(errno_t error, char *notif) {
  size_t errmsglen = strerrorlen_s(error) + 1;
  char errmsg[errmsglen];
  strerror_s(errmsg, errmsglen, error);
  printf("%s: %s", notif, errmsg);
}

int main(void) {
  FILE *readme = NULL;
  errno_t result;

  result = fopen_s(&readme, "README.md", "r");
  if (result != 0) {
    print_error(result, "`fopen` failed");
    return 123;
  }

  char buffer[128];
  while (fgets(buffer, sizeof(buffer), readme) != NULL)
    fputs(buffer, stdout);

  if (ferror(readme)) {
    fputs("Reading failed: ", stderr);
    return 125;
  } else if (feof(readme))
    puts("\n\nEnd of file reached successfully");

  if (fclose(readme) == EOF) {
    fputs("Failed to close file:", stderr);
    return 126;
  }

  return 0;
}
