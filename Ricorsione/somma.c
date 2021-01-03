#include <stdio.h>

int somma(int n)
{
    if (n == 0)
        return 0; //caso base
    else
        return n + somma(n - 1); //sommo a n il suo precedente quindi n-1
}

int main(void)
{
    int n, ris;

    puts("Inserisci un numero: ");
    scanf("%d", &n);
    ris = somma(n);

    printf("%d\n",ris);

    return 0;
}