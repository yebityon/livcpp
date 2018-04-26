int knapsack(int items, int maxW, const vector<int> &ws, const vector<int> &vs) {
  map<pii, int> dp;
  F<int(int, int)> f = [&](int i, int j) {
    pii p = {i, j};
    if (dp.count(p)) return dp[p];
    if (i == items) return dp[p] = 0;
    int r = f(i + 1, j);
    if (j - ws[i] >= 0) cmax(r, f(i + 1, j - ws[i]) + vs[i]);
    dp[p] = r;
    return r;
  };
  return f(0, maxW);
}
