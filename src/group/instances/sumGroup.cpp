template<typename T> struct sumGroup {
  using value_type = T;
  constexpr T id() { return 0; }
  constexpr T operator()(const T &a, const T &b) { return a + b; }
  constexpr T inv(const T &x) { return -x; }
};
