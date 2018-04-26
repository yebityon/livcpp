template<typename CommutativeMonoid> class HomUnionFind {
  using T = typename CommutativeMonoid::value_type;
  CommutativeMonoid m;
  int n;
  vector<int> tree, rank, setSize;
  vector<T> mapped;

public:
  HomUnionFind(const int &n) //
      : n(n), tree(n), rank(n), setSize(n, 1), mapped(n, m.id()) {
    iota(all(tree), 0);
  }

  template<typename InputIterator>
  HomUnionFind(InputIterator first, InputIterator last) //
      : n(distance(first, last)), tree(n), rank(n), setSize(n, 1), mapped(first, last) {
    iota(all(tree), 0);
  }

  int root(const int &x) { return tree[x] == x ? x : tree[x] = root(tree[x]); }

  bool same(const int &a, const int &b) { return root(a) == root(b); }

  bool unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return false;
    if (rank[a] < rank[b]) swap(a, b);
    tree[b] = a;
    setSize[a] += setSize[b];
    mapped[a] = m(mapped[a], mapped[b]);

    if (rank[a] == rank[b]) rank[a]++;
    return true;
  }

  int setSizeOf(const int &x) { return setSize[root(x)]; }

  T mappedValue(const int &x) { return mapped[root(x)]; }

  int size() { return n; }
};
