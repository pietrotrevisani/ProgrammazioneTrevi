#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    fp = fopen("rubrica.txt", "r");

    if (fp == NULL)
    {
        printf("Errore nell'apertura del file.");
        exit(1);
    }

    char cerca[20], nome[20], indirizzo[30], numero[15];

    printf("Inserisci il nome della persona da cercare: ");
    scanf("%s", cerca);

    while (!feof(fp))
    {
        fscanf(fp, "%s", nome);
        fscanf(fp, "%s", indirizzo);
        fscanf(fp, "%s", numero);
        if (strcmp(cerca, nome) == 0)
        {
            printf("%s %s %s\n", nome, indirizzo, numero);
            break;
        }
    }
    return 0;
}