template<typename CommutativeGroup> class Dim2RangeSum {
  using T = typename CommutativeGroup::value_type;

  CommutativeGroup g;

  std::vector<std::vector<T>> cache;

public:
  Dim2RangeSum(const std::vector<std::vector<T>> &raw) : cache(raw) {
    int h = cache.size(), w = cache[0].size();
    rep(i, h) loop(j, 1, w) cache[i][j] += cache[i][j - 1];
    loop(i, 1, h) rep(j, w) cache[i][j] += cache[i - 1][j];
  }

  T fold(const int t, const int b, const int l, const int r) { // [t, b), [l, r)
    T acc = g.id();
    if (b > 0 && r > 0) acc = g(acc, cache[b - 1][r - 1]);
    if (t > 0 && r > 0) acc = g(acc, g.inv(cache[t - 1][r - 1]));
    if (b > 0 && l > 0) acc = g(acc, g.inv(cache[b - 1][l - 1]));
    if (t > 0 && l > 0) acc = g(acc, cache[t - 1][l - 1]);
    return acc;
  }
};
