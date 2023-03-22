#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int real;
    int imag;
}complex;

void add_complex_num(complex num_1 ,complex num_2 ){
   
     int real_num = num_1.real + num_2.real ;
     int imag_num = num_1.imag + num_2.imag ;

     printf("Sum of two complex num : %d + %di ",real_num,imag_num);
    }

int main()
{
    complex n1 ={1,10};
    complex n2 ={12,10};
    add_complex_num(n1,n2);
    return 0;
}
