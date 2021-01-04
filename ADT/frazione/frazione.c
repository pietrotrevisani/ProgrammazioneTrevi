#include <stdio.h>
#include "frazione.h"

//Costruttore
Frazione frazione(int n, int d)
{
    if (d != 0)
    {
        int mcd = MCD(n, d);
        Frazione f;
        f.num = n / mcd;
        f.den = d / mcd;
        return f;
    }
    else
    {
        printf("Frazione non valida. (Denominatore nullo)\n");
        exit(1);
    }
}

//Utility: funzioni utili al file attuale da non mettere nel file .h
int MCD(int a, int b)
{
    a = a > 0 ? a : -a;
    b = a > 0 ? b : -b;
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

//Getter: restituiscono valori dell'oggetto Frazione
int numeratore(Frazione f)
{
    return f.num;
}

int denominatore(Frazione f)
{
    return f.den;
}

//Costruttore
Frazione leggiFrazione()
{
    int n, d;
    scanf("%d%d", &n, &d);
    return frazione(n, d);
}

void stampaFrazione(Frazione f)
{
    printf("%d/%d", f.num, f.den);
}

Frazione somma(Frazione f1, Frazione f2)
{
    int n, d;
    n = numeratore(f1) * denominatore(f2) + denominatore(f1) * denominatore(f2);
    d = denominatore(f1) + denominatore(f2);
    return frazione(n, d);
}

Frazione opposto(Frazione f)
{
    return frazione(-numeratore(f), denominatore(f));
}

Frazione sottrazione(Frazione f1, Frazione f2)
{
    return somma(f1, opposto(f2));
}