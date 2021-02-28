#include "eop.h"

template <typename F>
    requires(Transformation(F))
DistanceType(F) cycle_length_nonterminating_orbit(Domain(F) x, F f)
{
    typedef DistanceType(F) N;
    N c(0);
    N q(1);
    Domain(F) x0 = x;

    while (!(x == x0 && c != 0)) {
        if (c == q) {
            x0 = x;
            c = 0;
            q = 2 * q;
        } else {
            x = f(x);
            c = c + 1;
        }
    }

    return c;
}

template <typename F>
    requires(Transformation(F))
triple<DistanceType(F), DistanceType(F), Domain(F)>
orbit_structure_nonterminating_orbit_levy(const Domain(F)& x, F f)
{
    typedef DistanceType(F) N;
    N c = cycle_length_nonterminating_orbit(x, f);
    Domain(F) y = convergent_point(x, power_unary(x, c, f), f);
    return triple<N, N, Domain(F)>(distance(x, y, f), c, y);
}

struct index_map {
    const int* p;

    index_map(const int* p) : p(p) { }

    int operator()(int x) const
    {
        return p[x - 1];
    }
};

template <>
struct distance_type<index_map>
{
    typedef int type;
};

template <>
struct input_type<index_map, 0>
{
    typedef int type;
};

int main()
{
    int a[] = { 1, 3, 4, 2, 2 };
    index_map f(a);
    triple<int, int, int> t = orbit_structure_nonterminating_orbit_levy(5, f);
    // orbit of f under 5 is: 5 -> 2 -> 3 -> 4 -> 2 ...
    Assert(t.m0 == 1);
    Assert(t.m1 == 3);
    Assert(t.m2 == 2);
}
