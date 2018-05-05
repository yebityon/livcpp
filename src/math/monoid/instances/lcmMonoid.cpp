struct lcmMonoid {
  using value_type = int;
  value_type id() { return 1; }
  value_type operator()(const value_type &a, const value_type &b) { return lcm(a, b); }
};
