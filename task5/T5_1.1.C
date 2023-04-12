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
        }
        /********************************/
        /*“realloc”   is used to dynamically change the memory allocation of a previously allocated memory.
        if the memory previously allocated with the help of malloc or calloc is insufficient,
        realloc can be used to dynamically re-allocate memory.
        re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value*/
        int n1 ;
         printf("\nEnter the new size of the array");
         scanf("%d",&n1);

        ptr3 = realloc(ptr2, n1 * sizeof(int));

        for (int i = n; i < n1; ++i) {
            ptr3[i] = i + 1;
        }

        printf("The elements of the array are: ");
        for (int i = 0; i < n1; ++i) {
            printf("%d ", ptr3[i]);
        }

        free(ptr3);
        free(ptr2);
    }
    return 0;
}
