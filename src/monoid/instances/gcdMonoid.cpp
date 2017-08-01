struct gcdMonoid {
  using value_type = int;
  constexpr int id() const { return 0; }
  int operator()(const int &a, const int &b) const { return gcd(a, b); }
};
