template<typename Integral = int> Integral factorial(const int &n) {
  static std::vector<Integral> dp(1, 1);
  int prev = dp.size();
  if (prev < n) {
    dp.resize(n + 1);
    loop(i, prev, dp.size()) dp[i] = dp[i - 1] * i;
  }
  return dp[n];
}
