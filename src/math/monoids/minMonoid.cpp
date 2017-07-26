template<int inf>
Monoid<int> minMonoid = {inf, [](int a, int b) { return min(a, b); }};
