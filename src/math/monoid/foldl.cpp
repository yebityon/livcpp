template<typename Result, typename F, typename InputIterator> Result foldl(InputIterator first, InputIterator last, Result init, const F &f) {
  for_each(first, last, [&](auto &x) { init = f(init, x); });
  return init;
}
