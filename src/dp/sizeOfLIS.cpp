template<typename T> int sizeOfLIS(const vector<T> &v) {
  int n = v.size();
  const int inf = numeric_limits<T>::max();
  vector<T> dp(n, inf);
  rep(i, n) * lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
  return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));
}
