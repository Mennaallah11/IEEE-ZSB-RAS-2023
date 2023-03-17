#include <stdio.h>
#include <stdlib.h>

struct database{
    struct shops {
        char *name ;
        char *location ;
    };
     struct product_info {
        int id ;
        int  price ;
        int quantity ;
    };
    struct category {
        int id_category;
        int products_num;
    };
}size_of ;
int main()
{
    printf("The Size of the struct is: %d\n",sizeof(size_of));
    printf("The Size of the struct shops is: %d\n",sizeof(struct shops));
    printf("The Size of the struct product_info is: %d\n",sizeof(struct product_info));
    printf("The Size of the struct category is: %d\n",sizeof(struct category));

    return 0;
}
/**
     The size of a structure is equal to the sum of the sizes of each data member.
     The size of a union is equal to the size of its largest data member size. **/

