#include <stdio.h>
#include <stdlib.h>
extern int add(void) ;
z;
void next( void );
extern m ;
int main()
{   int y = add();
    printf("%d\n",y);

    z++ ;
    printf("%d\n",z);

    next();
    next();

    int *p = &m ; /*error,we cannot get a memory location when dealing with CPU register*/
    return 0;
}
