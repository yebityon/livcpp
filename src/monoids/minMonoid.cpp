template<int upperInf = std::numeric_limits<int>::max() / 8>
Monoid<int> minMonoid = {upperInf, [](int a, int b) { return min(a, b); }};
