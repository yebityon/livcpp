class BipartiteMatching {
  int n, m;
  FlowGraph g;

public:
  BipartiteMatching(const int &n, const int &m) : n(n), m(m), g(n + m + 2) {
    rep(i, n) g.addEdge(n + m, i);
    rep(i, m) g.addEdge(n + i, n + m + 1);
  }

  void add(const int &i, const int &j) { g.addEdge(i, n + j); }

  int maxMatching() { return dinic(g, n + m, n + m + 1); }
};
