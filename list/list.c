#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};
void initList(struct node **list);
void add_to_front(struct node **list, int data);
void add_to_tail(struct node **list, int data);
void delete (struct node **list, int position);
void printList(struct node *list);
void reverse(struct node **list);
int getLen(struct node *list);
void mergeList(struct node *list1, struct node *list2);
int main()
{
    struct node *l1, *l2;
    initList(&l1);
    initList(&l2);
    for (int i = 1; i < 5; i++)
    {
        add_to_tail(&l1, i);
        // add_to_tail(&l2, i * 3);
        // add_to_tail(&l1, i);
    }
    delete (&l1, 5);
    // mergeList(l1, l2);
    printList(l1);
    // printf("l2 is :");
    // printList(l2);
}

void initList(struct node **list)
{
    *list = NULL;
}
void add_to_front(struct node **list, int data)
{
    struct node *tmpNode;
    tmpNode = malloc(sizeof(struct node));
    tmpNode->data = data;
    tmpNode->next = *list;
    *list = tmpNode;
}
void add_to_tail(struct node **list, int data)
{
    struct node *tmpNode;
    struct node *cur;
    tmpNode = malloc(sizeof(struct node));
    tmpNode->data = data;
    if (!*list)
    {
        *list = tmpNode;
        return;
    }
    cur = *list;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = tmpNode;
    return;
}
void delete (struct node **list, int position)
{
    struct node *cur, *tmp;
    int n = 1;
    cur = (*list);
    if (position <= 0)
    {
        printf("position less than 0\n");
        return;
    }
    if (position == 1)
    {
        *list = cur->next;
        return;
    }
    // move cur to position's pre node;
    while (n < position - 1)
    {
        cur = cur->next;
        n++;
    }
    if (!cur->next)
    {
        printf("position is longer than list's length\n");
        return;
    }
    tmp = cur->next;
    cur->next = cur->next->next;
    free(tmp);
}
void printList(struct node *list)
{
    int len = 0;
    struct node *cur;
    cur = list;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
        len++;
    }
    printf("\n");
    printf("len:%d\n", len);
}
void mergeList(struct node *list1, struct node *list2)
{

    struct node *l3, *p1, *p2, *p3;
    l3 = malloc(sizeof(struct node));
    p1 = list1;
    p2 = list2;
    p3 = l3;
    if (!list1 && list2)
    {
        printf("list1 is nil\n");
        l3 = p2;
        return;
    }
    if (!list2 && list1)
    {
        printf("list2 is nil\n");

        l3 = p1;
        return;
    }

    while (p1 && p2)
    {
        if (p3->data == NULL)
        {
            if (p1->data <= p2->data)
            {
                p3->data = p1->data;
                p1 = p1->next;
            }
            else
            {
                p3->data = p2->data;
                p2 = p2->next;
            }
            continue;
        }
        if (p1->data <= p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    // if (!l3->data)
    // {
    //     printf("one of param is nil\n");
    //     l3 = p1 ? p1 : p2;
    //     printList(l3);
    //     return;
    // }
    if (p1 || p2)
    {
        p3->next = p1 ? p1 : p2;
    }
    printList(l3);
    return;
}
void reverse(struct node **list)
{
    struct node *p, *q, *ptr;
    p = (*list)->next;
    q = (*list);
    ptr = (*list);
    while (p)
    {
        ptr = p->next;
        p->next = q;
        q = p;
        p = ptr;
    }
    (*list)->next = NULL;
    *list = q;
    return;
}