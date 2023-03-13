#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val = 0x123456;
    int *ptr = &(val) ;
    printf("*ptr = 0x%x\n",ptr);

    *ptr++;
    printf("*ptr++ = 0x%x\n",ptr);
    /**ptr++ effectively dereferences the pointer > then increments the pointer*/

    *++ptr ;
    printf("*++ptr = 0x%x\n",ptr);
    /**++ptr effectively increments the pointer > then dereferences the pointer*/
    ++*ptr ;
    printf("++*ptr = 0x%x\n",ptr);
    /*++*ptr effectively dereferences the pointer> then increments dereferenced value*/

    return 0;
}
