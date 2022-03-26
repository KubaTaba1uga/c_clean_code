int main(void) {
  char *src;    // `src` has a type of pointer to char type
  char c;       // `c` has a type of char
  int x;        // `x` has a type of int
  int y[5];     // `y` has a type of 5 elements of type int
  int m[12];    // `m` has a type of 12 elements of type int
  int n[15][3]; // `n` has a type of 15 arrays of 3 elements of type int

  /* Variables can be declared multiple */
  /*         types within one line of code. */

  char *src, c;

  int x, y[5], m[12], n[15][3];

  return 0;
}
