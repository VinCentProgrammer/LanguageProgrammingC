// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// struct node
// {
//     int value;
//     struct node *next;
// };

// void printLinkedList(struct node *p)
// {
//     while (p != NULL)
//     {
//         printf(" %d ", p->value);
//         p = p->next;
//     }
// }
// //============INSERT LINKED LIST================
// // Insert at the Beginning
// struct node *newNode
//     newNode = malloc(sizeof(struct node));
// newNode->value = 5;
// newNode->next = head;
// head = newNode;

// // Insert at the End
// struct node *newNode
//     newNode = malloc(sizeof(struct node));
// newNode->value = 4;
// newNode->next = NULL;

// struct node *temp = head;
// while (temp != NULL)
// {
//     temp = temp->next;
// }
// temp->next = newNode;

// // Insert at the Middle
// struct node *newNode
//     newNode = malloc(sizeof(struct node));
// newNode->value = 4;

// struct node *tmp = head;
// for (int i = 2; i < position; i++)
// {
//     if (tmp->next != NULL)
//     {
//         tmp = tmp->next;
//     }
// }

// newNode->next = tmp->next;
// tmp->next = newNode;

// //===============DELETE LINKED LIST================

// // Delete from beginning
// head = head->next;

// // Delete from end
// struct node *tmp = head;
// while (tmp->next->next != NULL)
// {
//     tmp = tmp->next;
// }
// tmp->next = NULL;

// // Delete from middle
// struct node *tmp = head;
// for (int i = 2; i < postition; i++)
// {
//     if (tmp->next != NULL)
//     {
//         tmp = tmp->next;
//     }
// }
// tmp->next = tmp->next->next;

// // =============SEARCH AN ELEMENT ON A LINKED LIST============

// int searchNode(struct Node **head_ref, int key)
// {
//     struct Node *current = *head_ref;

//     while (current != NULL)
//     {
//         if (current->value == key)
//         {
//             return 1;
//         }
//         current = current->next;
//     }
//     return 0;
// }

// //============SORT ELEMENTS OF A LINKED LIST =================

// // Bubber sort

// void sortLinkedList(struct node **head_ref)
// {
//     struct node *current = *head_ref, *index = NULL;

//     if (head_ref == NULL)
//         return;
//     else
//     {
//         while (current != NULL)
//         {
//             index = current->next;
//             while (index != NULL)
//             {
//                 if (current->data > index->data)
//                 {
//                     int tmp = current->data;
//                     current->data = index->data;
//                     index->data = tmp;
//                 }
//                 index = index->next;
//             }
//             current = current->next;
//         }
//     }
// }

// int main()
// {
//     struct node *head;
//     struct node *one = NULL;
//     struct node *two = NULL;
//     struct node *three = NULL;

//     one = malloc(sizeof(struct node));
//     two = malloc(sizeof(struct node));
//     three = malloc(sizeof(struct node));

//     one->value = 1;
//     two->value = 2;
//     three->value = 3;

//     one->next = two;
//     two->next = three;
//     three->next = NULL;

//     head = one;
//     printLinkedList(head);

//     return 0;
// }



// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node
{
    int data;
    struct Node *next;d
};

// Insert at the beginning
void insertAtBeginning(struct Node **head_ref, int new_data)
{
    // Allocate memory to a node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // insert the data
    new_node->data = new_data;

    new_node->next = (*head_ref);

    // Move head to new node
    (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Insert the the end
void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref; /* used in step 5*/

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Delete a node
void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Find the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL)
        return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
}

// Search a node
int searchNode(struct Node **head_ref, int key)
{
    struct Node *current = *head_ref;

    while (current != NULL)
    {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

// Sort the linked list
void sortLinkedList(struct Node **head_ref)
{
    struct Node *current = *head_ref, *index = NULL;
    int temp;

    if (head_ref == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // index points to the node next to current
            index = current->next;

            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// Print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Driver program
int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAfter(head->next, 5);

    printf("Linked list: ");
    printList(head);

    printf("\nAfter deleting an element: ");
    deleteNode(&head, 3);
    printList(head);

    int item_to_find = 3;
    
    if (searchNode(&head, item_to_find))
    {
        printf("\n%d is found", item_to_find);
    }
}