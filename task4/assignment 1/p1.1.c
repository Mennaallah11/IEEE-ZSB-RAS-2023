include <stdio.h>
#include <stdlib.h>
/*Bit fields must be declared as unsigned int or int.
 The maximum value that can store in unsigned int filed is (2^n) - 1*/
struct info {
  unsigned int roll_number: 4;/* range (0 to 15)*/
  unsigned int age: 8;/*range (0 to 255)  */
  unsigned int mark: 3;/*range (0 to 7)*/
   char name[30] ;
  char address[30] ;
};
void information(struct info student[15] ){
    for(int i = 0; i <15; i++){
        printf("Roll number : %i\n",i+1);
        printf("Name: %s\n",student[i].name);
        printf("Age : %i\n", student[i].age);
        printf("Address :%s\n",student[i].address);
        printf("Mark = %i\n", student[i].mark);
        printf("----------------------------\n");
    }}
int main()
{

    struct info student[15]={
    {1,21,20,"Menna","zagazig"},{2,21,19,"mohamed","zagazig"},{3,21,18,"Ahmed","zagazig"},{4,21,17,"Ali","zagazig"},{5 ,21,20,"Amira","zagazig"},
    {6,21,16,"maha","zagazig"},{7,21,19,"Alaa","zagazig"},{8,21,20,"aya","zagazig"},{9,21,19,"Asmaa","zagazig"},{10,21,20,"Amina","zagazig"},
    {11,21,19,"Shimaa","zagazig"},{12 ,21,18,"Radwa","zagazig"},{13,21,17,"Sara","zagazig"},{14,21,16,"mona","zagazig"},{15 ,21,20,"Hanan","zagazig"}};
        information(student);
        printf("Size of struct : %d bytes",sizeof(student));

    return 0;
}