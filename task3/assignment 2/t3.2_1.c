#include <stdio.h>
#include <stdlib.h>
struct Data {
    char day[10];
    char month[10];
    char year[10];
}date[1];

int main()
{
    int i ;
    for(i = 0 ; i <2 ; i++){
        printf("Enter day %i : ",i+1);
        scanf("%s",&date[i].day);
        printf("Enter month %i : ",i+1);
        scanf("%s",&date[i].month);
        printf("E enter year %i : ",i+1);
        scanf("%s",&date[i].year);
    }
    int day = strcmp(date[0].day,date[1].day);
    int month= strcmp(date[0].month,date[1].month);
    int year = strcmp(date[0].year,date[1].year);
    if (day == 0 && month == 0 && year == 0){
        printf("Dates are equal");}
    else
        printf("Dates are not equal");

    return 0;
}
