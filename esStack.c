#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo
{
    char parentesi;
    struct Nodo *next;
}Nodo;

Nodo *creaNodo(char data);

bool pilaVuota(Nodo *cima);

void push(Nodo **cima, char dato);

int pop(Nodo **cima);

char peek(Nodo *cima);

void stampaPila(Nodo *cima);

int main()
{
    FILE *f = fopen("codice.txt", "r");
    Nodo *cima;
    char c;

    while ((c = fgetc(f)) != EOF)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            push(&cima, c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            pop(&cima);
        }
    }
    
    
    if (pilaVuota(cima))
    {
        printf("nessun errore");
    }
    else
    {
        printf("hai sbagliato delle parentesi!");
    }
    
    fclose(f);
    return 0;
}

//crea nodo
Nodo *creaNodo(char data)
{
    Nodo *newNode = (Nodo *)malloc(sizeof(Nodo));
    if (!newNode)
    {
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
    newNode->parentesi = data;
    newNode->next = NULL;
    return newNode;
}

// Funzioni per stack:
//  Funzione per controllare se la pila è vuota
bool pilaVuota(Nodo *cima)
{
    return cima == NULL;
}

// Funzione per aggiungere un elemento alla pila (push)
void push(Nodo **cima, char dato)
{
    Nodo *nuovoNodo = creaNodo(dato);
    nuovoNodo->next = *cima;
    *cima = nuovoNodo;
}

// Funzione per rimuovere un elemento dalla pila (pop)
int pop(Nodo **cima)
{
    if (pilaVuota(*cima))
    {
        printf("Errore: la pila è vuota\n");
        exit(1);
    }
    Nodo *temp = *cima;
    int dato = temp->parentesi;
    *cima = (*cima)->next;
    free(temp);
    return dato;
}

// Funzione per visualizzare la cima della pila
char peek(Nodo *cima)
{
    if (pilaVuota(cima))
    {
        printf("Errore: la pila è vuota\n");
        exit(1);
    }
    return cima->parentesi;
}

// Funzione per stampare tutti gli elementi della pila
void stampaPila(Nodo *cima)
{
    Nodo *corrente = cima;
    printf("Pila: ");
    while (corrente != NULL)
    {
        printf("%c ", corrente->parentesi);
        corrente = corrente->next;
    }
    printf("\n");
}