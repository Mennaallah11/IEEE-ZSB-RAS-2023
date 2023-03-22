#include <stdio.h>
#include <stdlib.h>
#define add(x,y) x+y
#define sub(x,y) x-y
#define num_1 1
#define num_2 2
int main()
{
#ifdef add
printf("addition = %d\n
       ",add(num_1,num_2));
#endif // add
#ifdef sub
printf("addition = %d",sub(num_1,num_2));
#endif // sub
}
