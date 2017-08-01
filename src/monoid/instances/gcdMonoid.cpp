template<typename T = int> struct gcdMonoid {
  using value_type = T;
  constexpr T id() const { return 0; }
  T operator()(const T &a, const T &b) const { return gcd(a, b); }
};
