#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

void nuovaLista(lista_t *pl)
{
    *pl = NULL;
}

void insTesta(lista_t *pl, dato_t d)
{
    nodo_t *aux = (nodo_t *)malloc(sizeof(nodo_t));

    if (aux == NULL)
    {
        puts("Errore malloc.");
        exit(2);
    }

    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void aggiornaCredito(lista_t *pl, chiamata_t c)
{
    float costo;

    while (*pl)
    {
        if (strcmp((*pl)->dato.numero, c.numero) == 0)
        {
            switch ((*pl)->dato.piano)
            {
            case 'A':
                costo = 0.15 + 0.08 * (c.durata % 60);
                break;
            case 'B':
                costo = (0.12 / 60) * c.durata;
                break;
            default:
                printf("Piano cliente non valido: %c", (*pl)->dato.piano);
                break;
            }

            (*pl)->dato.credito -= costo;
        }
        pl = &(*pl)->next;
    }
}

void stampaCredito(lista_t l)
{
    while (l)
    {
        printf("%s %f\n", l->dato.numero, l->dato.credito);
        l = l->next;
    }
}