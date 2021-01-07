#include <stdio.h>
#include "lista.h"

int main(void)
{
    lista_t l = nuovaLista();
    insTesta(&l, 5);
    insTesta(&l, 2);
    insCoda(&l, 8);
    stampaLista(l);
    putchar('\n');
    return 0;
}
