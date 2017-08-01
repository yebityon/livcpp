template<typename Monoid> constexpr typename Monoid::value_type powm(typename Monoid::value_type a, int b) {
  Monoid m = Monoid();
  typename Monoid::value_type c = m.id();
  while (b) {
    if (b & 1) c = m(c, a);
    b >>= 1;
    a = m(a, a);
  }
  return c;
}
