template<typename T = bool> struct andMonoid {
  using value_type = T;
  constexpr value_type id() { return false; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return a | b; }
};
