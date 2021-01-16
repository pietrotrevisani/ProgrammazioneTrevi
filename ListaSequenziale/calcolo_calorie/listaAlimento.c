#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaAlimento.h"

int caricaCalorie(char nomeFileBinario[], lista_t *pl)
{
  int numero;
  FILE *fb;
  fb = fopen(nomeFileBinario, "rb");
  if (fb == NULL)
  {
    printf("Impossibile aprire %s", nomeFileBinario);
    exit(3);
  }
  numero = fread(pl->dati, sizeof(Alimento), DIM, fb);

  fclose(fb);
  return numero;
}

float calorieAlimento(char nomeAlimento[], lista_t l)
{
  int i;
  for (i = 0; i < l.n_elementi; i++)
    if (strcmp(nomeAlimento, l.dati[i].nome) == 0)
      return l.dati[i].calorie;
  printf("Alimento non trovato");
  exit(4);
}