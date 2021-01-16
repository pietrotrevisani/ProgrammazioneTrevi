#include <stdio.h>
#include <stdlib.h>
#include "listaImmobili.h"

int main(int argc, char *argv[])
{
    lista_t l;
    FILE *fp;
    dato_t d;
    int a;

    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        puts("Errore apertura file.");
        exit(1);
    }

    nuovaLista(&l);

    while (fread(&d, sizeof(dato_t), 1, fp))
    {
        insOrdinato(&l, d);
    }

    stampa(l);
    fclose(fp);

    puts("Inserisci un numero:");
    scanf("%d", &a);

    if ((fp = fopen("vani.txt", "wt")) == NULL)
    {
        puts("Errore apertura file.");
        exit(1);
    }

    ordinaVani(ricercaVani(l, a), fp);
    fclose(fp);
    
    return 0;
}