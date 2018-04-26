vector<int> eratosthenes(const int n) {
  vector<int> v(n);
  iota(v.begin() + 2, v.end(), 2);
  for (int i = 2; i * i < n; i++) {
    if (v[i]) {
      for (int j = i * 2; j < n; j += i) v[j] = false;
    }
  }
  return v;
}
