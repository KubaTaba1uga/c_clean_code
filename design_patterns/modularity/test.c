/* ###################################################################### */
/* #                            Imports                                 # */
/* ###################################################################### */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

/* ###################################################################### */
/* #                            Mocks                                   # */
/* ###################################################################### */
struct TestData {
  int mock_lib_do_sth_counter;
};
struct TestData test_data;

void mock_lib_do_something(void) { test_data.mock_lib_do_sth_counter++; }
void prepare_test_data(void) { memset(&test_data, 0, sizeof(struct TestData)); }

// Custom assert macro for integers
#define TEST_ASSERT_INT(cond, msg)                                             \
  do {                                                                         \
    if (!(cond)) {                                                             \
      fprintf(stderr, "Assertion failed: %s\n", msg);                          \
      return 1;                                                                \
    }                                                                          \
  } while (0)

/* ###################################################################### */
/* #                            Modularity Boilercode                   # */
/* ###################################################################### */
struct PrivateLibOpsCopy { // This struct needs to be exact copy of
                           // PrivateLibOps
  void (*do_something)(void);
};

/* ###################################################################### */
/* #                            Test                                    # */
/* ###################################################################### */
int test_do_something(void) {
  struct LibOps *lib_ops = get_lib_ops();
  struct PrivateLibOpsCopy *priv_lib_ops = lib_ops->private_ops;

  priv_lib_ops->do_something();

  return 0;
}

int test_do_foo(void) {
  struct LibOps *lib_ops = get_lib_ops();
  struct PrivateLibOpsCopy *priv_lib_ops = lib_ops->private_ops;

  priv_lib_ops->do_something = mock_lib_do_something;

  lib_ops->do_foo(1);

  TEST_ASSERT_INT(test_data.mock_lib_do_sth_counter == 1,
                  "test_data.mock_lib_do_sth_counter has to be equal 1");

  return 0;
}

int test_do_bar(void) {
  struct LibOps *lib_ops = get_lib_ops();
  struct PrivateLibOpsCopy *priv_lib_ops = lib_ops->private_ops;

  priv_lib_ops->do_something = mock_lib_do_something;

  lib_ops->do_bar(priv_lib_ops);

  TEST_ASSERT_INT(test_data.mock_lib_do_sth_counter == 1,
                  "test_data.mock_lib_do_sth_counter has to be equal 1");

  return 0;
}

/* ###################################################################### */
/* #                            Main                                    # */
/* ###################################################################### */

struct TestFunc {
  const char *id;
  int (*test_func)(void);
};

int main(void) {
  struct TestFunc test_functions[] = {
      {.id = "Test do_something", .test_func = test_do_something},
      {.id = "Test do_foo", .test_func = test_do_foo},
      {.id = "Test do_bar", .test_func = test_do_bar}};
  size_t i;
  int err;

  puts("Starting test suite\n");

  for (i = 0; i < sizeof(test_functions) / sizeof(struct TestFunc); i++) {
    printf("\nStarting: '%s'\n", test_functions[i].id);

    err = test_functions[i].test_func();

    printf("Finished: '%s' with result '%s'\n\n", test_functions[i].id,
           err == 0 ? "success" : "failure");
  }

  puts("\nFinished test suite");
}
