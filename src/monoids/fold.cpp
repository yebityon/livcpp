template<class Monoid, class InputIterator> typename Monoid::value_type fold(InputIterator first, InputIterator last) {
  Monoid m = Monoid();
  using T = typename Monoid::value_type;
  T acc = m.id();
  std::for_each(first, last, [&](T &x) { acc = m(acc, x); });
  return acc;
}
