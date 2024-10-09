#include <stddef.h>
#include <stdio.h>

void print_memory_layout(void *ptr, size_t size);

struct PointerStruct {
  int *ptr;
  char value;
};

int main() {
  int num = 0xDEADBEEF;
  struct PointerStruct example = {
      &num, // ptr
      'C'   // value 0x43
  };

  printf("Size of struct: %zu bytes\n", sizeof(struct PointerStruct));
  printf("Offset>Size of 'ptr': 0>%zu bytes\n", sizeof(example.ptr));
  printf("Offset>Size of 'value': %zu>%zu bytes\n",
         offsetof(struct PointerStruct, value), sizeof(example.value));

  print_memory_layout(&example, sizeof(struct PointerStruct));

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
