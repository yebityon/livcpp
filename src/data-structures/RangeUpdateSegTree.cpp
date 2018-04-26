template<typename T> class RangeUpdateSegTree {
  int size = 1;
  size_t time = 1;
  vector<pair<size_t, T>> tree; // 1-indexed

public:
  RangeUpdateSegTree(const int n = 0) {
    while (size < n) size *= 2;
    tree.resize(size * 2);
  }

  RangeUpdateSegTree(const int n, const T &x) {
    while (size < n) size *= 2;
    tree.assign(size * 2, {0, x});
  }

  template<typename InputIterator> RangeUpdateSegTree(InputIterator first, InputIterator last) {
    size_t n = distance(first, last);
    while (size < n) size *= 2;
    tree.resize(size * 2);

    auto result = tree.begin() + size;
    while (first != last) {
      result->second = *first;
      ++result, ++first;
    }
  }

  // [l, r)
  void update(int l, int r, const T &x) {
    for (l += size, r += size; l < r; l /= 2, r /= 2) {
      if (l & 1) tree[l++] = {time, x};
      if (r & 1) tree[--r] = {time, x};
    }
    time++;
  }

  const T operator[](int i) const {
    pair<size_t, T> p = tree[i += size];
    while (i /= 2) p = max(p, tree[i]);
    return p.second;
  }
};
