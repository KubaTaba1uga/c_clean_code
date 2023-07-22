/* `break` keyword stops processing next rules. */
/*	It can be used for behaviours grouping.*/
#include <stdio.h>
#include <stdlib.h>

int calc_card_value(char *card) {
  /* Return number bigger than 0 if calculating value succeeded. */
  /* Return 0 if unable to calculate value. */
  int card_value;

  switch (card[0]) {
  case 'J':
  case 'Q':
  case 'K':
    card_value = 10;
    break;
  case 'A':
    card_value = 11;
    break;
  default:
    card_value = atoi(card);
  }

  return card_value;
}

int main(void) {
  /* Imagine a blackjack game. Let's assign  */
  /*   cards strings to it's values. */
  char card[] = "A";
  int card_value = calc_card_value(card);

  printf("Card: %s\nValue: %i\n", card, card_value);

  return 0;
}
