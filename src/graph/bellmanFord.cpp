template<int inf = std::numeric_limits<Weight>::max() / 8> std::pair<std::vector<Weight>, bool> bellmanFord(const Graph &g, int src) {
  int n = g.size();
  Edges es;
  for (auto &adj : g) {
    for (auto &e : adj) es.emplace_back(e);
  }
  std::vector<Weight> dist(n, inf);
  dist[src] = 0;
  bool negCycle = false;
  for (int i = 0;; i++) {
    bool updated = false;
    for (auto &e : es) {
      if (dist[e.src] != inf) {
        if (cmin(dist[e.dst], dist[e.src] + e.weight)) updated = true;
      }
    }
    if (!updated) break;
    if (i > n) {
      negCycle = true;
      break;
    }
  }
  return {dist, negCycle};
}
