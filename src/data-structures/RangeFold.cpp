template<typename CommutativeGroup> class RangeFold {
  using T = typename CommutativeGroup::value_type;

  CommutativeGroup g;

  std::vector<T> cache;

public:
  RangeFold(const std::vector<T> &raw) : cache(raw) {
    size_t w = cache.size();
    loop(i, 1, w) cache[i] = g(cache[i], cache[i - 1]);
  }

  T fold(const int l, const int r) { // [l, r)
    T acc = g.id();
    if (r > 0) acc = g(acc, cache[r - 1]);
    if (l > 0) acc = g(acc, g.inv(cache[l - 1]));
    return acc;
  }
};
