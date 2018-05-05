template<typename T = bool> struct anyMonoid {
  using value_type = T;
  value_type id() { return false; }
  value_type operator()(const value_type &a, const value_type &b) { return a | b; }
};
