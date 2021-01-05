#define DIM 1000

// record
typedef struct
{
  char nome[31];
  float calorie;
} Alimento;

typedef struct lista
{
  int n_elementi;
  Alimento dati[DIM];
} lista_t;

int caricaCalorie(char nomeFileBinario[], lista_t *pl);
float calorieAlimento(char nomeAlimento[], lista_t l);