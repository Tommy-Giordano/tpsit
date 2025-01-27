/*calloc = malloc ma assegna tutti i valori dell'array a zero*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = (int *)calloc(100, sizeof(int));

    if (array == NULL)
    {
        return 1;
    }

    for (int i = 0; i < 100; i++)
    {
        __mingw_printf("%d\n", array[i]);
    }

    free(array);

    return 0;
}