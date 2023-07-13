#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char num[1000];
    int numberCounter[1000] = {0};
    scanf("%[^\n]*c",num);
    for ( int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0; j<strlen(num);j++)
        {
            if (num[j]==(i+48))
            {
              numberCounter[i]++;
            }
        }

        printf("%d ",numberCounter[i]);
    }




    return 0;
}
