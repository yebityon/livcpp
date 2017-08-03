struct lcmMonoid {
  using value_type = int;
  constexpr int id() { return 1; }
  constexpr int operator()(const int &a, const int &b) { return lcm(a, b); }
};
