template<typename T> vector<T> nub(const vector<T> &xs) {
  set<T> s(xs.begin(), xs.end());
  vector<T> ys(s.begin(), s.end());
  return ys;
}
