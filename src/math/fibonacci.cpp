template<typename Integral = int> Integral fibonacci(const int n) {
  static vector<Integral> dp(2, 1);
  int prev = dp.size();
  if (prev < n + 1) {
    dp.resize(n + 1);
    loop(i, prev, dp.size()) dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}
