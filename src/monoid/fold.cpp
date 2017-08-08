template<typename Monoid, typename InputIterator> typename Monoid::value_type fold(InputIterator first, InputIterator last) {
  Monoid m;
  auto acc = m.id();
  std::for_each(first, last, [&](auto &x) { acc = m(acc, x); });
  return acc;
}
