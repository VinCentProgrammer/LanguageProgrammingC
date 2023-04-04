#include <stdio.h>
#include <stdlib.h>

node* createNode(int d){
    struct Node *p = (node *)malloc(sizeof(node));
    p->data = d;
    p->next = NULL;
    return p;
}

void addHead(list *l, node *p){
    if(l -> head == NULL){
        l -> head = p;
    }
    else{
        l -> head -> next = p;
    }
}
// Danh sach lien ket don
typedef struct Node
{
    int data;
    struct node *next;
} node;

// // Danh sach lien ket doi
// typedef struct Node
// {
//     int data;
//     node *next;
//     node *previous;

// } node;

typedef struct List
{
    node *head;
    node *tail;
    int n; // so luong phan tu cua list
} list;

int main()
{
    node *p = createNode(5);
    node *q = createNode(10);
    // them p node dau
    list *l = ;
    l.head = p;
    l.tail = p;
    l.n = 1;
    // them q
    l.head->next = q;
    l.tail = q;
    l.n = l.n + 1;

    for (node *i = l.head; i != NULL; i = i->next)
    {
        printf("%d  ", i->data);
    }
    return 0;
}