#include <stdio.h>
#include "immobili.h"

int main(void)
{
    dato_t immobile;
    lista_t l;
    FILE *fp = fopen("immobili.dat", "r");

    if (!fp)
    {
        puts("Errore di apertura del file.");
        exit(1);
    }

    init(&l);

    while (fp)
    {
        fscanf(fp, "%s %d %f", immobile.indirizzo, immobile.vani, immobile.distanza_centro);
        insOrd(&l, immobile);
    }

    return 0;
}