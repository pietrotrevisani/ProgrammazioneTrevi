#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

#define STR0(x) #x
#define STR(x) STR0(x)

nodo_t *nodoInit(dato_t d)
{
    nodo_t *aux = (nodo_t *)malloc(sizeof(nodo_t));

    if (!aux)
    {
        perror(__FILE__ ", line " STR(__LINE__));
        exit(EXIT_FAILURE);
    }
    aux->dato = d;

    return aux;
}

void insTesta(lista_t *pl, dato_t d)
{
    nodo_t *aux = nodoInit(d);

    aux->next = pl->head;
    pl->head = aux;
    ++pl->size;
}

lista_t nuovaLista(void)
{
    return (lista_t){0};
}

void reverse(lista_t *pl)
{
    nodo_t *aux1 = pl->head;

    if (!aux1)
        return;

    nodo_t *aux2 = aux1->next;
    aux1->next = NULL;

    while (aux2)
    {
        nodo_t *aux3 = aux2->next;

        aux2->next = aux1;
        aux1 = aux2;
        aux2 = aux3;
    }
}

void stampaLista(lista_t l)
{
    for (; l.head; l.head = l.head->next)
        printf("%d ", l.head->dato);
}

void elimTesta(lista_t *pl)
{
    nodo_t *aux = pl->head;

    pl->head = pl->head->next;
    --pl->size;
    free(aux);
}

void insOrdinato(lista_t *pl, dato_t d)
{
    nodo_t *aux = pl->head;

    if (!aux)
    {
        insTesta(pl, d);
        return;
    }

    //devo mettere l'indirizzo della sottolista al puntatore pl se no modifico la lista del main
    nodo_t *aux2 = nodoInit(d);
    for (; aux->next && aux->dato < d; aux = aux->next)
        ;

    aux2->next = aux->next;
    aux->next = aux2;
    ++pl->size;
}

void insCoda(lista_t *pl, dato_t d)
{
    nodo_t *tail = pl->head;

    if (!tail)
    {
        insTesta(pl, d);
        return;
    }

    nodo_t *aux = nodoInit(d);
    for (; tail->next; tail = tail->next)
        ;

    tail->next = aux;
    ++pl->size;
}
