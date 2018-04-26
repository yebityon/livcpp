template<int inf = numeric_limits<Weight>::max() / 8> Weight TSP(const Graph &g) {
  int n = g.size();
  Matrix dp(1 << n, Array(n, inf));
  dp[0][0] = 0;
  rep(s, 1 << n) {
    for (auto &es : g) {
      for (auto &e : es) {
        if (~s >> e.dst & 1) cmin(dp[s | 1 << e.dst][e.dst], dp[s][e.src] + e.weight);
      }
    }
  }
  return dp.back().front();
}
