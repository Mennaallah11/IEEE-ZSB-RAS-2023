#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1 ;
    char *p2 ;
    long long *p3 ;
    printf("p1 = %d\n",p1);
    p1++ ;
    printf("p1++ = %d\n",p1);

    printf("p2 = %d\n",p2);
    p2++ ;
    printf("p2++ = %d\n",p2);

    printf("p3 = %d\n",p3);
    p3++ ;
    printf("p3++ = %d\n",p3);
  /* p++, the p will point to the location  it will point to the next integer location which is 4 bytes next to the current location.
   This operation will move the pointer to the next memory location without impacting the actual value at the memory location.
   If p points to a character whose address is 1000, then the operation will point to the location 1001 because the next character will be available at 1001.*/

    return 0;
}
