template<typename T = bool> struct xorMonoid {
  using value_type = T;
  value_type id() { return 0; }
  value_type operator()(const value_type &a, const value_type &b) { return a ^ b; }
};
