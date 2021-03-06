#include "eop.h"

template <typename F, typename P>
    requires(Transformation(F) && UnaryPredicate(P) &&
        Domain(F) == Domain(P))
bool intersects(const Domain(F)& x0,
                const Domain(F)& x1, F f, P p)
{
    // Precondition: $p(x) \Leftrightarrow \text{$f(x)$ is defined}$
    return connection_point(x0, f, p) ==
        connection_point(x1, f, p);
}

int main()
{
}
