#include <stdio.h>

int add(int a, int b) {
    return a+b;
}

int minus(int a, int b) {
    return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

typedef int (*f)(int, int);                 //declare typdef

f func[3] = {&add, &minus, &multiply};      //make array func of type f,
                                            //the pointer to a function
int main() {
    int i;
    for (i = 0; i < 3; ++i) printf("%d\n", func[i](5, 4));
    return 0;
}
