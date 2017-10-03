template<typename Result, typename F, typename InputIterator> Result foldr(InputIterator first, InputIterator last, Result init, const F &f) {
  std::reverse_iterator<InputIterator> rfirst(first), rlast(last);
  std::for_each(rlast, rfirst, [&](auto &x) { init = f(x, init); });
  return init;
}
