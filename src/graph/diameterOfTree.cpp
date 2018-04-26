Edge diameterOfTree(const Graph &g) {
  Weight inf = numeric_limits<Weight>::max() / 8;
  int n = g.size();
  auto bfs = [&](int s) {
    vector<Weight> dist(n, inf);
    dist[s] = 0;
    queue<int> q;
    for (q.push(s); q.size(); q.pop()) {
      int u = q.front();
      for (auto &e : g[u]) {
        int v = e.dst;
        if (dist[v] == inf) {
          dist[v] = dist[u] + e.weight;
          q.push(v);
        }
      }
    }
    return dist;
  };
  vector<Weight> dist = bfs(0);
  int u = -1, v = -1;
  rep(i, n) if (dist[i] != inf && (u == -1 || dist[u] < dist[i])) u = i;
  dist = bfs(u);
  rep(i, n) if (dist[i] != inf && (v == -1 || dist[v] < dist[i])) v = i;
  Weight d = dist[v];
  if (u > v) swap(u, v);
  return Edge(u, v, d);
}
