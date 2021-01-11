#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "immobili.h"

int main(void)
{
    dato_t immobile;
    lista_t l;
    FILE *fp;

    if ((fp = fopen("immobili copy.dat", "r+b")) == NULL)
    {
        puts("Errore di apertura del file.");
        exit(1);
    }

    init(&l);

    while (fread(&immobile, sizeof(dato_t), 1, fp))
    {
        insOrd(&l, immobile);
    }

    stampaLista(l);

    fclose(fp);

        return 0;
}