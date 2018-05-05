template<typename T> struct sumGroup {
  using value_type = T;
  value_type id() { return 0; }
  value_type operator()(const value_type &a, const value_type &b) { return a + b; }
  value_type inv(const value_type &x) { return -x; }
};
