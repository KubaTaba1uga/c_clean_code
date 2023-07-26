#include <stdio.h>
/* `strcpy` dependency */
#include <string.h>
/* A structure type contains sequentially
allocated memory objects, but unlike
array they can be different types. */

typedef struct {
  char name[50];
  int age;
  int salary;
} employee; // `employee` becomes alias for anonymous struct

int main(void) {
  /* Create object and pointer of `struct employee` type. */
  employee Jakub, *Jakub_p;

  /* Assign values directly*/
  strcpy(Jakub.name, "Jakub");
  Jakub.age = 24;
  Jakub.salary = 1000000;

  printf("  Employee Name: %s\n", Jakub.name);
  printf("   Employee Age: %i\n", Jakub.age);
  printf("Employee Salary: %d$\n", Jakub.salary);

  /* Create pointer to structure */
  Jakub_p = &Jakub;

  /* Assign value via pointer */
  strcpy(Jakub_p->name, "Kuba"); // clean way
  printf("  Employee Name: %s\n", Jakub.name);
  strcpy((*Jakub_p).name, "Kubek"); // manual way
  printf("  Employee Name: %s\n", Jakub.name);

  return 0;
}
