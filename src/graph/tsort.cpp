std::vector<int> tsort(const Graph &g) {
  int n = g.size(), k = 0;
  std::vector<int> ord(n), in(n);
  for (auto &es : g) {
    for (auto &e : es) in[e.dst]++;
  }
  std::queue<int> q;
  rep(i, n) if (in[i] == 0) q.push(i);
  while (q.size()) {
    int v = q.front();
    q.pop();
    ord[k++] = v;
    for (auto &e : g[v])
      if (--in[e.dst] == 0) q.push(e.dst);
  }
  return *std::max_element(in.begin(), in.end()) == 0 ? ord : std::vector<int>();
}
