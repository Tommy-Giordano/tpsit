#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIM 50

typedef struct
{
    char nome[DIM];
    float prezzo;
    int quantita;
}Prodotto;

void menu();

void popolaProdotti(Prodotto *Prodotti, int dim);

int aggiungiProdotto(Prodotto *Prodotti, int dim);

void stampaProdotti(Prodotto *Prodotti, int dim);

void stampaProdotto(Prodotto *Prodotti, int dim);

void modificaProdotto(Prodotto *Prodotti, int dim);

void ordinaProdotti(Prodotto *Prodotti, int dim);

void popolaProdotto(Prodotto *Prodotto);

void scelta(Prodotto *Prodotti, int dim);

int main()
{
    int dim;

    printf("quanti prodotti vuoi aggiungere: ");
    scanf("%d", &dim);

    Prodotto *Prodotti = (Prodotto *)malloc(dim * sizeof(Prodotto));

    popolaProdotti(Prodotti, dim);

    scelta(Prodotti, dim);

    free(Prodotti);
}

void menu()
{
    printf("0-Esci\n1-Aggiungi prodotto\n2-Visualizza inventario\n3-Cerca prodotto\n4-Modifica prodotto\n5-Ordina inventario\n");
}

void scelta(Prodotto *Prodotti, int dim)
{
    int  scelta = 1;

    while (scelta != 0)
    {
        menu();
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
            dim = aggiungiProdotto(Prodotti, dim);
            break;

        case 2:
            stampaProdotti(Prodotti, dim);
            break;
        
        case 3:
            stampaProdotto(Prodotti, dim);
            break;

        case 4:
            modificaProdotto(Prodotti, dim);
            break;

        case 5:
            ordinaProdotti(Prodotti, dim);
            break;
        
        default:
            break;
        }
    }
}

void popolaProdotto(Prodotto *Prodotto)
{
    printf("inserisci il nome del prodotto: ");
    scanf("%s", Prodotto->nome);

    printf("inserisci il prezzo del prodotto: ");
    scanf("%f", &Prodotto->prezzo);

    printf("inserisci la quantita' del prodotto: ");
    scanf("%d", &Prodotto->quantita);
}

void popolaProdotti(Prodotto *Prodotti, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        popolaProdotto(&Prodotti[i]);
    }
}

int aggiungiProdotto(Prodotto *Prodotti, int dim)
{
    int temp;

    printf("quanti prodotti vuoi aggiungere: ");
    scanf("%d", &temp);

    temp = temp + dim;

    Prodotti = (Prodotto *)realloc(Prodotti, temp);

    for (int i = dim; i < temp; i++)
    {
        popolaProdotto(&Prodotti[i]);
    }

    return temp;
}

void stampaProdotti(Prodotto *Prodotti, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("il prodotto %s costa %.2f e ce ne sono %d\n", Prodotti[i].nome, Prodotti[i].prezzo, Prodotti[i].quantita);
    }
}

void modificaProdotto(Prodotto *Prodotti, int dim)
{
    char nome[DIM];

    printf("Inserisci il nome per cercare il prodotto e modificarne le proprieta': ");
    scanf("%s", nome);

    for (int i = 0; i < dim; i++)
    {
        if (strcmp(Prodotti[i].nome, nome) == 0)
        {
            printf("inserisci il prezzo del prodotto: ");
            scanf("%f", &Prodotti[i].prezzo);

            printf("inserisci la quantita' del prodotto: ");
            scanf("%d", &Prodotti[i].quantita);
        }
    }
}

void stampaProdotto(Prodotto *Prodotti, int dim)
{
    char nome[DIM];

    printf("Inserisci il nome per cercare il prodotto: ");
    scanf("%s", nome);

    for (int i = 0; i < dim; i++)
    {
        if (strcmp(Prodotti[i].nome, nome) == 0)
        {
            printf("il prodotto %s costa %.2f e ce ne sono %d\n", Prodotti[i].nome, Prodotti[i].prezzo, Prodotti[i].quantita);
        }
    }
}

void ordinaProdotti(Prodotto *Prodotti, int dim)
{
    int sup = dim - 1;
    Prodotto temp;
    bool scambio = true;

    while (sup > 0 && scambio == true)
    {
        scambio = false;
        for (int i = 0; i < sup; i++)
        {
            if (Prodotti[i].prezzo > Prodotti[i+1].prezzo)
            {
                temp = Prodotti[i];
                Prodotti[i] = Prodotti[i + 1];
                Prodotti[i + 1] = temp;
                scambio = true;
            }
        }
        sup--;
    } 
}