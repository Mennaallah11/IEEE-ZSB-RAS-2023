#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
     char words[1000];
     scanf("%[^\n]*c",words);
     for(int i = 0 ; i < strlen(words);i++)
     {
         if (words[i]==' ')
         {
         printf("\n");
         }
         else {
          printf("%c",words[i]);
         }
     }
    return 0;
}
