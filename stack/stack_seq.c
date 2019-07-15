#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#define INIT_STACK_SIZE 5
#define STACK_EXTEND_SIZE 5
// typedef struct elemType
// {
//     int data;
//     char name;
// } elemType;
typedef int elemType;
typedef struct stack
{
    elemType *top;
    elemType *base;
    int stackSize;
} Stack, *pStack;
// pStack initStack(pStack pS);
bool initStack(Stack *S);

// elemType get_base_elem(Stack *S);
elemType get_top_elem(Stack *S);
// bool pop(Stack **S, elemType *e);
bool pop(Stack *S, elemType **e);

// bool push(Stack **S, elemType data);
bool push(Stack *S, elemType data);
bool visit(Stack *S);

int main()
{

    Stack S1;
    elemType tmp;
    tmp = malloc(sizeof(elemType));
    initStack(&S1);
    for (elemType i = 1; i < 100; i++)
    {
        push(&S1, i);
        printf("stack size is:%d\n", S1.stackSize);
    }
    for (int i = 1; i < 100; i++)
    {
        pop(&S1, &tmp);
        printf("tmp is :%d\n", tmp);
    }
}
bool visit(Stack *S)
{
    return true;
}
bool initStack(Stack *S)
{
    (*S).base = (elemType *)malloc(INIT_STACK_SIZE * sizeof(Stack));
    (*S).stackSize = INIT_STACK_SIZE;
    if (!(*S).base)
    {
        return false;
        exit(1);
    }
    (*S).top = (*S).base;
    return true;
}

elemType get_top_elem(Stack *S)
{
    if ((*S).top == (*S).base)
    {
        return 0;
    }
    return *((*S).top - 1);
}
bool pop(Stack *S, elemType **e)
{
    if ((*S).top == (*S).base)
    {
        return false;
    }
    *e = *((*S).top - 1);
    (*S).top--;
    // printf("func tmp is :%d\n", *e);
    return true;
}
bool push(Stack *S, elemType data)
{
    if ((*S).top - (*S).base >= (*S).stackSize)
    {
        // printf("pre base ptr is:%p\n", (*S).base);
        (*S).base = (elemType *)realloc((*S).base, ((*S).stackSize + STACK_EXTEND_SIZE) * sizeof(elemType));
        // printf("after base ptr is:%p\n", (*S).base);
        (*S).top = (*S).base + (*S).stackSize;
        (*S).stackSize += STACK_EXTEND_SIZE;
    }
    if (!(*S).base)
    {
        return false;
        exit(1);
    }
    *(*S).top++ = data;
    return true;
}