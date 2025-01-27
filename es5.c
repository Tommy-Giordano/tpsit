#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next; 
}Node;

void addTop(Node **head, int data);

int main()
{
    
}

void addTop(Node **head, int data) 
{
    Node *newHead = (Node *)malloc(sizeof(Node));
    newHead->data = data;
    newHead->next = *head;
    *head = newHead;
}