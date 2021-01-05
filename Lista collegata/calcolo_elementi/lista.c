#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void listaNonOrdinata(lista_t *l, int dim)
{
    *l = malloc(sizeof(int) * dim);
}

void azzera(lista_t l)
{
    while (l)
    {
        l->dato = 0;
        l = l->next;
    }
}

void stampaLista(lista_t l)
{
    while (l)
    {
        printf("%d", l->dato);
        l = l->next;
    }
}

int lunghezza(lista_t l)
{
    int lunghezza = 0;
    while (l)
    {
        lunghezza++;
        l = l->next;
    }
    return lunghezza;
}

int *listToArray(lista_t l)
{
    int *v;
    v = (int *)malloc(sizeof(int) * lunghezza(l));
    int i = 0;
    while (l)
    {
        v[i] = l->dato;
        l = l->next;
    }
    return v;
}