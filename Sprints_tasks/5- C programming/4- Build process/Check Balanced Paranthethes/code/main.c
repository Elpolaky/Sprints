#include"balanced.h"

uint8_t data, i;
char expression, state;
char* ptr_expression = &expression;
uint8_t* ptr_data = &data;
uint8_t topData;
uint8_t* ptr_topData = &topData;

int main()
{


    uint8_t data[10];
    int8_t expressionState = 0;
    createEmptyStack(ptr_stack);
    while (1) {
        printf("\nEnter expression:");
        scanf("%s", &expression);
        state = isBalancedParanthethes(ptr_expression);
        switch (state) {
        case 0:  printf("\nThe expression is balanced"); break;
        case -1: printf("\nThe expression is not balanced"); break;
        case -2: printf("\nThe expression doesn't include paranthethes"); break;
        }
    }
    return  0;
    }




