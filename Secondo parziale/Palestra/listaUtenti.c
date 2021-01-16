#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

void nuovaLista(lista_t *pl)
{
    *pl = NULL;
}

void insCF(lista_t *pl, codice_fiscale cf)
{
    nodo_t *aux = (nodo_t *)malloc(sizeof(nodo_t));

    if (aux == NULL)
    {
        puts("Errore malloc.");
        exit(2);
    }

    strcpy(aux->dato.cf, cf.codice);
    aux->dato.prima = 4;
    aux->dato.seconda = 4;
    aux->dato.terza = 4;
    aux->dato.disattiva = 3;
    aux->next = *pl;
    *pl = aux;
}

void controllaAccesso(lista_t *pl, codice_fiscale cf, int a)
{
    while (*pl)
    {
        if (strcmp((*pl)->dato.cf, cf.codice) == 0)
        {
            if ((*pl)->dato.disattiva > 0)
            {
                switch (a)
                {
                case 1:
                    if ((*pl)->dato.prima > 0)
                    {
                        --(*pl)->dato.prima;
                    }
                    else
                    {
                        printf("Codice Fiscale %s, attivita' %d: Accesso negato.\n", cf.codice, a);
                        --(*pl)->dato.disattiva;
                    }
                    break;
                case 2:
                    if ((*pl)->dato.seconda > 0)
                    {
                        --(*pl)->dato.seconda;
                    }
                    else
                    {
                        printf("Codice Fiscale %s, attivita' %d: Accesso negato.\n", cf.codice, a);
                        --(*pl)->dato.disattiva;
                    }
                    break;
                case 3:
                    if ((*pl)->dato.terza > 0)
                    {
                        --(*pl)->dato.terza;
                    }
                    else
                    {
                        printf("Codice Fiscale %s, attivita' %d: Accesso negato.\n", cf.codice, a);
                        --(*pl)->dato.disattiva;
                    }
                    break;

                default:
                    printf("Codice attivita' non valido.\n");
                    break;
                }
            }
            else
            {
                printf("Codice Fiscale %s: Tessera disattivata.\n", cf.codice);
            }
        }

        pl = &(*pl)->next;
    }
}

void stampaLista(lista_t l)
{
    while (l)
    {
        printf("%s: %d %d %d\n", l->dato.cf, l->dato.prima, l->dato.seconda, l->dato.terza);
        l = l->next;
    }
}