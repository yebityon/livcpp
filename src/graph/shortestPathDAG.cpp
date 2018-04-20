template<int inf = numeric_limits<Weight>::max() / 8> Graph shortestPathDAG(const Graph &g, const int &source = 0, const int &destination = 0) {
  Graph rg = transposeGraph(g);
  vector<Weight> d = dijkstra<inf>(g, source).first, rd = dijkstra<inf>(rg, destination).first;
  Graph dag(g.size());
  for (auto &es : g) {
    for (auto &e : es) {
      if (d[e.src] + e.weight + rd[e.dst] == d[destination]) dag.addArc(e.src, e.dst, e.weight);
    }
  }
  return dag;
}
