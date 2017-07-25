template<typename Integer = int>
Integer factorial(const int& n) {
  static std::vector<Integer> dp(1, 1);
  if (dp.size() < n) dp.resize(n + 1);
  if (dp[n] != 0) return dp[n];
  dp[n] = factorial<Integer>(n - 1) * Integer(n);
  return dp[n];
}
