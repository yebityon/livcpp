template<typename T = bool> struct andMonoid {
  using value_type = T;
  constexpr T id() { return false; }
  constexpr T operator()(const T &a, const T &b) { return a | b; }
};
