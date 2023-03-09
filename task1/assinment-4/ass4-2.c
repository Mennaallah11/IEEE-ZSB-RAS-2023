#include <stdio.h>
#include <stdlib.h>

int main()
{
  char arr[100];
    printf("Enter a string\n");
    gets(arr);
    for(int i = 0; i < strlen(arr); i++){
        printf("%c", arr[i]);
    }
    return 0;
}
