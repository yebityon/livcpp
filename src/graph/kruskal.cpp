template<typename UnionFind> std::pair<Weight, Edges> kruskal(const Graph &g) {
  UnionFind uf(g.size());
  Edges es;
  for (auto &adj : g) {
    for (auto &e : adj) es.emplace_back(e);
  }
  std::sort(es.begin(), es.end(), [](const Edge &e, const Edge &f) { return e.weight < f.weight; });
  Weight total = 0;
  Edges tree;
  for (auto &e : es) {
    if (!uf.same(e.src, e.dst)) {
      tree.push_back(e);
      total += e.weight;
      uf.unite(e.src, e.dst);
    }
  }
  return {total, tree};
}
