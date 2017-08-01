template<typename T = bool> struct andMonoid {
  using value_type = T;
  constexpr T id() const { return false; }
  T operator()(const T &a, const T &b) const { return a | b; }
};
