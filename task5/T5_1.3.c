#include <stdio.h>

int main() {
    int size ;
    char arr[size];
    int count = 0 ;
    int maxCount=0 ;
    char maxElement ;
    printf("What is the largest size you can enter ?");
    scanf("%d",&size);
    printf("Enter a string  ");
    for (int z = 0 ; z <= size ; z++){
    scanf("%c",&arr[z]);
    printf("%c",arr[z]);}

        for (int i = 0 ; arr[i] != '\0';i++) {
        count =1 ;
        for (int j = i+1; arr[j] != '\0' ; j++){
        if (arr[i] == arr[j])
            count++;
             if(count > maxCount)
                {
                    maxElement = arr[j];
                    maxCount = count;
                }
    }}
    printf("\nFrequency of %c = %d",maxElement ,maxCount);
    return 0 ; }