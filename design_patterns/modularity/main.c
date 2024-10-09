#include "lib.h"

int main() {
  struct LibOps *lib_ops = get_lib_ops();

  lib_ops->do_foo(42);
  lib_ops->do_bar("asd");
}
