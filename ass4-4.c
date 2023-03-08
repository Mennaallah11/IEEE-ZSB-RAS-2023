#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr1[100], arr2[100];
    printf("Enter the string: ");
    scanf("%s", arr1);
    printf("\nString 1 = %s", arr1);
    strcpy(arr2, arr1);
    printf("\nString 2 = %s", arr2);

    return 0;
}
