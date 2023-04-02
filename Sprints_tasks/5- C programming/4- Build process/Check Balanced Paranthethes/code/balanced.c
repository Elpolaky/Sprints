#include"balanced.h"


ST_stack_t _stack;
ST_stack_t* ptr_stack = &_stack;
uint8_t* ptr_data ;
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

uint8_t matching_paranthethesis(uint8_t close, uint8_t open)
{
    if (close == ')' && open == '(') return 1;
    else if (close == '}' && open == '{')  return 1;
    else  return 0;
}


char isBalancedParanthethes(char* exp)
{
    uint8_t length = strlen(exp);
    uint8_t counter = 0;
    createEmptyStack(ptr_stack);

    for (uint8_t c = 0; c < length; c++)
    {
        if (exp[c] != '(' && exp[c] != '{' && exp[c] != ')' && exp[c] != '}')
        {
            counter++;
        }
    }
    if (counter == length) return -2;
    for (uint8_t c = 0; c < length; c++)
    {
        if (exp[c] == '(' || exp[c] == '{')
        {
            push(ptr_stack, exp[c]);
        }
        else if (exp[c] == ')' || exp[c] == '}')
        {
            if (ptr_stack->top == -1) return -1;
            else
            {
                pop(ptr_stack, ptr_data);
                if (!matching_paranthethesis(exp[c], data)) return -1;
            }
        }
    }
    if (ptr_stack->top == -1) return 0;
    else return -1;
}
