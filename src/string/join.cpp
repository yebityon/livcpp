template<typename InputIterator> constexpr std::string join(InputIterator first, InputIterator last, const std::string &sep) {
  if (first == last) return "";
  std::stringstream ss;
  ss << *(first++);
  for_each(first, last, [&](auto &x) { ss << sep << x; });
  return ss.str();
}
