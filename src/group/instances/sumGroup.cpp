template<typename T> struct sumGroup {
  using value_type = T;
  constexpr T id() const { return 0; }
  T operator()(const T &a, const T &b) const { return a + b; }
  T inv(const T &x) const { return -x; }
};
