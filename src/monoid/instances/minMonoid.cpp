template<typename T, T upperInf = std::numeric_limits<T>::max()> struct minMonoid {
  using value_type = T;
  constexpr T id() { return upperInf; }
  constexpr T operator()(const T &a, const T &b) { return a < b ? a : b; }
};
