#include <stdio.h>

int somma(int a[], int n)
{

    if (n == 0)
        return a[0]; //caso base
    else
        return a[n] + somma(a, n - 1); //passo l'array e decremento l'indice n
}

int main(void)
{
    int array[8] = {3, 4, 1, 2, 5, 1, 2, 1};
    int n, ris;
    puts("Inserisci un indice n: ");
    scanf("%d", &n);
    ris = somma(array, n);
    printf("%d\n", ris);
    return 0;
}