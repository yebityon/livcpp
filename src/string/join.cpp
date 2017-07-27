template<typename V> constexpr std::string join(const V &v, const std::string &sep) {
  std::stringstream ss;
  if (v.size()) ss << v[0];
  loop(i, 1, v.size()) ss << sep << v[i];
  return ss.str();
}
