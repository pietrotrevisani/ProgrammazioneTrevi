#include <stdio.h>

int massimo(int a[], int n)
{
    int m;

    if (n == 0)
        return a[0];
    else
    {
        m = massimo(a, n - 1); /* usiamo m per evitare di richiamare massimo() 
        due volte il che aumenterebbe il tempo di calcolo */
        if (m < a[n])
            return a[n];
        else
            return m;
    }
}

int main(void)
{
    int array[8] = {3, 4, 1, 2, 5, 1, 2, 1};
    int n, ris;
    puts("Inserisci un indice n: ");
    scanf("%d", &n);
    ris = massimo(array, n);
    printf("%d\n", ris);
    return 0;
}