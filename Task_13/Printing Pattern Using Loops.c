#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n ;
    scanf("%d", &n);
    int dimension_arr = 2*n-1;
    int arr[dimension_arr][dimension_arr];
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = i ; j < dimension_arr-i ; j++)
        {
            for (int k = i ; k <dimension_arr-i ; k++)
            {
              arr[j][k]=n-i;
            }
        }
    }
    for (int i = 0 ;i < dimension_arr ; i++)
    {
        for (int j = 0 ; j < dimension_arr ; j ++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
   return 0;
}