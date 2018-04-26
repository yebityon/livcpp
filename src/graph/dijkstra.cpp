template<int inf = numeric_limits<Weight>::max() / 8> pair<vector<Weight>, vector<int>> dijkstra(const Graph &g, const int src) {
  using state = pair<Weight, int>;
  priority_queue<state, vector<state>, greater<state>> q;
  vector<Weight> dist(g.size(), inf);
  vector<int> via(g.size());
  dist[src] = 0;
  q.emplace(0, src);
  while (q.size()) {
    Weight d;
    int v;
    tie(d, v) = q.top();
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
