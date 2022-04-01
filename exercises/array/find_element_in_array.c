#include <errno.h>
#include <stdio.h>

int find_element_i(int *arr, int len, int element) {
  int pos = ERANGE;
  for (int i = 0; i < len; i++) {
    if (*arr++ == element) {
      pos = i;
      break;
    }
  }
  return pos;
}

int main(void) {
  int arr[10] = {5, 2, 3, 6, 8, 0, 3, 5, 9, 1};

  int i = find_element_i(arr, 10, 1);

  printf("1 is at index %i", i);

  return 0;
}
