#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* ptr0;
    int* ptr1;
    int* ptr2;
    int* ptr3;
    int n;
    printf("Enter number of elements:");

    scanf("%d",&n);

    ptr0 = (int*)malloc(n*sizeof(int));

    if (ptr0 == NULL) {

        printf("Memory not allocated.\n");}

    else {

        for (int i = 0; i < n; ++i) {

            ptr0[i] = i + 1;}

        printf("The elements of the array are:\n");
        for (int i = 0; i < n; ++i) {
            printf("%d ", ptr0[i]);
        }
    }
    /*********************************************************************/
    printf("\nEnter number of elements:");

    scanf("%d",&n);

    ptr1 = (int*)malloc(n*sizeof(int));

    if (ptr1 == NULL) {

        printf("Memory not allocated.\n");
    }
    else {
        for (int i = 0; i < n; ++i) {
            ptr1[i] = i + 1;
        }
        printf("The elements of the array are\n: ");
        for (int i = 0; i < n; ++i) {
            printf("%d ", ptr1[i]);
        }
    }
    /***********************************************************/
    printf("\nEnter number of elements:");

    scanf("%d",&n);

    ptr2 = (int*)calloc(n, sizeof(int));

    if (ptr2 == NULL) {

        printf("Memory not allocated.\n");
    }
    else {

        for (int i = 0; i < n; ++i) {
            ptr2[i] = i + 1;
        }

        printf("The elements of the array are: ");
        for (int i = 0; i < n; ++i) {
            printf("%d ", ptr2[i]);
        }}
        free(ptr2);
        /********************************/
        /*Limited space in memory causes stack overflow in memory*/
     printf("Enter the largest number of elements:");

    scanf("%d",&n);

    ptr3 = (int*)malloc(n*sizeof(int));

    if (ptr3 == NULL) {

        printf("Memory not allocated.\n");}

    else {

        for (int i = 0; i < n; ++i) {

            ptr3[i] = i + 1;}

        printf("The elements of the array are:\n");
        for (int i = 0; i < n; ++i) {
            printf("%d ", ptr3[i]);
        }
    }
    return 0 ;
    }