#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    lista_t l;
    FILE *fp;
    codice_fiscale temp;
    int attivita;

    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        printf("Errore apertura file binario %s.\n", argv[1]);
        exit(1);
    }

    nuovaLista(&l);

    while (fread(&temp, sizeof(temp), 1, fp))
    {
        insCF(&l, temp);
    }

    fclose(fp);

    if ((fp = fopen(argv[2], "rt")) == NULL)
    {
        printf("Errore apertura file di testo %s.\n", argv[2]);
        exit(1);
    }

    while (fscanf(fp, "%s %d", temp.codice, &attivita) != EOF)
    {
        controllaAccesso(&l, temp, attivita);
    }

    stampaLista(l);

    fclose(fp);

    return 0;
}