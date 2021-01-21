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

lista_t ricercaVani(lista_t l, int a)
{
    lista_t temp;

    nuovaLista(&temp);

    while (l)
    {
        if (l->dato.vani >= a)
        {
            insOrdVani(&temp, l->dato);
        }
        l = l->next;
    }

    return temp;
}

int precede(dato_t d1, dato_t d2)
{
    return d1.vani > d2.vani ||
           d1.vani == d2.vani &&
               d1.distanza_centro < d2.distanza_centro;
}

void insOrdVani(lista_t *pl, dato_t d)
{
    while (*pl && precede((*pl)->dato, d))
    {
        pl = &(*pl)->next;
    }
    insTesta(pl, d);
}

void stampaVani(lista_t l, FILE *fp)
{
    while (l)
    {
        fprintf(fp, "%s %d %.3f\n", l->dato.indirizzo, l->dato.vani,
                l->dato.distanza_centro);
        l = l->next;
    }
}
