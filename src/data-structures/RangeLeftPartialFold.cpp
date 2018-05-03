template<typename Magma> class RangeLeftPartialFold {
  using T = typename Magma::value_type;
  Magma m;

  vector<T> cache;

public:
  RangeLeftPartialFold(const vector<T> &raw) : cache(raw) {
    size_t n = cache.size();
    for (int i = 1; i < n; i++) cache[i] = m(cache[i], cache[i - 1]);
  }

  T fold(const int &r) { // [0, r)
    T acc = m.id();
    if (r > 0) acc = m(acc, cache[r - 1]);
    return acc;
  }
};
