#include "my_stack.h"
#include <stdio.h>
#include <stdlib.h>

/**since makeNullStack() modifies data in stack, need pointer**/
void makeNullStack(STACK* S)
{
    S->top = -1;
}

/**since empty() only read data from stack, only need value**/
int  Empty(STACK S)
{
    if(S.top == -1)
        return 1;
    else
        return 0;
}

/**since push() modifies data in stack, need pointer**/
void push(ElemType x, STACK* S)
{
    if(S->top == MAX-1)
    {
        printf("Error in push: try to push an element into a full stack\n");
        return;
    }
    else
    {
        (S->top)++;
        S->element[S->top] = x;
    }
}

/**since top() only read data from stack, only need value**/
ElemType  top(STACK S)
{
    return S.element[S.top];
}

/**since pop() modifies data in stack, need pointer**/
void pop(STACK *S)
{
      if(S->top == -1)
    {
        printf("Error in pop: try to pop an empty stack\n");
        return;
    }
    else
    {
        (S->top)--;
    }
}
