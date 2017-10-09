std::vector<int> kosaraju(const Graph &g) {
  int n = g.size();
  std::vector<int> ord(n);
  {
    int k = n - 1;
    std::vector<int> visited(n), ordered(n);
    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;
      std::stack<int> stk;
      stk.push(i);
      while (stk.size()) {
        int v = stk.top();
        visited[v] = true;
        bool pushed = false;
        for (auto &e : g[v]) {
          if (!visited[e.dst]) {
            stk.push(e.dst);
            pushed = true;
          }
        }
        if (pushed) continue;
        if (!ordered[v]) {
          ordered[v] = true;
          ord[k--] = v;
        }
        stk.pop();
      }
    }
  }
  Graph rg(n);
  for (auto &es : g) {
    for (auto &e : es) rg.addArc(e.dst, e.src, e.weight);
  }
  std::vector<int> root(n, -1);
  int k = 0;
  for (int u : ord) {
    if (root[u] >= 0) continue;
    std::stack<int> stk;
    stk.push(u);
    while (stk.size()) {
      int v = stk.top();
      stk.pop();
      root[v] = k;
      for (auto &e : rg[v]) {
        if (root[e.dst] == -1) stk.push(e.dst);
      }
    }
    ++k;
  }
  return root;
}
