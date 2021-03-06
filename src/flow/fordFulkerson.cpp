// Change it to 'FlowGraph &g' when you need a residual network
template<Flow inf = numeric_limits<Flow>::max() / 8> Flow fordFulkerson(FlowGraph g, const int source, const int sink) {
  vector<int> used(g.size());
  function<Flow(int, Flow)> dfs = [&](int v, Flow f) -> Flow {
    if (v == sink) return f;
    used[v] = true;
    for (auto &e : g[v]) {
      if (used[e.dst] || e.cap <= 0) continue;
      Flow d = dfs(e.dst, min(f, e.cap));
      if (d <= 0) continue;
      e.cap -= d;
      g[e.dst][e.rev].cap += d;
      return d;
    }
    return 0;
  };
  Flow s, f;
  for (s = 0; (f = dfs(source, inf)); s += f) fill(used.begin(), used.end(), false);
  return s;
}
