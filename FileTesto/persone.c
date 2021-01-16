#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 31

typedef struct
{
    char cognome[DIM];
    char nome[DIM];
    char sesso[2];
    char data_nascita[5];
} Persona;

int main(void)
{
    Persona p[DIM];
    FILE *fp;
    fp = fopen("persone.txt", "r");

    if (fp == NULL)
    {
        printf("Errore di apertura del file.");
        exit(1);
    }

    for (int i = 0; i < DIM && !feof(fp); i++)
    {
        fscanf(fp, "%s%s%s%s", p[i].cognome, p[i].nome, p[i].sesso, p[i].data_nascita);
        printf("%s %s %s %s\n", p[i].cognome, p[i].nome, p[i].sesso, p[i].data_nascita);
    }

    if (fclose(fp) != 0)
    {
        printf("Errore di chiusura del file.");
        exit(2);
    }

    return 0;
}