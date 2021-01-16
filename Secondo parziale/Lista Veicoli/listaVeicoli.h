typedef struct dato
{
    char targa[8];
    float sosta;
} dato_t;

typedef struct nodo
{
    dato_t dato;
    int accessi;
    struct nodo *next;
} nodo_t;

typedef nodo_t *lista_t;

void nuovaLista(lista_t *pl);
void insTesta(lista_t *pl, dato_t d);
void insCoda(lista_t *pl, dato_t d);
void insOrd(lista_t *pl, dato_t d);
void stampaImporto(lista_t l);