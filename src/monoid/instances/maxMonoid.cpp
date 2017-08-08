template<typename T, T lowerInf = std::numeric_limits<T>::min()> struct maxMonoid {
  using value_type = T;
  constexpr value_type id() { return lowerInf; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return a < b ? b : a; }
};
