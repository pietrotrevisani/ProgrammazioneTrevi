#include <stdio.h>
#include <stdlib.h>
#include "listaImmobili.h"

void nuovaLista(lista_t *pl)
{
    *pl = NULL;
}

void insTesta(lista_t *pl, dato_t d)
{
    nodo_t *aux = (nodo_t *)malloc(sizeof(nodo_t));
    if (!aux)
    {
        puts("Errore allocazione memoria.");
        exit(1);
    }

    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
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

void insOrdinato(lista_t *pl, dato_t d)
{
    pl = ricerca(pl, d);
    insTesta(pl, d);
}

void stampa(lista_t l)
{
    while (l)
    {
        printf("%s %d %.3f\n", l->dato.indirizzo, l->dato.vani, l->dato.distanza_centro);
        l = l->next;
    }
}