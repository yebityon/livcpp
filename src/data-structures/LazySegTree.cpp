template<typename LSTTrait> class LazySegTree {
  using FoldMonoid = typename LSTTrait::FoldMonoid;
  using ActionMonoid = typename LSTTrait::ActionMonoid;
  using T = typename FoldMonoid::value_type;
  using Q = typename ActionMonoid::value_type;

  LSTTrait lstTrait; // apply :: (T, Q) -> T
  FoldMonoid foldM;
  ActionMonoid actionM;
  int size = 1;
  std::vector<T> tree; // 1-indexed
  std::vector<Q> lazy; // 1-indexed

  void flush(int i, int l, int r) {
    tree[i] = lstTrait.apply(tree[i], powm<ActionMonoid>(lazy[i], r - l));
    if (i < size) {
      lazy[i * 2] = actionM(lazy[i * 2], lazy[i]);
      lazy[i * 2 + 1] = actionM(lazy[i * 2 + 1], lazy[i]);
    }
    lazy[i] = actionM.id();
  }

public:
  LazySegTree(const int n = 0) {
    while (size < n) size *= 2;
    tree.assign(size * 2, foldM.id());
    lazy.assign(size * 2, actionM.id());
  }

  LazySegTree(const int n, const T &x) {
    while (size < n) size *= 2;
    tree.assign(size * 2, x);
    lazy.assign(size * 2, actionM.id());
    for (int i = size - 1; i >= 1; i--) tree[i] = foldM(tree[i * 2], tree[i * 2 + 1]);
  }

  template<typename InputIterator> LazySegTree(InputIterator first, InputIterator last) {
    int n = std::distance(first, last);
    while (size < n) size *= 2;
    tree.resize(size * 2, foldM.id());
    lazy.resize(size * 2, actionM.id());
    std::copy(first, last, tree.begin() + size);
    for (int i = size - 1; i >= 1; i--) tree[i] = foldM(tree[i * 2], tree[i * 2 + 1]);
  }

  // [l, r)
  void act(int l, int r, const Q x) { act(l, r, x, 1, 0, size); }
  void act(const int l, const int r, const Q x, int i, int a, int b) {
    flush(i, a, b);
    if (b <= l || r <= a) return;
    if (l <= a && b <= r) {
      lazy[i] = actionM(lazy[i], x);
      flush(i, a, b);
      return;
    }
    act(l, r, x, i * 2, a, (a + b) / 2);
    act(l, r, x, i * 2 + 1, (a + b) / 2, b);
    tree[i] = foldM(tree[i * 2], tree[i * 2 + 1]);
  }

  // [l, r)
  T fold(int l, int r) { return fold(l, r, 1, 0, size); }
  T fold(int l, int r, int i, int a, int b) {
    flush(i, a, b);
    if (b <= l || r <= a) return foldM.id();
    if (l <= a && b <= r) return tree[i];
    T lhs = fold(l, r, i * 2, a, (a + b) / 2);
    T rhs = fold(l, r, i * 2 + 1, (a + b) / 2, b);
    tree[i] = foldM(tree[i * 2], tree[i * 2 + 1]);
    return foldM(lhs, rhs);
  }
};
