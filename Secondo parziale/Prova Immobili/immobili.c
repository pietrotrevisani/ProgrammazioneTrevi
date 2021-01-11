#include <stdlib.h>
#include <stdio.h>
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
    while (*pl)
    {
        pl = ricerca(pl, d);
    }
    insTesta(pl, d);
}

lista_t *ricerca(lista_t *pl, dato_t d)
{
    while (*pl)
    {
        if ((*pl)->dato.distanza_centro > d.distanza_centro)
            break;
        pl = &(*pl)->next;
    }
    return pl;
}

void stampaDato(dato_t d)
{
    printf("%s %d %f\n", d.indirizzo, d.vani, d.distanza_centro);
}

void stampaLista(lista_t l)
{
    while (l)
    {
        stampaDato(l->dato);
    }
}
