bool isBipartiteGraph(const Graph &g) {
  int n = g.size();
  std::vector<int> color(n, -1);
  color[0] = 0;
  std::queue<int> q;
  q.push(0);
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (auto &e : g[v]) {
      if (color[e.dst] == color[e.src]) return false;
      if (color[e.dst] == -1) {
        color[e.dst] = !color[e.src];
        q.push(e.dst);
      }
    }
  }
  return true;
}
