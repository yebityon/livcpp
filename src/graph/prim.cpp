std::pair<Weight, Edges> prim(const Graph &g, const int &root = 0) {
  struct comp {
    bool operator()(const Edge &e, const Edge &f) const { return e.weight > f.weight; }
  };
  Edges tree;
  Weight total = 0;
  std::vector<int> vs(g.size());
  std::priority_queue<Edge, std::vector<Edge>, comp> q;
  q.emplace(-1, root, 0);
  while (q.size()) {
    Edge e = q.top();
    q.pop();
    if (vs[e.dst]) continue;
    vs[e.dst] = true;
    total += e.weight;
    if (e.src != -1) tree.emplace_back(e);
    for (auto &f : g[e.dst]) {
      if (!vs[f.dst]) q.emplace(f);
    }
  }
  return {total, tree};
}
