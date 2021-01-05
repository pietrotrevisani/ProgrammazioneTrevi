#include <stdio.h>
#include "lista.h"

int main(void)
{
    lista_t l;
    int n;
    nuovaLista(&l);
    puts("Inserisci numeri:");
    do
    {

        scanf("%d", &n);
        inserisciOrdinato(&l, n);
    } while (n > 0);

    stampaLista(l);
    putchar('\n');

    return 0;
}