Graph Graph::toRootedTree(int r = 0) {
  int n = g.size();
  Graph tree(n);
  std::vector<int> ord(n, -1);
  std::queue<int> q;
  q.push(r);
  int k = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (auto &e : g[u]) {
      int v = e.dst;
      if (ord[v] == -1) {
        ord[v] = k++;
        q.push(v);
        tree.addEdge(u, v, e.weight);
      }
    }
  }
  return tree;
}
