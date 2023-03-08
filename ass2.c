#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1 , y = 2, z = 3 ;
    int *p , *q , *r ;
    p=&x ;
    q=&y;
    r=&z;
    printf("%d %d %d \n",x , y ,z);
    printf("%d %d %d\n",p , q ,r);
    printf("%p %p %p\n",*p ,*q ,*r);
    printf("swapping pointers.\n");
    r = p ;
    p = q ;
    q = r ;
    printf("%d %d %d \n",x , y ,z);
    printf("%d %d %d\n",p , q ,r);
    printf("%p %p %p\n",*p ,*q ,*r);
    return 0;
}
