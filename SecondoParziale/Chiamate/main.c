#include <stdio.h>
#include <stdlib.h>
#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    lista_t l;
    FILE *fp;
    dato_t temp;
    chiamata_t chiamata;

    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        printf("Errore apertura file binario %s.\n", argv[1]);
        exit(1);
    }

    nuovaLista(&l);

    while (fread(&temp, sizeof(temp), 1, fp))
    {
        insTesta(&l, temp);
    }

    fclose(fp);

    if ((fp = fopen(argv[2], "rt")) == NULL)
    {
        printf("Errore apertura file di testo %s.\n", argv[2]);
        exit(3);
    }

    while (fscanf(fp, "%s %d", chiamata.numero, &chiamata.durata) != EOF)
    {
        aggiornaCredito(&l, chiamata);
    }

    fclose(fp);
    stampaCredito(l);

    return 0;
}