template<typename InputIterator> string join(InputIterator first, InputIterator last, const string &sep) {
  if (first == last) return "";
  stringstream ss;
  ss << *(first++);
  for_each(first, last, [&](auto &x) { ss << sep << x; });
  return ss.str();
}
