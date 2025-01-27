#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data);
Node *search(Node *head, int data);
void append(Node **head, int data);
void prepend(Node **head, int data);
void deleteNode(Node **head, int data);
void sortList(Node **head);
void printList(Node *head);

int main()
{
    Node *head = NULL;

    append(&head, 10);
    append(&head, 20);
    prepend(&head, 5);
    printList(head);

    Node *found = search(head, 20);
    if (found)
    {
        printf("Nodo con valore %d trovato.\n", found->data);
    }
    else
    {
        printf("Nodo non trovato.\n");
    }

    deleteNode(&head, 10);
    printList(head);

    append(&head, 15);
    append(&head, 25);
    sortList(&head);
    printList(head);

    return 0;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void prepend(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

Node *search(Node *head, int data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteNode(Node **head, int data)
{
    Node *temp = *head;

    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Nodo con valore %d non trovato.\n", data);
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Nodo con valore %d cancellato.\n", data);
}

void sortList(Node **head)
{
    if (*head == NULL)
        return;

    Node *current;
    Node *index;
    int temp;

    for (current = *head; current->next != NULL; current = current->next)
    {
        for (index = current->next; index != NULL; index = index->next)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

void printList(Node *head)
{
    Node *temp = head;
    printf("Lista: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}