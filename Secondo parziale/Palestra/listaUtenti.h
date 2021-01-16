typedef struct
{
    char codice[17];
} codice_fiscale;

typedef struct dato
{
    char cf[17];
    int prima;
    int seconda;
    int terza;
    int disattiva;
} dato_t;

typedef struct nodo
{
    dato_t dato;
    struct nodo *next;
} nodo_t;

typedef nodo_t *lista_t;

void nuovaLista(lista_t *pl);
void insCF(lista_t *pl, codice_fiscale cf);
void controllaAccesso(lista_t *pl, codice_fiscale cf, int a);
void stampaLista(lista_t l);
