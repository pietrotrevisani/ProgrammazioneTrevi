#include <stdio.h>
#include <stdlib.h>
#include "listaCani.h"

void nuovaLista(lista_t *pl)
{
    *pl = NULL;
}

void insTesta(lista_t *pl, vaccino_t v)
{
    nodo_t *aux = (nodo_t *)malloc(sizeof(nodo_t));
    int find = 0;

    while (*pl)
    {
        if ((*pl)->dato.chip == v.chip)
        {
            switch (v.tipo)
            {
            case 'C':
                (*pl)->dato.c = 1;
                break;
            case 'E':
                (*pl)->dato.e = 1;
                break;
            case 'P':
                (*pl)->dato.p = 1;
                break;
            default:
                printf("Tipo vaccino non corretto.\n");
                break;
            }
            find = 1;
        }
        pl = &(*pl)->next;
    }

    if (!find)
    {
        switch (v.tipo)
        {
        case 'C':
            aux->dato.c = 1;
            aux->dato.e = 0;
            aux->dato.p = 0;
            break;
        case 'E':
            aux->dato.c = 0;
            aux->dato.e = 1;
            aux->dato.p = 0;
            break;
        case 'P':
            aux->dato.c = 0;
            aux->dato.e = 0;
            aux->dato.p = 1;
            break;
        default:
            printf("Tipo vaccino non corretto.\n");
            break;
        }
        aux->dato.chip = v.chip;
        aux->next = *pl;
        *pl = aux;
    }
}

void vacciniMancanti(lista_t l)
{
    while (l)
    {
        printf("%d: ", l->dato.chip);

        if (!l->dato.c)
            printf("cimurro ");
        if (!l->dato.e)
            printf("epatite ");
        if (!l->dato.p)
            printf("parvovirosi");

        printf("\n");

        l = l->next;
    }
}

int precede(lista_t l1, lista_t l2)
{
    int n1 = l1->dato.c + l1->dato.e + l1->dato.p;
    int n2 = l2->dato.c + l2->dato.e + l2->dato.p;
    return n1 < n2 || l1->dato.chip < l2->dato.chip && n1 == n2;
}

void insOrd(lista_t *pl)
{
    while ((*pl)->next)
    {
        if (precede(*pl, (*pl)->next))
        {
            lista_t *temp;
            temp = pl;
            *pl = (*pl)->next;
            (*pl)->next = *temp;
        }

        pl = &(*pl)->next;
    }
}

void insFile(lista_t l, FILE *fp)
{
    while (l)
    {
        insOrd(&l);
        l = l->next;
    }

    while (l)
    {
        fprintf(fp, "%d (%d vaccini)\n", l->dato.chip, l->dato.c + l->dato.e + l->dato.p);
        l = l->next;
    }
}