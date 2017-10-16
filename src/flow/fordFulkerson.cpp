template<int inf = std::numeric_limits<Flow>::max() / 8> Flow fordFulkerson(FlowGraph g, const int source, const int sink) {
  std::vector<int> used;
  std::function<int(int, int, int)> dfs = [&](int s, int t, int f) -> int {
    if (s == t) return f;
    used[s] = true;
    for (auto &e : g[s]) {
      if (used[e.dst] || e.cap <= 0) continue;
      int d = dfs(e.dst, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        g[e.dst][e.rev].cap += d;
        return d;
      }
    }
    return 0;
  };
  Flow s = 0;
  for (;;) {
    used.assign(g.size(), false);
    Flow f = dfs(source, sink, inf);
    if (f == 0) return s;
    s += f;
  }
}
