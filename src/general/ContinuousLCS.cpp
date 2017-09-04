template<typename T> int ContinuousLCS(const T &a, const T &b) {
  const int n = a.size(), m = b.size();
  vvi dp(n + 1, vi(m + 1));
  int maxi = 0;
  rep(i, n) rep(j, m) {
    if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
    cmax(maxi, dp[i + 1][j + 1]);
  }
  return maxi;
}
