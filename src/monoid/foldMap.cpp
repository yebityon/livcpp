template<class Monoid, class InputIterator, class F> typename Monoid::value_type foldMap(InputIterator first, InputIterator last, const F &f) {
  Monoid m = Monoid();
  auto acc = m.id();
  std::for_each(first, last, [&](auto &x) { acc = m(acc, f(x)); });
  return acc;
}
