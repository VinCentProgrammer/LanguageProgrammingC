#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList *node;

node CreateNode(int value)
{
    node tmp;
    tmp = (node)malloc(sizeof(struct LinkedList));
    tmp->next = NULL;
    tmp->data = value;
    return tmp;
}

node AddHead(node head, int value)
{
    node tmp = CreateNode(value);
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }
    return head;
}

node AddTail(node head, int value)
{
    node tmp, p;
    tmp = CreateNode(value);
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
    return head;
}

node AddAt(node head, int value, int position)
{
    if (position == 0 || head == NULL)
    {
        head = AddHead(head, value);
    }
    else
    {
        int k = 1;
        node p = head;
        while (p != NULL && k != position)
        {
            p = p->next;
            ++k;
        }

        if (k != position)
        {
            head = AddTail(head, value);
        }
        else
        {
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
}

int main()
{
}