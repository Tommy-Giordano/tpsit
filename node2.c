#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 10;   
    head->next = NULL; 

    Node *old = head;

    for (int i = 0; i < 5; i++)
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->data = i;
        old->next = new;
        new->next = NULL;
        old = new;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
        free(temp);
    }

    free(head);
}