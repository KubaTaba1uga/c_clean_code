#ifndef LIBOPS_H
#define LIBOPS_H

/* ###################################################################### */
/* #                            Modularity Boilercode                   # */
/* ###################################################################### */
struct LibOps {
  void (*do_foo)(int x);
  const char *(*do_bar)(void *p);
  void *private_ops;
};

struct LibOps *get_lib_ops(void);

#endif /* LIBOPS_H */
