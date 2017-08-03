template<int size, typename T> struct permMonoid {
  using value_type = T;
  constexpr T id() {
    T v(size);
    iota(v.begin(), v.end(), 0);
    return v;
  }
  T operator()(const T &a, const T &b) const {
    T v(size);
    rep(i, size) v[i] = b[a[i]];
    return v;
  }
};
