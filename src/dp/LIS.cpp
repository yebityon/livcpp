template<typename T> vector<T> LIS(const vector<T> &a) {
  int n = a.size();
  if (n == 0) return vector<T>();
  vector<T> lis;
  vector<int> p(a.size());
  int u, v;
  lis.emplace_back(0);
  loop(i, 1, n) {
    if (a[lis.back()] < a[i]) {
      p[i] = lis.back();
      lis.emplace_back(i);
      continue;
    }
    for (u = 0, v = lis.size() - 1; u < v;) {
      int c = (u + v) / 2;
      if (a[lis[c]] < a[i]) {
        u = c + 1;
      } else {
        v = c;
      }
    }
    if (a[i] < a[lis[u]]) {
      if (u > 0) p[i] = lis[u - 1];
      lis[u] = i;
    }
  }
  for (int u = lis.size(), v = lis.back(); u--; v = p[v]) lis[u] = a[v];
  return lis;
}
