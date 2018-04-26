template<int inf = numeric_limits<Weight>::max() / 8> Matrix warshallFloyd(const Graph &g) {
  int n = g.size();
  Matrix d(n, Array(n, inf));
  rep(i, n) d[i][i] = 0;
  for (auto &adj : g) {
    for (auto &e : adj) cmin(d[e.src][e.dst], e.weight);
  }
  rep(k, n) rep(i, n) rep(j, n) {
    if (d[i][k] != inf && d[k][j] != inf) cmin(d[i][j], d[i][k] + d[k][j]);
  }
  return d;
}
