template<typename T> struct productMonoid {
  using value_type = T;
  value_type id() { return 1; }
  value_type operator()(const value_type &a, const value_type &b) { return a * b; }
};
