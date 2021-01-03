#include <stdio.h>
#define DIM 30

int ricerca_binaria(int a[], int first, int last, int n)
{
    if (first > last)
        return -1;
    int med = (first + last) / 2;
    if (a[med] == n)
        return med;
    else
    {
        if (a[med] > n)
            return ricerca_binaria(a, first, med - 1, n);
        else
            return ricerca_binaria(a, med + 1, last, n);
    }
}

int main(void)
{
    int array[DIM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
                      22, 23, 24, 25, 26, 27, 28, 29};
    int n, ris;
    puts("Inserisci il numero da cercare: ");
    scanf("%d", &n);
    ris = ricerca_binaria(array, 0, DIM, n);
    if (ris < 0)
        printf("Numero non trovato.\n");
    else
        printf("Il numero cercato si trova nella posizione %d.\n", ris);
    return 0;
}