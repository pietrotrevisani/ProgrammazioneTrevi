#include <stdio.h>
#include <stdlib.h>
#include "listaCani.h"

int main(int argc, char *argv[])
{
    lista_t l;
    FILE *fp;
    vaccino_t temp;

    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        printf("Errore apertura file %s.\n", argv[1]);
    }

    nuovaLista(&l);

    while (fread(&temp, sizeof(temp), 1, fp))
    {
        insTesta(&l, temp);
    }

    vacciniMancanti(l);

    fclose(fp);

    if ((fp = fopen("vaccinati.txt", "wt")) == NULL)
    {
        printf("Errore creazione file di testo.\n");
    }

    insFile(l, fp);

    fclose(fp);

    return 0;
}