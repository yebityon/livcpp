vector<int> compressByOrd(const vector<int> &v) {
  int n = v.size(), k = 0;
  map<int, int> m;
  vector<int> w(all(v));
  sort(all(w));
  rep(i, n) if (!m.count(w[i])) m[w[i]] = k++;
  rep(i, n) w[i] = m[v[i]];
  return w;
}
