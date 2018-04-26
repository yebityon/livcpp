template<typename Monoid, typename InputIterator, typename F> typename Monoid::value_type foldMap(InputIterator first, InputIterator last, const F &f) {
  Monoid m;
  auto acc = m.id();
  for_each(first, last, [&](auto &x) { acc = m(acc, f(x)); });
  return acc;
}
