#include <stdio.h>
#include <stdlib.h>

typedef struct {
 char roll_number ;
 char name[30] ;
 int age ;
 char address[30] ;
 int mark ;
}info ;

int main()
{
    info student[15];
     printf("Enter information :\n");
      for(int i = 0; i <15 ; i++){
        printf("roll number : %d \n",i+1);
        printf("Enter name : ");
        scanf("%s",&student[i].name);
        printf("Enter Age : ");
        scanf("%d",&student[i].age);
        printf("Address : ");
        scanf("%s",&student[i].address);
        printf("Enter Mark :");
        scanf("%i",&student[i].mark);
        printf("--------------------------\n");
    }
    for(int i = 0; i <15; i++){
        printf("Roll number : %i\n",i+1);
        printf("Name: %s\n",student[i].name);
        printf("Age : %i\n", student[i].age);
        printf("Address :%s\n",student[i].address);
        printf("Mark = %i\n", student[i].mark);
        printf("----------------------------\n");
    }


    return 0;
}


