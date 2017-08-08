template<typename T> class LazySegTree_RSQ_RAQ {
  int size = 1;
  std::vector<T> tree, lazy; // 1-indexed

  void flush(int i, int l, int r) {
    tree[i] = tree[i] + lazy[i] * (r - l);
    if (i < size) {
      lazy[i * 2] = lazy[i * 2] + lazy[i];
      lazy[i * 2 + 1] = lazy[i * 2 + 1] + lazy[i];
    }
    lazy[i] = 0;
  }

public:
  LazySegTree_RSQ_RAQ(const int &n) {
    while (size < n) size *= 2;
    tree.assign(size * 2, 0);
    lazy.assign(size * 2, 0);
  }

  // [l, r)
  void add(int l, int r, const int &x) { add(l, r, x, 1, 0, size); }
  void add(const int l, const int r, const int &x, int i, int a, int b) {
    flush(i, a, b);
    if (b <= l || r <= a) return;
    if (l <= a && b <= r) {
      lazy[i] = lazy[i] + x;
      flush(i, a, b);
      return;
    }
    add(l, r, x, i * 2, a, (a + b) / 2);
    add(l, r, x, i * 2 + 1, (a + b) / 2, b);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
  }

  // [l, r]
  T sum(int l, int r) { return sum(l, r, 1, 0, size); }
  T sum(int l, int r, int i, int a, int b) {
    flush(i, a, b);
    if (b <= l || r <= a) return 0;
    if (l <= a && b <= r) return tree[i];
    T lhs = sum(l, r, i * 2, a, (a + b) / 2);
    T rhs = sum(l, r, i * 2 + 1, (a + b) / 2, b);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
    return lhs + rhs;
  }
};
