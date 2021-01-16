#define DIM 50

typedef struct lista
{
    int n_elementi;
    int dati[DIM];
} lista_t;

void nuovaLista(lista_t *pl);
int piena(lista_t l);
void stampaLista(lista_t l);
void inserisciOrdinato(lista_t *pl, int n);
