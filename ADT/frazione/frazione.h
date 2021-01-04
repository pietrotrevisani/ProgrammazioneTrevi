typedef struct frazione
{
    int num;
    int den;
} Frazione;

Frazione frazione(int n, int d);
int numeratore(Frazione f);
int denominatore(Frazione f);
void stampaFrazione();
Frazione leggiFrazione();
Frazione somma(Frazione f1, Frazione f2);
Frazione opposto(Frazione f);
Frazione sottrazione(Frazione f1, Frazione f2);