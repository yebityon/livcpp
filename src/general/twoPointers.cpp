/*
  This algorithm enumerates all intervals [l, r) that satisfies f(l, r) && !f(l + 1, r) && !f(l, r - 1)
  The function f should satisfy the twoPointers laws:
    [l, r) is empty => f(l, r)
    f(l, r) => f(l - 1, r) && f(l, r + 1)
*/
template<typename InputIterator, typename F> std::vector<std::pair<InputIterator, InputIterator>> twoPointers(InputIterator first, InputIterator last, const F &f) {
  std::vector<std::pair<InputIterator, InputIterator>> v;
  for (InputIterator l = first, r = first;; l++) {
    while (r != last && !f(l, r)) r++;
    if (!f(l, r)) break;
    v.emplace_back(l, r);
  }
  return v;
}
