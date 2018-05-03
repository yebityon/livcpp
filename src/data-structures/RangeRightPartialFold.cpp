template<typename Magma> class RangeRightPartialFold {
  using T = typename Magma::value_type;
  Magma m;

  vector<T> cache;

public:
  RangeRightPartialFold(const vector<T> &raw) : cache(raw) {
    size_t n = cache.size();
    for (int i = n - 2; i >= 0; i--) cache[i] = m(cache[i], cache[i + 1]);
  }

  T fold(const int &l) { // (l, n]
    T acc = m.id();
    int n = cache.size();
    if (l < n - 1) acc = m(acc, cache[l + 1]);
    return acc;
  }
};
