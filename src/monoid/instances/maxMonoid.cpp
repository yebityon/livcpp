template<typename T, T lowerInf = std::numeric_limits<T>::min()> struct maxMonoid {
  using value_type = T;
  constexpr T id() const { return lowerInf; }
  T operator()(const T &a, const T &b) const { return std::max(a, b); }
};
