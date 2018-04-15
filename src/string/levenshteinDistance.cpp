int levenshteinDistance(const string &s, const string &t) {
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  rep(i, n + 1) dp[i][0] = i;
  rep(j, m + 1) dp[0][j] = j;
  loop(i, 1, n + 1) loop(j, 1, m + 1) dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});
  return dp[n][m];
}