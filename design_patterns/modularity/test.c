/* ###################################################################### */
/* #                            Imports                                 # */
/* ###################################################################### */
#include "lib.h"
#include <stdio.h>

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

/* ###################################################################### */
/* #                            Main                                    # */
/* ###################################################################### */
int main(void) {
  int err;

  puts("Starting test_do_something");

  err = test_do_something();

  puts("Finished test_do_something");
}
