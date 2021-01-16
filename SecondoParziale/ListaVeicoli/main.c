#include <stdio.h>
#include <stdlib.h>
#include "listaVeicoli.h"

int main(int argc, char *argv[])
{
    lista_t l;
    FILE *fp;
    dato_t temp;

    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        puts("Errore apertura file.");
        exit(1);
    }

    nuovaLista(&l);

    while (fread(&temp, sizeof(dato_t), 1, fp))
    {
        insOrd(&l, temp);
    }

    stampaImporto(l);

    return 0;
}