template<typename T> std::vector<T> nub(const std::vector<T> &xs) {
  std::set<T> s(xs.begin(), xs.end());
  std::vector<T> ys(s.begin(), s.end());
  return ys;
}
