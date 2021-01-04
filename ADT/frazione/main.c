#include "frazione.h"

int main(void)
{
    Frazione fr;
    fr = sottrazione(frazione(5, 6), frazione(3, 4));
    stampaFrazione(fr);
    return 0;
}