#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listaVeicoli.h"

void nuovaLista(lista_t *pl)
{
    *pl = NULL;
}

void insTesta(lista_t *pl, dato_t d)
{
    nodo_t *aux = (nodo_t *)malloc(sizeof(nodo_t));

    if (!aux)
    {
        puts("Errore allocamento memoria.");
        exit(2);
    }

    aux->dato = d;
    aux->accessi = 1;
    aux->next = *pl;
    *pl = aux;
}

/*void insCoda(lista_t *pl, dato_t d)
{
    while (pl)
        pl = &(*pl)->next;

    insTesta(pl, d);
}*/

lista_t *targaEsistente(lista_t *pl, dato_t d)
{
    while (*pl)
    {
        if (strcmp((*pl)->dato.targa, d.targa))
        {
            break;
        }
        pl = &(*pl)->next;
    }

    return pl;
}

void insOrd(lista_t *pl, dato_t d)
{
    pl = targaEsistente(pl, d);
    if (*pl)
    {
        ++(*pl)->accessi;
    }
    else
    {
        insTesta(pl, d);
    }
}

float calcoloImporto(int accessi)
{
    if (accessi <= 5)
    {
        return accessi * 2.00;
    }
    else
    {
        if (accessi <= 10)
        {
            return accessi * 1.90;
        }
        else
        {
            return accessi * 1.80;
        }
    }
}

void stampaImporto(lista_t l)
{
    float importo;
    while (l)
    {
        importo = calcoloImporto(l->accessi);
        printf("%s %.3f\n", l->dato.targa, importo);
        l = l->next;
    }
}