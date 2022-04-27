#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <uchar.h>
#include <wchar.h>

#if __STDC_UTF_16__ != 1
#error "__STDC_UTF_16__ not define"
#endif

int main(void) {
  setlocale(LC_ALL, "");
  char16_t input[] = u"źdźbło";

  size_t input_size = sizeof(input);

  char output[input_size];
  char *output_p = output;

  char16_t *input_p = input;

  size_t convertion_result;

  mbstate_t state = {0};

  for (size_t i = 0; i < input_size + 2; ++i) {
    convertion_result = c16rtomb(output_p, *input_p, &state);
    if (convertion_result == (size_t)-1)
      break; // -1 == invalid code unit sequence detected
    else {
      output_p += convertion_result; // move forward by number of written values
      input_p++;                     // one value was written out
    }
  }

  printf("%s\n", output);
}
