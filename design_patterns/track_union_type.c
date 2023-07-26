/* You can store lots of possible values in a union, */
/*   but you have no way of knowing what type it was */
/*   once it’s stored.  */

/* The compiler won’t be able to keep track of the fields */
/*   that are set and read in a union, so there’s nothing */
/*   to stop us setting one field and reading another. */
/*   It can be a BIG PROBLEM. */

#include <stdio.h>
enum unit { KILOGRAMS, PIECES };

union quantity {
  float weight;
  int count;
};

typedef struct {
  enum unit unit;
  union quantity quantity;
} amount;

int print_amount(amount amount);

int main() {
  amount computers = {.unit = PIECES, .quantity.count = 5};
  amount fruits = {.unit = KILOGRAMS, .quantity.weight = 21.42};
  int error;

  puts("STOCK");

  fputs("Computers: ", stdout);
  error = print_amount(computers);
  if (error)
    return 1;

  puts("");

  fputs("Fruits: ", stdout);
  error = print_amount(fruits);
  if (error)
    return 2;

  puts("");

  return 0;
};

int print_amount(amount amount) {
  switch (amount.unit) {
  case KILOGRAMS:
    printf("%.2f KG", amount.quantity.weight);
    break;
  case PIECES:
    printf("%i", amount.quantity.count);
    break;
  default:
    // error
    return 1;
  }
  // print succeed
  return 0;
}
