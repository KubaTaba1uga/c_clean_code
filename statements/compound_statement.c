int main(void) {
  /* Compound statement is sometimes */
  /*   called block. It creates lifetime and */
  /*   scope for variables defined inside it. */

  { int a = 5; }
  int a = 5;

  /* Empty compound statement is also valid; */
  {}

  return 0;
}
