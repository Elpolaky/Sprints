#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10
#define FULL_STACK -1
#define EMPTY_STACK -2

typedef unsigned char uint8_t;
typedef signed char int8_t;





typedef struct _stack
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
void createEmptyStack(ST_stack_t* _stack);


/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t* _stack, uint8_t data);



/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t* _stack, uint8_t* data);

/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t printStack(ST_stack_t* _stack);


/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t* _stack, uint8_t* topData);

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t* _stack);


/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t* _stack);


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

extern ST_stack_t _stack;
extern ST_stack_t* ptr_stack ;
extern uint8_t data, i;
extern char expression, state;
extern char* ptr_expression ;
extern uint8_t* ptr_dat ;
extern uint8_t topData;
extern uint8_t* ptr_topData ;
