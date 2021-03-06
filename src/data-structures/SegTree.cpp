template<typename Monoid> class SegTree {
  using T = typename Monoid::value_type;

  Monoid m;
  vector<T> tree; // 1-indexed
  int size = 1;

public:
  SegTree(const int n = 0) {
    while (size < n) size *= 2;
    tree.assign(size * 2, m.id());
  }

  SegTree(const int n, const T &x) {
    while (size < n) size *= 2;
    tree.assign(size * 2, x);
    for (int i = size - 1; i >= 1; i--) tree[i] = m(tree[i * 2], tree[i * 2 + 1]);
  }

  template<typename InputIterator> SegTree(InputIterator first, InputIterator last) {
    int n = distance(first, last);
    while (size < n) size *= 2;
    tree.resize(size * 2, m.id());
    copy(first, last, tree.begin() + size);
    for (int i = size - 1; i >= 1; i--) tree[i] = m(tree[i * 2], tree[i * 2 + 1]);
  }

  T fold(int l, int r) { // [l, r)
    T accl = m.id(), accr = m.id();
    for (l += size, r += size; l < r; l /= 2, r /= 2) {
      if (l & 1) accl = m(accl, tree[l++]);
      if (r & 1) accr = m(tree[--r], accr);
    }
    return m(accl, accr);
  }

  void update(int i, const T &x) {
    tree[i += size] = x;
    while (i /= 2) tree[i] = m(tree[i * 2], tree[i * 2 + 1]);
  }

  const T &operator[](int i) const { return tree[i + size]; }
};
