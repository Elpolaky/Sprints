#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define FULL_STACK -1
#define EMPTY_STACK -2

typedef unsigned char uint8_t ;
typedef signed char int8_t ;





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
void createEmptyStack(ST_stack_t *stack);


/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t *stack, uint8_t data);



/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t *stack, uint8_t *data);

/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t printStack(ST_stack_t *stack);


/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t *stack);


/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t *stack);


/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t *expression);
ST_stack_t mathExpression ;
ST_stack_t *p_mathExpression = &mathExpression;
int main()
{


    uint8_t data[10];
    int8_t expressionState=0;
    createEmptyStack(p_mathExpression);
    while(1){
    printf("Enter the expression : \n");
    scanf("%s",data);


    expressionState=isBalancedParanthethes(data);


    switch(expressionState)
    {

    case 0:
        printf("\nthe parentheses are balanced\n");
        break;
    case -1:
        printf("\nthe parentheses are not balanced\n");
        break;
    case -2 :
        printf("\nneither of parentheses is used\n");
        break;

    default :
        break;
    }
    }
    return 0;
}


void createEmptyStack(ST_stack_t *stack)
{

    for(uint8_t i=0 ; i<= STACK_SIZE-1 ; i++)
    {
        stack->elements[i] = '0';
    }
    stack->top= -1 ;
}


int8_t push(ST_stack_t *stack, uint8_t data)
{
    int8_t return_value = FULL_STACK ;
    if(isFull(stack)==0)
    {
        (stack->top)++ ;
        stack->elements[stack->top]= data;
        return_value = 0 ;
    }

    return return_value ;
}

int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    int8_t return_value = EMPTY_STACK ;
    if(isEmpty(stack)==0)
    {

        *data =stack->elements[stack->top];
        stack->elements[stack->top] = '0';
        (stack->top)-- ;
        return_value = 0 ;
    }
    return return_value ;

}

int8_t printStack(ST_stack_t *stack)
{
    int8_t return_value = 0 ;
    if(isFull(stack) == FULL_STACK )
    {
        return_value = FULL_STACK;
        printf("Error in push ");

    }
    else if (isEmpty(stack) == EMPTY_STACK)
    {
        return_value= EMPTY_STACK;
        printf("Error in pop ");

    }

    else
    {
        for(int8_t i = STACK_SIZE-1 ; i >=0  ; i--)
        {
            printf("%c ",stack->elements[i]);

        }
        return_value= 0;

    }
    return return_value ;
}



int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    int8_t return_value = EMPTY_STACK ;

    if(isEmpty(stack) !=EMPTY_STACK )
    {
        *topData = stack->elements[stack->top];
        return_value = 0;
    }
    else
    {
        *topData = ' ';
    }
    return return_value ;
}


int8_t isFull(ST_stack_t *stack)
{
    int8_t return_value = 0;

    if(stack->top == STACK_SIZE-1)
    {

        return_value = FULL_STACK ;
    }
    return return_value ;
}


int8_t isEmpty(ST_stack_t *stack)
{

    int8_t return_value = 0;

    if(stack->top == -1)
    {

        return_value = EMPTY_STACK ;
    }
    return return_value ;
}


int8_t isBalancedParanthethes(uint8_t *expression)
{
    uint8_t counter=0,stackCounter=0,top,data1,paranthethes1,paranthethes2;
    int8_t balanceState,paranthethes3;
    while(expression[counter]!= '\0')
    {
        if(expression[counter]=='(' || expression[counter]=='{'|| expression[counter]==')' || expression[counter]=='}')
        {

            if(expression[counter]=='('  )
            {
                push(p_mathExpression,expression[counter]);
                paranthethes1 ++;
            }
            else if(expression[counter]=='{')
            {
                push(p_mathExpression,expression[counter]);
                paranthethes2 ++;
            }



            else  if((expression[counter]==')')&&paranthethes1!=0)
            {
                pop(p_mathExpression,&data1);
                paranthethes1 --;


            }
            else if((expression[counter]=='}')&&paranthethes2!=0)
            {
                pop(p_mathExpression,&data1);
                paranthethes2--;


            }



        }

        else //if(expression[counter]=='['|| expression[counter]==']' || expression[counter]=='<'|| expression[counter]=='>')
        {

            paranthethes3 = -2 ;


        }
        counter++;



    }
    if(getStackTop(p_mathExpression,&top)==EMPTY_STACK && paranthethes3!=-2)
    {
        balanceState = 0;
    }
   /* else if( paranthethes3==-2)
    {
        balanceState=-2 ;
        paranthethes3=0;
    }*/
    else
    {

        balanceState=-1 ;
    }
    return balanceState;

}

