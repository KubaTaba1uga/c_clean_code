#include <locale.h>
#include <stdio.h>
#include <uchar.h>

#if __STDC_UTF_16__ != 1
#error "__STDC_UTF_16__ not define"
#endif

mbstate_t state = {0};

int main(void) {
  setlocale(LC_ALL, "en_US.utf8");
  char input[] = "zß水🍌";
  size_t input_size = sizeof(input);

  char16_t output[input_size];
  char16_t *p_output = output;

  char *p_input = input, *end = input + input_size;

  size_t convertion_result;

  while ((convertion_result =
              mbrtoc16(p_output, p_input, end - p_input, &state))) {
    if (convertion_result == (size_t)-1) { // invalid input
      goto EXIT_FAILURE;
      break;
    } else if (convertion_result == (size_t)-2) { // truncated input
      goto EXIT_FAILURE;
      break;
    } else if (convertion_result == (size_t)-3) // UTF-16 high surrogate
      p_output += 1;
    else {
      p_input += convertion_result;
      p_output += 1;
    };
  }

  // output_size = last element address - first element address + space for '\0'
  size_t output_size = p_output - output + 1;

  printf("The word: %s\n", input);

  printf("%zu UTF-8 code units: [ ", input_size);
  for (size_t n = 0; n < input_size; ++n)
    printf("%#x ", (unsigned char)input[n]);
  puts("]");

  printf("%zu UTF-16 code units: [ ", output_size);
  for (size_t x = 0; x < output_size; ++x)
    printf("%#x ", output[x]);
  puts("]");

  return 0;

EXIT_FAILURE:
  printf("ERROR: convertion return code == %li", convertion_result);
  return (-1);
}
