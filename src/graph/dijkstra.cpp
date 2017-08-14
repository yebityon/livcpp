template<int inf = std::numeric_limits<Weight>::max() / 8> std::pair<std::vector<Weight>, std::vector<int>> dijkstra(const Graph &g, const int src) {
  using state = std::pair<Weight, int>;
  std::priority_queue<state, std::vector<state>, std::greater<state>> q;
  std::vector<Weight> dist(g.size(), inf);
  std::vector<int> via(g.size());
  dist[src] = 0;
  q.emplace(0, src);
  while (q.size()) {
    Weight d;
    int v;
    std::tie(d, v) = q.top();
    q.pop();
    if (dist[v] < d) continue;
    for (auto &e : g[v]) {
      if (cmin(dist[e.dst], dist[v] + e.weight)) {
        via[e.dst] = v;
        q.emplace(dist[e.dst], e.dst);
      }
    }
  }
  return {dist, via};
}
