#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10
#define FULL_STACK -1
#define EMPTY_STACK -2

typedef unsigned char uint8_t;
typedef signed char int8_t;





typedef struct stack
{
    uint8_t elements[STACK_SIZE];
    int8_t top;
} ST_stack_t; // Type


/* Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t* stack);


/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t* stack, uint8_t data);



/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t* stack, uint8_t* data);

/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t printStack(ST_stack_t* stack);


/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData);

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t* stack);


/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t* stack);


/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
uint8_t matching_paranthethesis(uint8_t close, uint8_t open);
char isBalancedParanthethes(char* expression);

ST_stack_t stack;
ST_stack_t* ptr_stack = &stack;
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




void createEmptyStack(ST_stack_t* stack)
{

    for (uint8_t i = 0; i <= STACK_SIZE - 1; i++)
    {
        stack->elements[i] = '0';
    }
    stack->top = -1;
}


int8_t push(ST_stack_t* stack, uint8_t data)
{
    int8_t return_value = FULL_STACK;
    if (isFull(stack) == 0)
    {
        (stack->top)++;
        stack->elements[stack->top] = data;
        return_value = 0;
    }

    return return_value;
}

int8_t pop(ST_stack_t* stack, uint8_t* data)
{
    int8_t return_value = EMPTY_STACK;
    if (isEmpty(stack) == 0)
    {

        *data = stack->elements[stack->top];
        stack->elements[stack->top] = '0';
        (stack->top)--;
        return_value = 0;
    }
    return return_value;

}

int8_t printStack(ST_stack_t* stack)
{
    int8_t return_value = 0;
    if (isFull(stack) == FULL_STACK)
    {
        return_value = FULL_STACK;
        printf("Error in push ");

    }
    else if (isEmpty(stack) == EMPTY_STACK)
    {
        return_value = EMPTY_STACK;
        printf("Error in pop ");

    }

    else
    {
        for (int8_t i = STACK_SIZE - 1; i >= 0; i--)
        {
            printf("%c ", stack->elements[i]);

        }
        return_value = 0;

    }
    return return_value;
}



int8_t getStackTop(ST_stack_t* stack, uint8_t* topData)
{
    int8_t return_value = EMPTY_STACK;

    if (isEmpty(stack) != EMPTY_STACK)
    {
        *topData = stack->elements[stack->top];
        return_value = 0;
    }
    else
    {
        *topData = ' ';
    }
    return return_value;
}


int8_t isFull(ST_stack_t* stack)
{
    int8_t return_value = 0;

    if (stack->top == STACK_SIZE - 1)
    {

        return_value = FULL_STACK;
    }
    return return_value;
}


int8_t isEmpty(ST_stack_t* stack)
{

    int8_t return_value = 0;

    if (stack->top == -1)
    {

        return_value = EMPTY_STACK;
    }
    return return_value;
}

uint8_t matching_paranthethesis(uint8_t close, uint8_t open) {
    if (close == ')' && open == '(') return 1;
    else if (close == '}' && open == '{')  return 1;
    else  return 0;
}


char isBalancedParanthethes(char* exp) {
    uint8_t length = strlen(exp);
    uint8_t counter = 0;
    createEmptyStack(ptr_stack);

    for (uint8_t c = 0; c < length; c++) {
        if (exp[c] != '(' && exp[c] != '{' && exp[c] != ')' && exp[c] != '}') {
            counter++;
        }
    }
    if (counter == length) return -2;
    for (uint8_t c = 0; c < length; c++) {
        if (exp[c] == '(' || exp[c] == '{') {
            push(ptr_stack, exp[c]);
        }
        else if (exp[c] == ')' || exp[c] == '}') {
            if (ptr_stack->top == -1) return -1;
            else {
                pop(ptr_stack, ptr_data);
                if (!matching_paranthethesis(exp[c], data)) return -1;
            }
        }
    }
    if (ptr_stack->top == -1) return 0;
    else return -1;
}
