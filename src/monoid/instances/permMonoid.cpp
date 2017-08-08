template<int size, typename T> struct permMonoid {
  using value_type = T;
  constexpr value_type id() {
    value_type v(size);
    iota(v.begin(), v.end(), 0);
    return v;
  }
  value_type operator()(const value_type &a, const value_type &b) const {
    value_type v(size);
    rep(i, size) v[i] = b[a[i]];
    return v;
  }
};
