typedef int dato_t;

typedef struct nodo
{
    dato_t dato;
    struct nodo *next;
} nodo_t;

typedef struct lista
{
    size_t size;
    nodo_t *head;
} lista_t;

void insTesta(lista_t *pl, dato_t d);
lista_t nuovaLista();
void reverse(lista_t *pl);
void stampaLista(lista_t l);
void elimTesta(lista_t *pl);
void insOrdinato(lista_t *pl, dato_t d);
void insCoda(lista_t *pl, dato_t d);