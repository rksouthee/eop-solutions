#include "eop.h"
#include "assertions.h"
#include <cmath> // NAN

int main()
{
    equal<float> r;
    Assert(r(NAN, NAN) == false);
    Assert((!r(.0f, .0f)) == false);
}
