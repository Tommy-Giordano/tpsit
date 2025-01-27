#include <stdio.h>
#include <stdlib.h>

void *crea(int x);

int main()
{
    int x;
    int *intero;
    char *car;

    scanf("%d", &x);

    if (x == 1)
    {
        intero = (int *)crea(x);
    }
    else if (x == 2)
    {
        car = (char *)crea(x);
    }
}

void *crea(int x)
{
    if (x == 1)
    {
        int intero;
        return scanf("%d", &intero);
    }
    else if (x == 2)
    {
        int car;
        return scanf("%cr", &car);
    }
}