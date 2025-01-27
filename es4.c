#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dim, temp;

    printf("quanti elementi vuoi: ");
    scanf("%d",&dim);

    int *arr = (int *)calloc(dim, sizeof(int));

    for (int i = 0; i < dim; i++)
    {
        arr[i] = i;
        printf("%d-",arr[i]);
    }
    
    printf("\nquanti elementi vuoi aggiungere: ");
    scanf("%d", &temp);

    if (temp > 0)
    {
        dim = dim + temp;
        arr = (int *)realloc(arr, dim);

        for (int i = 0; i < dim; i++)
        {
            arr[i] = i;
        }
    }

    for (int i = 0; i < dim; i++)
    {
        printf("%d-",arr[i]);
    }

    free(arr);
}