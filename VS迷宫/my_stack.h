#ifndef MY_STACK_H_INCLUDED
#define MY_STACK_H_INCLUDED

#define MAX 100
typedef struct posision
{
    int x;
    int y;
}Posision;
typedef Posision ElemType;
typedef struct MyStack
{
  ElemType element[MAX];
  int top;
}STACK;

void makeNullStack(STACK *S);
int  Empty(STACK S);
void push(ElemType x, STACK *S);
ElemType  top(STACK S);
void pop(STACK *S);
#endif // MY_STACK_H_INCLUDED
