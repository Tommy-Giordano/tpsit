#include <stdio.h>
#include <stdlib.h>

int *creaArray(int dimArray);

int *popolaArray(int dimArray, int array[]);

int *aumentaDispari(int dimArray, int array[]);

void stampaArray(int dimArray, int array[]);

int main()
{
    int dimArray;

    printf("crea un array di dim variabile, inserisci la dimensione: ");
    scanf("%d", &dimArray);

    int *arr = creaArray(dimArray);
    arr = popolaArray(dimArray, arr);
    stampaArray(dimArray, arr);
    arr = aumentaDispari(dimArray, arr);
    stampaArray(dimArray, arr);
    
}   


int *creaArray(int dimArray)
{
    int *array = (int *) malloc( sizeof(int) * dimArray);
    
    return array;
}

int *popolaArray(int dimArray, int array[])
{
    for (int i = 0; i < dimArray; i++)
    {
        array[i] = i;
    }
    
    return array;
}

int *aumentaDispari(int dimArray, int array[])
{
    for (int i = 0; i < dimArray; i++)
    {
        if (array[i] % 2 != 0)
        {
            array[i]++;
        }
    }
    
    return array;
}

void stampaArray(int dimArray, int array[])
{
    for (int i = 0; i < dimArray; i++)
    {
        printf("%d-", array[i]);
    }
    printf("\n");
}