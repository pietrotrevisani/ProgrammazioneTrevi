#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

int main(void)
{

    FILE *fp;
    fp = fopen("prova.txt", "w");

    if (fp == NULL)
    {
        printf("Errore di apertura del file.");
        exit(1);
    }

    char stringa[DIM];
    do
    {
        puts("Inserisci parola: ");
        scanf("%s", stringa);
        fprintf(fp, "%s ", stringa);
    } while (strcmp(stringa,"FINE"));

    fclose(fp);

    return 0;
}