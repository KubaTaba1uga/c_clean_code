#include <stddef.h>
#include <stdio.h>

int main() {
  char best_food[25];

  printf("Enter your favourite food:");
  /* sizeof can be used because of array variable. */
  fgets(best_food, sizeof(best_food), stdin);

  size_t worst_food_size = 25;
  char worst_food[worst_food_size];
  char *worst_food_p = worst_food;
  printf("Enter your most hated food:");
  /* sizeof can be used because of array variable. */
  fgets(worst_food, worst_food_size, stdin);

  printf("Best: %sWorst: %s", best_food, worst_food);

  return 0;
}
