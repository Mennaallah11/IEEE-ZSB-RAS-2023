#include <stdio.h>
#include <stdlib.h>
struct test1{
 int id ;/*4 bayt*/
 char *name ;/*8 bayt*/
 char class_id ;/*4bayt */
};

struct test2{
 char *name ;
 int id ;
 char class_id ;
};

int main()
{
    printf("size of struct test1 : %d\n",sizeof(struct test1));

    printf("size of struct test2 : %d\n",sizeof(struct test2));
    return 0;
}
/*The sizeof for a struct is not always equal to the sum of sizeof of each individual member.
This is because of the (Padding) added by the compiler . Padding is only added when a structure member is followed by a member
with a larger size
case 1 = 4 + (4 padding) + 8 + 4 + (4 padding) = 24
case 2 = 8 + 4 + 4 = 16
*/

