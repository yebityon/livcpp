class LCA {
  int n = 0;
  int log2_n = 0;
  std::vector<std::vector<int>> _parent;
  std::vector<int> _depth;

public:
  LCA() {}

  LCA(const Graph &g, int root = 0) : n(g.size()), log2_n(log2(n) + 1), _parent(log2_n, std::vector<int>(n)), _depth(n) {
    dfs(g, root, -1, 0);
    rep(k, log2_n - 1) rep(v, g.size()) _parent[k + 1][v] = _parent[k][v] < 0 ? -1 : _parent[k][_parent[k][v]];
  }

  void dfs(const Graph &g, int v, int p, int d) {
    _parent[0][v] = p;
    _depth[v] = d;
    for (auto &e : g[v]) {
      if (e.dst != p) dfs(g, e.dst, v, d + 1);
    }
  }

  int get(int u, int v) {
    if (_depth[u] > _depth[v]) std::swap(u, v);
    rep(k, log2_n) if ((_depth[v] - _depth[u]) >> k & 1) v = _parent[k][v];
    if (u == v) return u;
    for (int k = log2_n - 1; k >= 0; k--) {
      if (_parent[k][u] != _parent[k][v]) {
        u = _parent[k][u];
        v = _parent[k][v];
      }
    }
    return _parent[0][u];
  }

  int depth(int v) { return _depth[v]; }
};
