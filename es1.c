#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100//macro più leggero di una variabile perchè sostituisce il nome con il suo valore assegnato dal define

typedef struct
{
    char nome[DIM];
    char cognome[DIM];
    int eta;
    char mail[DIM];
}Persona;

int popolaTabella(Persona Persone[]);

void stampaTabella(Persona Persone[], int dim);

int main()
{
    Persona Persone[DIM];

    int dim = popolaTabella(Persone);
    stampaTabella(Persone, dim);
    
    return 0;
}

int popolaTabella(Persona Persone[])
{
    FILE *f = fopen("file.csv", "r");
    char buffer[DIM];
    int i = 0;

    if (f == NULL)
    {
        perror("file inesistente");
        return -1;
    }

    while (fgets(buffer, DIM, f))
    {
        char *token = strtok(buffer, ",");
        strcpy(Persone[i].nome, token);

        token = strtok(NULL, ",");
        strcpy(Persone[i].cognome, token);

        token = strtok(NULL, ",");
        Persone[i].eta = atoi(token);

        token = strtok(NULL, ",");
        strcpy(Persone[i].mail, token);

        i++;
    }
    fclose(f);
    return i;
}

void stampaTabella(Persona Persone[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("nome: %s\n", Persone[i].nome);
        printf("cognome: %s\n", Persone[i].cognome);
        printf("eta: %d\n", Persone[i].eta);
        printf("mail: %s\n", Persone[i].mail);
    }
}