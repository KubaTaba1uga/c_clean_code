#include <stdio.h>
#include <stdlib.h>

int main() {

  char ch, word[16], sentence[64];

  printf("Type one character: ");
  // Take one character
  scanf("%c", &ch);

  printf("Type one word: ");
  // Take collection of characters
  //  until space char is met
  scanf("%s", word);
  // It is required because previous
  //  scanf invokation didn't took `\n`
  scanf("\n");

  printf("\nType one sentence: ");
  // Take collection of characters
  //  until `\n` char is met
  scanf("%[^\n]%*c", sentence);

  printf("\n%c\n", ch);
  printf("%s\n", word);
  printf("%s", sentence);

  return 0;
}
