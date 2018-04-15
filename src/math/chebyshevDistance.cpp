template<typename T> T chebyshevDistance(const vector<T> &a, const vector<T> &b) {
  int n = a.size();
  T x = 0;
  rep(i, n) cmax(x, abs(a[i] - b[i]));
  return x;
}
