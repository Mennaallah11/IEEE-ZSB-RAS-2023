#include <stdio.h>
#include <stdlib.h>
struct into {
    char *name;
    int age;
};
int main()
{
    struct into data = {"menna allah mohamed",21};
    struct into *p = &data ;
    printf("Here is your info accessed by pointer:\n name : %s \n age : %d",p->name,p->age);
    return 0;
}
