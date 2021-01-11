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

void init(lista_t *pl);
void insTesta(lista_t *pl, dato_t d);
lista_t *ricerca(lista_t *pl, dato_t d);
void insOrd(lista_t *pl, dato_t d);
void stampaLista(lista_t l);
