#include <stdio.h>
#include <stdlib.h>
typedef enum {
  addition,subtraction,multiplication,division,AND,OR,NOT
}arithmetic_operation;
int main()
{
    int operation1,operation2;
    char operation3 ;
    arithmetic_operation op ;

    printf("Please Enter Number 1: ");
    scanf("%d",&operation1);
    printf("Please Enter Number 2: ");
    scanf("%d",&operation2);
    printf("Pease Choose your operation [+,-,*,/,&,|,!]: ");
    getchar();
    operation3 = getchar();
    switch(operation3){
    case '+':
      op = addition;
      break;
    case '-':
      op = subtraction;
      break;
    case '*':
      op = multiplication;
      break;
    case '/':
      op = division;
      break;
    case '&':
      op = AND;
      break;
    case '|':
      op = OR;
      break;
    case '!':
      op = NOT ;
    default:
      printf("ERROR : Invalid operation\n");
      break;
    }
    switch (op){
    case addition:
    printf("Addition = %d \n",operation1+operation2);
    break;
    case subtraction:
    printf("Subtraction = %d \n",operation1-operation2);
    break;
    case multiplication :
    printf("multiplication = %d \n",operation1*operation2);
    break;
    case division:
    printf("division = %d \n", operation1/operation2);
    break;
    case AND:
    printf("AND = %d\n",operation1&operation2);
    break;
    case OR:
    printf("OR = %d\n",operation1|operation2);
    break;
    case NOT:
    printf("!%d = %d\n", operation1,!operation1);
    printf("!%d = %d\n", operation2,!operation2);
    break;
  }
  printf("The Size of enum is: %d bytes",sizeof(op));
  /*The C standard specifies that enums are integers, but it does not specify the size.
   that is up to the people who write the compiler. On an 8-bit processor, enums can be 16-bits wide.
    On a 32-bit processor they can be 32-bits wide or more or less.
  I in compiler, the size of enum is 4 bytes , if  add extra members
    the size of it remains the same*/*/

    return 0;
}
