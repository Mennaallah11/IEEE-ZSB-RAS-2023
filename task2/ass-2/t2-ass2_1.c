#include <stdio.h>
#include <stdlib.h>


void increment(int x)
{
    x=x+1 ;
    printf("x = %d\n",x);
}
int main() {

 void (*p)(int);
   p = &increment;
   (*p)(2);
}
