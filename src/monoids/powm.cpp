template<typename Monoid> constexpr int powm(typename Monoid::value_type a, int b) {
  Monoid m = Monoid();
  int c = m.id();
  while (b) {
    if (b & 1) c = m(c, a);
    b >>= 1;
    a = m(a, a);
  }
  return c;
}
