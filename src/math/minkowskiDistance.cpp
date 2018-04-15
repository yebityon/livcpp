template<typename T> T minkowskiDistance(const vector<T> &a, const vector<T> &b, const int &p) {
  int n = a.size();
  T x = 0;
  rep(i, n) x += pow(abs(a[i] - b[i]), p);
  return pow(x, 1.0 / p);
}
