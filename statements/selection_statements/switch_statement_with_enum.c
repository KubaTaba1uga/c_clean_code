#include <stdio.h>
/* `abort` dependency */
#include <stdlib.h>

typedef enum { NormalAccount, SavingsAccount, PremiumAccount } accountType;

float find_interests(accountType account) {
  switch (account) {
  case NormalAccount:
    return 0.05;
  case SavingsAccount:
    return 0.04;
  case PremiumAccount:
    return 0.02;
  default:
    // If account is none from the above,
    //	  terminate program producing
    //	  error code 3.
    puts("In find_interests function, provided non considered case");
    abort();
  }
}

int main(void) {
  /* Imagine bank that has to assign interests  */
  /*   procentage based of account type. */

  accountType account = PremiumAccount;

  float interest = find_interests(account);

  printf("Account interest is %.1f%%\n", interest * 100);

  return EXIT_SUCCESS;
}
