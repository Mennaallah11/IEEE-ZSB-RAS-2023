#include<stdio.h>
#define my_sizeof(type) (char *)(&type+1)-(char *)(&type)
static inline int my_sizeof1(int type){return (char *)(&type+1)-(char *)(&type);}
int main(){
    int val1,val2;
    printf("The size of variable using macros: %d\n",my_sizeof(val1));
    printf("The size of variable using inline function: %d \n",my_sizeof1(val2));

    return 0;}
/*The sizeof() operator is a compile-time operator that returns the size of a data type in bytes.
1-macro implementation This implementation can be used for any data type at compile time and is evaluated by the preprocessor. 
However, it does not perform any type checking, so it can lead to unexpected results if used improperly . 
The best use case for the macro implementation is when the data type is not known until runtime,
2- The inline implementation  This implementation is evaluated at run time and performs type checking,
 so it is safer to use than the macro implementation. However, it can only be used with data types that are known at compile time,
  and it may generate larger executable code due to the inlining process.
    The best use case is when the data type is known at compile time
*/