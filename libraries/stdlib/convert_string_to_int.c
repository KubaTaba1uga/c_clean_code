#include <stdio.h>
/* `atoi` dependency */
#include <stdlib.h>
 
int main(void)
{
    printf("%i\n", atoi(" -123junk"));
    printf("%i\n", atoi("0"));
    printf("%i\n", atoi("junk"));         // no conversion can be performed
    printf("%i\n", atoi("2147483648"));   // UB: out of range of int
}
