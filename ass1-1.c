#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5] ;
    int count = 0 ;
    printf("Enter 5 numbers : ");
    for (int i = 0 ; i < 5 ; i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0 ; i < 5 ; i++){
    for (int j = i+1 ; j < 5 ; j++){
        if(arr[i]==arr[j]){
            count ++ ;
            break;
    }}}
      printf("Total number of duplicate elements found in array = %d",count);
    return 0;
}
