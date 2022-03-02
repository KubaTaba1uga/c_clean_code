#include <stdio.h>

/* A union type contains sequentially
allocated memory objects, but unlike
array they can be different types and 
unlike structure data can overlap itself. */

/* Union declaration */
union {
  struct {
    int x;
    int y;
  } square;
  struct {
    int x;
    int y;
    int z;
  } triangle;
 /* Union tag */
} shape;

int main(void){

  shape.square.x = 5;

  shape.triangle.y = 3;

  int area = shape.square.x*shape.square.y;

  printf("Square area: %i\n", area);

  return 0;
}
