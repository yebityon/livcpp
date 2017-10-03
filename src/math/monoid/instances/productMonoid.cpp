template<typename T> struct productMonoid {
  using value_type = T;
  constexpr value_type id() { return 1; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return a * b; }
};
