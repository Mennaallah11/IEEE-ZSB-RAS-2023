#include <stdio.h>
#include <stdlib.h>

int main()
{
     int arr1[5], n,count=0;
    int i, j;
       printf("enter 5 numberse : ");
       for(i=0;i<5;i++)
            {
	      scanf("%d",&arr1[i]);
	    }
    printf("\nThe unique elements found in the array are: \n");
    for(i=0; i<5; i++)
    {
        count=0;
        for(j=0; j<5; j++)
        {

            if (i!=j)
            {
		       if(arr1[i]==arr1[j])
              {
                 count++;
               }
             }
        }
       if(count==0)
        {
          printf("%d ",arr1[i]);
        }
    }

    return 0;
}
