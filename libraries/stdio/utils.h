#ifndef _UTILS_H
#define _UTILS_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define LOWEST_0 65
#define HIGHEST_0 90
#define LOWEST_1 97
#define HIGHEST_1 122

bool is_printable_char(int char_);

char get_random_char(void);

void create_random_word(char *word, size_t word_size);

#endif
