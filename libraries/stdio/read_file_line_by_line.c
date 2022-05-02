/* fopen_s implementation used in this example is from: */
/* 	https://github.com/rurban/safeclib */
/* to compile using gcc add: `-l safec` */
#include <safeclib/safe_lib.h>
#include <safeclib/safe_str_lib.h>

int main(void) {
  FILE *readme = NULL;
  errno_t result;

  result = fopen_s(&readme, "README.md", "r");
  if (result != 0) {
    size_t errmsglen = strerrorlen_s(result) + 1;
    char errmsg[errmsglen];
    strerror_s(errmsg, errmsglen, result);
    printf("`fopen` failed: %s", errmsg);
    return 123;
  }

  char buffer[128];
  while (fgets(buffer, sizeof(buffer), readme) != NULL)
    fputs(buffer, stdout);

  if (ferror(readme)) {
    size_t errmsglen = strerrorlen_s(result) + 1;
    char errmsg[errmsglen];
    strerror_s(errmsg, errmsglen, result);
    printf("`fgetc` failed: %s", errmsg);
    return 125;
  } else if (feof(readme))
    puts("\n\nEnd of file reached successfully");

  fclose(readme);

  return 0;
}
