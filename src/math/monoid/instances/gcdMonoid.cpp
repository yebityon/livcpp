struct gcdMonoid {
  using value_type = int;
  constexpr value_type id() { return 0; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return gcd(a, b); }
};
