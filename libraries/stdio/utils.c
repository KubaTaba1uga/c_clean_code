#include "utils.h"

bool is_printable_char(int char_) {
  bool too_low = char_ < LOWEST_0;
  bool in_gap = (char_ > HIGHEST_0 && char_ < LOWEST_1);
  bool too_high = char_ > HIGHEST_1;
  return !(too_low || in_gap || too_high);
}

char get_random_char(void) {
  int now = time(NULL);
  int seed = rand();
  int new_seed = now * seed;
  int char_;

  srand(new_seed);

  do {
    char_ = (rand() % HIGHEST_1) + LOWEST_0;
  } while (!is_printable_char(char_));
  return char_;
}

void create_random_word(char *word, size_t word_size) {
  for (size_t i = 0; i < word_size; ++i)
    word[i] = get_random_char();
}
