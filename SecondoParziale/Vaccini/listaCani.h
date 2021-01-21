typedef struct vaccino
{
    int chip;
    char tipo;
} vaccino_t;

typedef struct dato
{
    int chip;
    int c;
    int e;
    int p;
} dato_t;

typedef struct nodo
{
    dato_t dato;
    struct nodo *next;
} nodo_t;

typedef nodo_t *lista_t;

void nuovaLista(lista_t *pl);
void insTesta(lista_t *pl, vaccino_t v);
void vacciniMancanti(lista_t l);
void insFile(lista_t l, FILE *fp);
