#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node 
{
    int data;
    struct Node *previous;
    struct Node *next;
} Node;

Node* createList();
void initializeList(Node **head, int n, int range);
void appendNode(Node **head, int data);
void printList(Node *head);
void printListCoda(Node *tail);
void freeList(Node *head);
void ordinaLista(Node **head);

int main()
{
    srand(time(0));

    int n = 5;
    int range = 100;


    Node *head = createList();
    initializeList(&head, n, range);

    printf("Lista iniziale:\n");
    printList(head);
    
    ordinaLista(&head);
    printf("Lista ordinata:\n");
    printList(head);


    appendNode(&head, 4);
    printf("Lista dopo append:\n");
    printList(head);

    Node *current = head;
    while (current != NULL)
    {
        current = current->next;
    }

    printListCoda(current);
    freeList(head);

    return 0;
}

Node* createList() 
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = 0;
    temp->next = NULL;
    temp->previous = NULL;

    return temp;
}

void initializeList(Node **head, int n, int range) 
{
    Node *current = NULL;

    for (int i = 0; i < n; i++) 
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = rand() % range;
        newNode->next = NULL;

        if (*head == NULL) 
        {
            *head = newNode;
        } 
        else 
        {
            current->next = newNode;
        }
        current = newNode;
    }
}

void appendNode(Node **head, int data)
{
    Node *new = createList();

    if (*head == NULL)
    {
        *head = new;
        return;
    }
    
    Node *temp = *head;
    Node *old;
    while (temp->next != NULL)
    {
        old = temp;
        temp = temp->next;
    }
    
    temp->previous = old;
    temp->next = new;
}

void printList(Node *head) 
{
    Node *current = head;

    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void printListCoda(Node *tail)
{
    Node *current = tail;

    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->previous;
    }
}

void freeList(Node *head) 
{
    Node *temp;

    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void ordinaLista(Node **head) 
{
    if (*head == NULL) 
        return;

    bool swap = true;
    Node *current;
    Node *last = NULL;

    while (swap) 
    {
        swap = false;
        current = *head;

        while (current->next != last) 
        {
            if (current->data > current->next->data) 
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swap = true;
            }
            current = current->next;
        }
        last = current;
    }
}
