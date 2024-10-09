/* ###################################################################### */
/* #                            Imports                                 # */
/* ###################################################################### */
#include "lib.h"
#include <stdio.h>

/* ###################################################################### */
/* #                            Private Declarations                    # */
/* ###################################################################### */
struct PrivateLibOps {
  void (*do_something)(void);
};
static void lib_do_foo(int x);
static void lib_do_something(void);
static const char *lib_do_bar(void *p);
static struct PrivateLibOps private_lib_ops = {.do_something =
                                                   lib_do_something};

/* ###################################################################### */
/* #                            Modularity Boilercode                   # */
/* ###################################################################### */
static struct LibOps lib_ops = {.do_foo = lib_do_foo,
                                .do_bar = lib_do_bar,
                                .private_ops = &private_lib_ops};

struct LibOps *get_lib_ops(void) { return &lib_ops; }

/* ###################################################################### */
/* #                            Public API                              # */
/* ###################################################################### */
static void lib_do_foo(int x) { printf("Doing foo %d\n", x); }

static const char *lib_do_bar(void *p) {
  printf("Doing bar: %p\n", p);
  return "Hello";
}

/* ###################################################################### */
/* #                            Private API                             # */
/* ###################################################################### */
static void lib_do_something(void) { puts("Doing something"); }
