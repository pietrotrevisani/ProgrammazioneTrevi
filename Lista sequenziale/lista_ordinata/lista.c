#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void nuovaLista(lista_t *pl)
{
    pl->n_elementi = 0;
}

int piena(lista_t l)
{
    return l.n_elementi == DIM;
}

void stampaLista(lista_t l)
{
    for (int i = 0; i < l.n_elementi; i++)
    {
        printf("%d ", l.dati[i]);
    }
}

void inserisciOrdinato(lista_t *pl, int numero)
{
    int i;
    if (piena(*pl))
    {
        printf("Errore: lista piena \n");
        exit(-1);
    }
    i = pl->n_elementi;
    while (i > 0 && pl->dati[i - 1] > numero)
    {
        pl->dati[i] = pl->dati[i - 1];
        i--;
    }
    pl->dati[i] = numero;
    pl->n_elementi++;
}