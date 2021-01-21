#include <stdio.h>

int f(int d)
{
    switch (d)
    {
    case 1:
        return 2;
        break;
    case 2:
        return 1;
        break;
    case 3:
        return 6;
        break;
    case 4:
        return 3;
        break;
    case 5:
        return 6;
        break;
    case 6:
        return 5;
        break;
    default:
        return 0;
        break;
    }
}

int main()
{
    int i = 8;
    while (!f(--i))
        ;
    do
    {
        printf("%c", '0' + f(i--));
    } while (f(i));
    printf("\n");
    return 0;
}
