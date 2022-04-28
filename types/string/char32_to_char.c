#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <uchar.h>
#include <wchar.h>

#if __STDC_UTF_32__ != 1
#error "__STDC_UTF_32__ not define"
#endif

int main(void) {
  setlocale(LC_ALL, "");
  char32_t *input = U"źdźbło";

  size_t input_size = sizeof(input);

  char output[input_size];
  char *output_p = output;

  char32_t *input_p = input;

  size_t convertion_result;

  mbstate_t state = {0};

  for (size_t i = 0; i < input_size; i++) {
    convertion_result = c32rtomb(output_p, *input_p, &state);
    if (convertion_result == (size_t)-1) {
      break; // -1 == invalid code unit sequence detected
      return (EXIT_FAILURE);
    } else {
      output_p += convertion_result; // move forward by number of written values
      input_p++;                     // one value was written out
    }
  }

  printf("%s\n", output);

  return (EXIT_SUCCESS);
}
