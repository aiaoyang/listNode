//链栈
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottm;
} STACK, *PSTACK;

void initStack(PSTACK pS);
void pushStack(PSTACK pS, int val);
void traverseStack(PSTACK pS);
bool popStack(PSTACK pS, int *pVal);
bool empty(PSTACK pS);
void clearStack(PSTACK pS);

int main(void)
{
    STACK s;
    printf("%p\n", s);
    int val;
    initStack(&s); //目的是造出一个空栈
    pushStack(&s, 1);
    pushStack(&s, 2);
    pushStack(&s, 3);
    pushStack(&s, 4);
    pushStack(&s, 5);
    traverseStack(&s);

    if (popStack(&s, &val))
    {
        printf("出栈成功，出栈的元素是%d\n", val);
    }
    else
    {
        printf("出栈失败\n");
    }
    traverseStack(&s);
    clearStack(&s);
    traverseStack(&s);
    if (popStack(&s, &val))
    {
        printf("出栈成功，出栈的元素是%d\n", val);
    }
    else
    {
        printf("出栈失败\n");
    }

    return 0;
}
void initStack(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (pS->pTop == NULL)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    else
    {
        pS->pBottm = pS->pTop; //pS->pBottm->pNext=pS->pTop->pNext ?
        pS->pTop->pNext = NULL;
    }
}
void pushStack(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop; //因为刚开始pTop和pBottom指向的都是同一个节点，所以pS->pTop=pS->pBottom
    pS->pTop = pNew;

    return;
}
void traverseStack(PSTACK pS)
{
    PNODE p = pS->pTop;
    while (p != pS->pBottm)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}
bool empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottm)
        return true;
    else
        return false;
}
//把pS指向的栈出栈一次，并将出栈的元素存入pVal形参所指向的变量中，如果出栈失败，返回false，否则返回true
bool popStack(PSTACK pS, int *pVal)
{
    if (empty(pS)) //pS本身存放的就是s的地址
    {
        return false;
    }
    else
    {
        PNODE r = pS->pTop; //目的是为了释放那一块内存
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;

        return true;
    }
}
//清空
void clearStack(PSTACK pS)
{
    if (empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        while (p != pS->pBottm)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottm;
    }
}