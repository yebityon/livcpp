template<typename T, T lowerInf = numeric_limits<T>::min()> struct maxMonoid {
  using value_type = T;
  value_type id() { return lowerInf; }
  value_type operator()(const value_type &a, const value_type &b) { return a < b ? b : a; }
};
