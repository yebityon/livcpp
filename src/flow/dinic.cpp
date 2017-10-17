// Change it to 'FlowGraph &g' when you need a residual network
template<Flow inf = std::numeric_limits<Flow>::max() / 8> Flow dinic(FlowGraph g, const int source, const int sink) {
  std::vector<int> level(g.size()), iter(g.size());
  auto bfs = [&] {
    std::fill(level.begin(), level.end(), -1);
    std::queue<int> q;
    level[source] = 0;
    q.push(source);
    while (q.size()) {
      int v = q.front();
      q.pop();
      for (auto &e : g[v]) {
        if (level[e.dst] >= 0 || e.cap <= 0) continue;
        level[e.dst] = level[v] + 1;
        q.push(e.dst);
      }
    }
    return level[sink] >= 0;
  };
  std::function<Flow(int, Flow)> dfs = [&](int v, Flow f) -> Flow {
    if (v == sink) return f;
    Flow s = 0;
    for (; iter[v] < g[v].size(); iter[v]++) {
      auto &e = g[v][iter[v]];
      if (level[v] >= level[e.dst] || e.cap <= 0) continue;
      Flow d = dfs(e.dst, min(f, e.cap));
      e.cap -= d;
      g[e.dst][e.rev].cap += d;
      s += d;
      f -= d;
      if (f == 0) break;
    }
    return s;
  };
  Flow s = 0;
  while (bfs()) {
    std::fill(iter.begin(), iter.end(), 0);
    s += dfs(source, inf);
  }
  return s;
}
