#include <stdlib.h>
#include "immobili.h"

void init(lista_t *pl)
{
    *pl = NULL;
}

void insTesta(lista_t *pl, dato_t d)
{
    nodo_t *aux = (nodo_t *)malloc(sizeof(nodo_t));

    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void insOrd(lista_t *pl, dato_t d)
{
    while (pl)
    {
        pl = ricerca(pl, d);
        insTesta(pl, d);
    }
}