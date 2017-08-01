struct lcmMonoid {
  using value_type = int;
  constexpr int id() const { return 1; }
  int operator()(const int &a, const int &b) const { return lcm(a, b); }
};
