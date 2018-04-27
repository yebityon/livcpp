template<typename T> vector<T> maximumSubarray(const vector<T> &v) {
  int n = v.size();
  vector<T> dp(n);
  dp[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; i--) dp[i] = max(v[i], v[i] + dp[i + 1]);
  auto begin = max_element(all(dp));
  int l, r;
  l = r = distance(dp.begin(), begin);
  int maxSum = *begin, acc = 0;
  while (acc != maxSum) acc += v[r++];
  return vector<T>(v.begin() + l, v.begin() + r);
}
