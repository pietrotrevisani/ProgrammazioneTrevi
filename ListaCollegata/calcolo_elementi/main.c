#include <stdio.h>
#include "lista.h"

int main(void)
{
    lista_t l;
    int *v;
    listaNonOrdinata(&l, 6);
    azzera(l);
    v = listToArray(l);
    for (int i = 0; i < 6; i++)
    {
        printf("%d", v[i]);
    }
    return 0;
}