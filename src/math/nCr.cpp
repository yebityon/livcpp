template<typename Integral = int> Integral nCr(const int n, const int r) {
  int c = n - r;
  if (c < r) return nCr<Integral>(n, c);
  static std::vector<std::vector<Integral>> dp(1, std::vector<Integral>(1, 1));
  int prevC = dp.size(), prevR = dp.front().size();
  if (prevC <= c) dp.resize(c + 1);
  for (auto &row : dp) {
    if (row.size() <= r) row.resize(r + 1);
  }
  if (prevR <= r) {
    rep(i, prevC) loop(j, prevR, r + 1) {
      if (i > 0) dp[i][j] += dp[i - 1][j];
      if (j > 0) dp[i][j] += dp[i][j - 1];
    }
  }
  loop(i, prevC, c + 1) rep(j, r + 1) {
    if (i > 0) dp[i][j] += dp[i - 1][j];
    if (j > 0) dp[i][j] += dp[i][j - 1];
  }
  return dp[c][r];
}
