#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

int main(void)
{
    FILE *fp;
    char nome_file[DIM];
    char c;
    puts("Inserisci nome del file da aprire: ");
    scanf("%s", nome_file);
    fp = fopen(nome_file, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file.");
        exit(1);
    }

    /*while (!feof(fp))
    {
        fscanf(fp, "%c", &c);
        printf("%c", c);
    }*/

    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    return 0;
}