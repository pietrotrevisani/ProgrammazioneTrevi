#include <stdio.h>

char f(char *d)
{
    int i, *p = (int *)d;
    char *q;
    p++;
    q = (char *)p;
    return *q;
}

int main()
{
    printf("%c", f("abcdefg"));
}