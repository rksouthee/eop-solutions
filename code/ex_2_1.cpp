#include <stdint.h>
#include "eop.h"

bool addition_predicate(int x, int y)
{
    if (x < 0)
        return y >= INT_MIN - x;
    return y <= INT_MAX - x;
}

int main()
{
    Assert(addition_predicate(INT_MAX, 0));
    Assert(addition_predicate(0, INT_MAX));
    Assert(addition_predicate(INT_MIN, 0));
    Assert(addition_predicate(0, INT_MIN));
    Assert(!addition_predicate(INT_MAX, 1));
    Assert(!addition_predicate(1, INT_MAX));
    Assert(!addition_predicate(-1, INT_MIN));
    Assert(!addition_predicate(INT_MIN, -1));
}
