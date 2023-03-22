#include <stdio.h>
#include <stdlib.h>
typedef int num_1;
typedef unsigned int num1_unsigned_int;
typedef float num_2;
typedef short num_3;
typedef long num_4;
typedef double num_5;
typedef char char_1;
typedef unsigned char Char1_unsigned_char;

int main()
{
    printf(" the size of int is: %d bytes\n",sizeof(num_1));
    printf(" the size of unsigned int is: %d bytes\n",sizeof(num1_unsigned_int));
    printf(" the size of float is: %d bytes\n",sizeof(num_2));
    printf(" the size of shortis : %d bytes\n",sizeof(num_3));
    printf(" the size of long is: %d bytes\n",sizeof(num_4));
    printf(" the size of double is: %d bytes\n",sizeof(num_5));
    printf(" the size of char is: %d bytes\n",sizeof(char_1));
    printf(" the size of unsigned char is: %d bytes\n",sizeof(Char1_unsigned_char));
return 0;

}
