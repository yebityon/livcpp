template<typename T> std::vector<T> LIS(const std::vector<T> &v) {
  int n = v.size();
  const int inf = std::numeric_limits<T>::max();
  std::vector<T> dp(n, inf);
  rep(i, n) * std::lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
  return std::vector<T>(dp.begin(), std::lower_bound(dp.begin(), dp.end(), inf));
}
