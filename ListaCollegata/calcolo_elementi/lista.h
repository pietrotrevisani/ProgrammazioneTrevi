typedef int dato_t;

typedef struct nodo
{
    dato_t dato;
    struct nodo *next;
} nodo_t;

typedef nodo_t *lista_t;

void listaNonOrdinata(lista_t *l, int dim);
void stampaLista(lista_t l);
void azzera(lista_t l);
int lunghezza(lista_t l);
int *listToArray(lista_t l);