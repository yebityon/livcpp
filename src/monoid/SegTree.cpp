template<typename Monoid> class SegTree {
  using T = typename Monoid::value_type;

  Monoid m;
  std::vector<T> tree; // 1-indexed
  int size = 1;

  void _update(int i) { tree[i] = m(tree[i * 2], tree[i * 2 + 1]); }

public:
  SegTree(const int &n = 0) {
    m = Monoid();
    while (size < n) size *= 2;
    tree.assign(size * 2, m.id());
  }

  template<typename InputIterator> SegTree(InputIterator first, InputIterator last) {
    int n = std::distance(first, last);
    m = Monoid();
    while (size < n) size *= 2;
    tree.resize(size * 2, m.id());
    std::copy(first, last, tree.begin() + size);
    for (int i = size - 1; i >= 1; i--) _update(i);
  }

  T fold(int l, int r) const { // [l, r)
    T acc = m.id();
    for (l += size, r += size; l < r; l /= 2, r /= 2) {
      if (l & 1) acc = m(acc, tree[l++]);
      if (r & 1) acc = m(acc, tree[--r]);
    }
    return acc;
  }

  void update(int i, const T &x) {
    tree[i += size] = x;
    while (i /= 2) _update(i);
  }

  const T &operator[](int i) const { return tree[i + size]; }
};
