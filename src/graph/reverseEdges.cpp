Graph reverseEdges(const Graph &g) {
  Graph h(g.size());
  for (auto &es : g) {
    for (auto &e : es) h.addArc(e.dst, e.src, e.weight);
  }
  return h;
}
