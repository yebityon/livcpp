struct lcmMonoid {
  using value_type = int;
  constexpr value_type id() { return 1; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return lcm(a, b); }
};
