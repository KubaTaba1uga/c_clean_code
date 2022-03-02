#include <stdio.h>

void show_array(int array[3][3]){
  printf("array[3][3]= [");

  for (int i=0 ; i < 3; ++i) {

    printf("\n    [");

    for (int j=0; j < 3; ++j) {
      if (j<2){
	printf("%d, ", array[i][j]);
      } else {
        printf("%d", array[i][j]);
      }
    }

    if (i<2){
      printf("],");
    } else {
      printf("]");
    }
  }

  printf("\n  ]\n");
}

void show_element(int i, int j, int value){
  printf("array[%d][%d]=%d\n",i, j, value);
}


int main(void){
  /* Create array of 3 arrays, each */
  /*   containing 3 integers */
  int array[3][3] = {
				{1,2,3},
				{4,5,6},
				{7,8,9}
			    };

  /* To access N array of two dimmensional array */
  /*   use pattern: *(*(<array pointer> + <array index>) + <element index>) */
  int first_array_first_value = *(*(array + 0)+0) ;

  int third_array_second_value =  *(*(array + 2)+1) ;

  /* The same could be done by shortcut */
  int second_array_first_value = array[1][0];
 
  show_array(array);

  show_element(0, 0, first_array_first_value);
  
  show_element(1, 0, second_array_first_value);

  show_element(2, 1, third_array_second_value);

  return 0;
}
