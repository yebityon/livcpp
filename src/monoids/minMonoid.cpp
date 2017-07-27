template<typename T, T upperInf = std::numeric_limits<T>::max()> struct minMonoid {
  using value_type = T;
  constexpr T id() const { return upperInf; }
  T operator()(const T &a, const T &b) const { return std::min(a, b); }
};
