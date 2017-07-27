template<class InputIterator, class T> T fold(InputIterator first, InputIterator last, Monoid<T> m) {
  T init = m.id;
  while (first != last) {
    init = m.op(init, *first);
    ++first;
  }
  return init;
}
