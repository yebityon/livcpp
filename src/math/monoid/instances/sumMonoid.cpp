template<typename T> struct sumMonoid {
  using value_type = T;
  constexpr value_type id() { return 0; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return a + b; }
};
