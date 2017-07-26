template<int inf>
Monoid<int> maxMonoid = {-inf, [](int a, int b) { return max(a, b); }};
