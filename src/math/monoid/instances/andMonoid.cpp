template<typename T = bool> struct andMonoid {
  using value_type = T;
  value_type id() { return true; }
  value_type operator()(const value_type &a, const value_type &b) { return a & b; }
};
