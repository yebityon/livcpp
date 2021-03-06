class SCC {
public:
  vector<int> root;
  Graph g;

  SCC(const Graph &g) : g(g) {
    int n = g.size();
    vector<int> ord(n);
    {
      int k = n - 1;
      vector<int> visited(n), ordered(n);
      for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        stack<int> stk;
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
    root = vector<int>(n, -1);
    int k = 0;
    for (int u : ord) {
      if (root[u] >= 0) continue;
      stack<int> stk;
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
  }

  Graph makeDAG() {
    Graph h(g.size());
    for (auto &es : g) {
      for (auto &e : es) {
        if (root[e.src] == root[e.dst]) continue;
        h.addArc(root[e.src], root[e.dst]);
      }
    }
    return h;
  }
};