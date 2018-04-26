template<typename T, T upperInf = numeric_limits<T>::max()> struct minMonoid {
  using value_type = T;
  constexpr value_type id() { return upperInf; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return a < b ? a : b; }
};
