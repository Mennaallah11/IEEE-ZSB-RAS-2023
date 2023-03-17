#include <stdio.h>
#include <stdlib.h>

struct student {
 char roll_number ;
 char name[30] ;
 int age ;
 char address[30] ;
 int mark ;
}student[15];
void information(struct student student[15] ){
    int count = 0 ;
    for(int i = 0; i <15; i++){
        printf("Roll number : %i\n",i+1);
        printf("Name: %s\n",student[i].name);
        printf("Age : %i\n", student[i].age);
        printf("Address :%s\n",student[i].address);
        printf("Mark = %i\n", student[i].mark);
        printf("----------------------------\n");
        if (student[i].mark < 12)
            count ++ ;
    }
printf("Number of students gets mark less than 12 = %i ",count);
}
int main()
{
     printf("Enter information :\n");
     for(int i = 0 ; i <15 ; i++){
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
        if (student[i].mark > 20 ){
        printf("Error : the full mark is of 20 , try agin");
        break ;
      }}
    if (student->mark < 20 ){
      information(student);}

    return 0;
}
