/* `switch` statement works just like the if...else ledder. */
/*	Except that the controlling expression must have an
        int type and passing one evaluation won't lead
        to stop attempting the others by default.*/
#include <stdio.h>

int main(void) {
  /* Imagine a game where rewards are */
  /*   granted depending on user's score. */

  int points = 65;

  switch (points / 10) {
  case 10:
    puts("Maximum score!! Reward: Gold duck.");
    /* `break` keyword is needed to stop */
    /*   evaluating next cases. */
    break;
  case 9:
    puts("Reward: Silver duck.");
    break;
  case 8:
    puts("Reward: Brown duck.");
    break;
  case 7:
    puts("Reward: Gold peagon.");
    break;
  case 6:
    puts("Reward: Silver peagon.");
    break;
  case 5:
    puts("Reward: Brown peagon.");
    break;
  default:
    puts("Score to low!! No reward this time :(");
  }

  return 0;
}
