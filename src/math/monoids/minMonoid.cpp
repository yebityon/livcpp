template<int upperInf>
Monoid<int> minMonoid = {upperInf, [](int a, int b) { return min(a, b); }};
