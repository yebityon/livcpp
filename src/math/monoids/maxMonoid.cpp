template<int lowerInf>
Monoid<int> maxMonoid = {lowerInf, [](int a, int b) { return max(a, b); }};
