#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main()
{
    // Creo il nodo di TESTA
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 10;   // Gli assegno 10 come data
    head->next = NULL; // Gli assegno NULL al puntatore del prox nodo

    // Creo il nodo SECONDO
    Node *second = (Node *)malloc(sizeof(Node));
    second->data = 20;   // Gli assegno 20 come data
    second->next = NULL; // Gli assegno NULL al puntatore del prox nodo

    // Faccio puntare il nodo TESTA all'indirizzo del nodo SECONDO
    head->next = second;

    // Creo il nodo TERZO
    Node *third = (Node *)malloc(sizeof(Node));
    third->data = 30;   // Gli assegno 30 come data
    third->next = NULL; // Gli assegno NULL al puntatore del prox nodo

    // Faccio puntare il nodo SECONDO all'indirizzo del nodo TERZO
    second->next = third;

    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    free(head);
    free(second);
    free(third);
}