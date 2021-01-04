#pragma once

typedef struct counter counter_t;

struct counter
{
    struct counter_data *data;

    void (*reset)(counter_t);
    void (*increment)(counter_t);
    void (*print)(counter_t);
};

counter_t init(void);

void del(counter_t);