Graph toRootedTree(const Graph &g, const int root = 0) {
  int n = g.size();
  Graph tree(n);
  vector<int> ord(n, -1);
  queue<int> q;
  q.push(root);
  int k = 0;
  ord[root] = k++;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (auto &e : g[u]) {
      int v = e.dst;
      if (ord[v] == -1) {
        ord[v] = k++;
        q.push(v);
        tree.addArc(u, v, e.weight);
      }
    }
  }
  return tree;
}
