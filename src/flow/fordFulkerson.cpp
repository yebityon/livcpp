template<int inf = std::numeric_limits<Flow>::max() / 8> Flow fordFulkerson(FlowGraph g, const int source, const int sink) {
  std::vector<int> used(g.size());
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
    std::fill(used.begin(), used.end(), false);
    Flow f = dfs(source, sink, inf);
    if (f == 0) return s;
    s += f;
  }
}
