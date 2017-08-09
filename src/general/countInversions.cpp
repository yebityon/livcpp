template<typename InputIterator> int countInversions(InputIterator first, InputIterator last) {
  FenwickTree<sumGroup<int>> ft(*max_element(first, last));
  int c = 0;
  for (int i = 0; first != last; i++, first++) {
    c += i - ft.fold(*first);
    ft.add(*first, 1);
  }
  return c;
}
