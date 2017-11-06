std::vector<int> zaatsu(const std::vector<int> &v) {
  int n = v.size(), k = 0;
  std::map<int, int> m;
  std::vector<int> w(all(v));
  std::sort(all(w));
  rep(i, n) if (!m.count(w[i])) m[w[i]] = k++;
  rep(i, n) w[i] = m[v[i]];
  return w;
}
