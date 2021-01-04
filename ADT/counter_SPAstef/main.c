#include "counter.h"
#include <stdio.h>

int main()
{
    counter_t c = init();
    counter_t d = init();

    c.reset(c);
    c.increment(c);
    c.increment(c);
    c.increment(c);
    d.increment(c);
    c.print(c);
    putchar('\n');

    return 0;
}
