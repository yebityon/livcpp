template<typename T> struct productMonoid {
  using value_type = T;
  constexpr T id() { return 1; }
  constexpr T operator()(const T &a, const T &b) { return a * b; }
};
