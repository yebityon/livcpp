template<int inf = std::numeric_limits<Weight>::max() / 8> std::pair<std::vector<Weight>, std::vector<int>> bellmanFord(const Graph &g, int src) {
  int n = g.size();
  Edges es;
  for (auto &adj : g) {
    for (auto &e : adj) es.emplace_back(e);
  }
  std::vector<Weight> dist(n, inf);
  dist[src] = 0;
  std::vector<int> negCycle(n);
  rep(i, n) {
    for (auto &e : es) {
      if (dist[e.src] == inf) continue;
      if (cmin(dist[e.dst], dist[e.src] + e.weight)) {
        if (i == n - 1) negCycle[e.dst] = true;
      }
    }
  }
  return {dist, negCycle};
}
