#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,result;
    int *x , *y ;
    printf("Enter Two Values: ");
    scanf("%d %d",&num1,&num2);
    result =add(&num1,&num2);
    printf("The Sum is: %d",result);
    return 0;
}
 int add(int *x,int *y)
{
    int z;
    z=*x+*y;
    return(z);
}
