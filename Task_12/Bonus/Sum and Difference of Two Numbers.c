#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int number1 , number2 ;
float  number3 , number4 ;
int main()
{
 scanf("%d %d \n", &number1 , &number2);
    scanf("%f%f \n", &number3 , &number4);
    printf("%d %d \n",(number1 + number2),(number1 - number2));
    printf("%0.1f %0.1f \n",(number3 + number4),(number3 - number4));

    return 0;
}
