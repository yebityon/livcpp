template<int lowerInf = std::numeric_limits<int>::min() / 8>
Monoid<int> maxMonoid = {lowerInf, [](int a, int b) { return max(a, b); }};
