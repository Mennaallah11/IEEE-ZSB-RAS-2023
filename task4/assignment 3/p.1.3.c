#include <stdio.h>
#include <stdlib.h>
#define clc Descending_order
#ifdef clc
void Ascending_order(){
    int arr[5] ,num;
    for(int i=0;i<5;i++){
        printf("please Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int j =0 ;j<5;j++){
        for(int x = j+1;x<5;x++){
            if (arr[x]<arr[j]){
                num=arr[j];
                arr[j]=arr[x];
                arr[x]=num;
            }}}
    printf("Your Numbers After Arranging in Ascending order:\n ");
    for(int i=0;i<5;i++){
        printf("%d\n",arr[i]);
}}
void Descending_order(){
    int arr [5] ,num;
    for(int i=0;i<5;i++){
        printf("please Enter number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int j =0 ;j<5;j++){
        for(int x = j+1;x<5;x++){
            if (arr[x]>arr[j]){
                num=arr[j];
                arr[j]=arr[x];
                arr[x]=num;
            }
        }
    }
    printf("Your Numbers After Arranging in Descending order :\n ");
    for(int i=0;i<5;i++){
        printf("%d\n ",arr[i]);
}}
#endif

int main(){
    clc();
      return 0;
}
