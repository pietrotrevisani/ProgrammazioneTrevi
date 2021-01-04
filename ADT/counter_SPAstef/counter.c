#include "counter.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct counter_data
{
    int i;
} cdata_t;


void reset(counter_t c)
{
    c.data->i = 0;
}

void increment(counter_t c)
{
    ++c.data->i;
}

void print(counter_t c)
{
    printf("%d", c.data->i);
}

counter_t init(void)
{
    return (counter_t){
        .data = malloc(sizeof(cdata_t)),
        .reset = reset,
        .increment = increment,
        .print = print,
    };
}

void del(counter_t c)
{
    free(c.data);
}
