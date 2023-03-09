#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr1[100],arr2[100];
    int flag =1 ;
    printf("Enter a string 1\n");
    gets(arr1);
    printf("Enter a string 1\n");
    gets(arr2);
    int length_1=strlen(arr1);
    int length_2=strlen(arr2);
    if(length_1==length_2){
    	for(int i=0;i<length_1;i++){
        	if(arr1[i]!=arr2[i]){
            		flag=0;
	                break;
		}
        }
    }

    else{
    	flag=0; }

    if(flag==1){
        printf("The two string are equal\n");
        printf("%s = %s",arr1,arr2);
    }
    else{
        printf("The two string are not equal!!!\n");
        printf("%s != %s",arr1,arr2);}
    return 0;
}
