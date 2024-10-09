#include <stddef.h>
#include <stdio.h>

void print_memory_layout(void *ptr, size_t size);

struct InnerStruct {
  char s;
  char c;
};

struct OuterStruct {
  struct InnerStruct inner;
  long int d;
};

int main() {
  struct OuterStruct example = {
      {'C', 'C'}, // inner
      3           // d
  };

  printf("Size of struct: %zu bytes\n", sizeof(struct OuterStruct));
  printf("Offset>Size of 'inner': 0>%zu bytes\n", sizeof(example.inner));
  printf("Offset>Size of 'd': %zu>%zu bytes\n", offsetof(struct OuterStruct, d),
         sizeof(example.d));

  print_memory_layout(&example, sizeof(struct OuterStruct));

  return 0;
}

void print_memory_layout(void *ptr, size_t size) {
  unsigned char *byte_ptr = (unsigned char *)ptr;
  printf("\nMemory layout:\n");
  for (size_t i = 0; i < size; i++) {
    printf("%02X ", byte_ptr[i]);
    if ((i + 1) % 8 == 0)
      printf("\n"); // Newline every 8 bytes for readability
  }
  printf("\n");
}
