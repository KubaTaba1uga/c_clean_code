#ifndef UTILS_H
#define UTILS_H

void stdin_buffer_cleanup(void);

void print_error(const char *message);

void take_input(void *n, const char *n_format, const char *question);

int take_input_warning(int n_max, int n_min, const char *question,
                       const char *n_format);

void take_double_input(void *n, const char *n_format, const char *question);

#endif
