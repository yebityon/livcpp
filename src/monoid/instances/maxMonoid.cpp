template<typename T, T lowerInf = std::numeric_limits<T>::min()> struct maxMonoid {
  using value_type = T;
  constexpr T id() { return lowerInf; }
  constexpr T operator()(const T &a, const T &b) { return a < b ? b : a; }
};
