template<typename T> int LCS(const T &a, const T &b) {
  const int n = a.size(), m = b.size();
  vvi dp(n + 1, vi(m + 1));
  rep(i, n) rep(j, m) {
    if (a[i] == b[j]) cmax(dp[i + 1][j + 1], dp[i][j] + 1);
    cmax(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
  }
  return dp.back().back();
}
