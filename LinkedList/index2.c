#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct list
{
    struct node *head;
    struct node *tail;
    int n = 0;
};

node *createNode(int d)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = d;
    p->next = NULL;
    return p;
};

void addHead(node *p, list *l)
{
    if (l->head == NULL)
    {
        l->head = p;
        l->tail = p;
    }
    else
    {
        p->next = l->head;
        l->head = p;
    }
    l->n++
}

void addEnd(node *p, list *l)
{
    if (l->head == NULL)
        l->head = p;
    else
    {
        list->tail->next = p;
        l->tail = p;
    }
    l->n++
}

int main()
{

    return 0;
}