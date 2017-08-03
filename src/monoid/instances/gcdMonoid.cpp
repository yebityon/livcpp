struct gcdMonoid {
  using value_type = int;
  constexpr int id() { return 0; }
  constexpr int operator()(const int &a, const int &b) { return gcd(a, b); }
};
