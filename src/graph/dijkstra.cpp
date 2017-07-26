std::vector<Weight> Graph::dijkstra(const int &src, const int &inf = std::numeric_limits<Weight>::max() / 8) {
  using state = std::pair<Weight, int>;
  std::priority_queue<state, std::vector<state>, std::greater<state>> q;
  std::vector<Weight> dist(g.size(), inf);
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
        q.emplace(dist[e.dst], e.dst);
      }
    }
  }
  return dist;
}
