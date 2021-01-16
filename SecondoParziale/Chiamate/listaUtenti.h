typedef struct chiamata
{
    char numero[11];
    int durata;
} chiamata_t;

typedef struct dato
{
    char numero[11];
    char piano;
    float credito;
} dato_t;

typedef struct nodo
{
    dato_t dato;
    struct nodo *next;
} nodo_t;

typedef nodo_t *lista_t;

void nuovaLista(lista_t *pl);
void insTesta(lista_t *pl, dato_t d);
void aggiornaCredito(lista_t *pl, chiamata_t c);
void stampaCredito(lista_t l);
