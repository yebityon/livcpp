Matrix Graph::warshallFloyd(const int &inf = std::numeric_limits<Weight>::max() / 8) {
  int n = g.size();
  Matrix d(n, Array(n, inf));
  rep(i, n) d[i][i] = 0;
  rep(i, n) for (auto &e : g[i]) cmin(d[e.src][e.dst], e.weight);
  rep(k, n) rep(i, n) rep(j, n) {
    if (d[i][k] != inf && d[k][j] != inf) cmin(d[i][j], d[i][k] + d[k][j]);
  }
  return d;
}
