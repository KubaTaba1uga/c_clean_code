#include <stdio.h>

void print_addresses_by_index(size_t n, int arr[n]) {
  for (int x = 0; x < (int)n; x++)
    printf("%p\n", &arr[x]);
}

void print_address_by_pointer(size_t n, int *arr) {
  while (n-- > 0)
    printf("%p\n", arr++);
}

int main() {
  size_t size = 5;
  int a[5] = {11, 22, 33, 44, 55};

  print_addresses_by_index(size, a);
  puts("");
  print_addresses_by_index(size, a);

  return (0);
}
