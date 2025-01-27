#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

int main() 
{
    int n = 5;
    Node *head = NULL; 
    Node *current = NULL;
    bool scandolah = false;

    for (int i = 0; i < n; i++) 
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->data = rand() % 100; 
        new->next = NULL; 

        if (head == NULL) 
        {
            head = new;
        } else 
        {
            current->next = new;
        }
        
        current = new;
    }

    Node *temp1;
    current = head;

    while (scandolah == false)
    {
        temp1 = current;
        if (temp1 = NULL)
        {
            temp1->data = 104;
            scandolah = true;
        }
        
    }
    

    current = head;
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Libera la memoria
    current = head;
    Node *temp;
    while (current != NULL) 
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}