typedef struct dato
{
    char indirizzo[30];
    int vani;
    float distanza_centro;
} dato_t;

typedef struct nodo
{
    dato_t dato;
    struct nodo *next;
} nodo_t;

typedef nodo_t *lista_t;

void nuovaLista(lista_t *pl);
void insTesta(lista_t *pl, dato_t d);
lista_t *ricerca(lista_t *pl, dato_t d);
void insOrdinato(lista_t *pl, dato_t d);
void stampa(lista_t l);