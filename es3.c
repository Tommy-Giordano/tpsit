#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int matricola;
    int *voti;
    int nVoti;
}Studente;

Studente *creaTabella(int *index);

int popolaTabella(Studente *Studenti, int index);

void popolaVoti(Studente *Studenti, int index, int nVoti);

void stampaTabella(Studente *Studenti, int index, int nVoti);

int main()
{
    int index = 0;

    Studente *Studenti = creaTabella(&index);

    int nVoti = popolaTabella(Studenti, index);
    popolaVoti(Studenti, index, nVoti);

    stampaTabella(Studenti, index, nVoti);

    for (int i = 0; i < index; i++)
    {
        free(Studenti[i].voti);
    }
    
    free(Studenti);

    return 0;
}

Studente *creaTabella(int *index)
{
    printf("quanti studenti vuoi inserire: ");
    scanf("%d", index);

    Studente *Studenti = (Studente *)malloc(*index * sizeof(Studente));

    return Studenti;
}

int popolaTabella(Studente *Studenti, int index)
{
    int nVoti;

    printf("quanti voti hanno gli studenti: ");
    scanf("%d", &nVoti);

    for (int i = 0; i < index; i++)
    {
        Studenti[i].nVoti = nVoti;

        printf("inserire la matricola del %d studente: ", i+1);
        scanf("%d", &Studenti[i].matricola);
    }

    return nVoti;
}

void popolaVoti(Studente *Studenti, int index, int nVoti)
{
    for (int i = 0; i < index; i++)
    {
        Studenti[i].voti = (int *)malloc(nVoti * sizeof(Studenti[i].voti));

        for (int j = 0; j < nVoti; j++)
        {
            printf("inserisci il %d voto dell'alunno %d: ", j+1, Studenti[i].matricola);
            scanf("%d", &Studenti[i].voti[j]);
        }
    }
}

void stampaTabella(Studente *Studenti, int index, int nVoti)
{
    for (int i = 0; i < index; i++)
    {
        printf("\nlo studente %d ha come voti: ", Studenti[i].matricola);

        for (int j = 0; j < nVoti; j++)
        {
            printf("%d ", Studenti[i].voti[j]);
        }
    }
}