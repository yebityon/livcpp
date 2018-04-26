vector<int> tsort(const Graph &g) {
  int n = g.size(), k = 0;
  vector<int> ord, in(n);
  ord.reserve(n);
  for (auto &es : g) {
    for (auto &e : es) in[e.dst]++;
  }
  queue<int> q;
  rep(i, n) if (in[i] == 0) q.push(i);
  while (q.size()) {
    int v = q.front();
    q.pop();
    ord.emplace_back(v);
    for (auto &e : g[v])
      if (--in[e.dst] == 0) q.push(e.dst);
  }
  return ord.size() == n ? ord : vector<int>();
}
