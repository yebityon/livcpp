struct gcdMonoid {
  using value_type = int;
  value_type id() { return 0; }
  value_type operator()(const value_type &a, const value_type &b) { return gcd(a, b); }
};
