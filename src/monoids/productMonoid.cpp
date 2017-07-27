template<typename T> struct productMonoid {
  using value_type = T;
  constexpr T id() const { return 1; }
  T operator()(const T &a, const T &b) const { return a * b; }
};
