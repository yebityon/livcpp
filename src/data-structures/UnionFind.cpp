class UnionFind {
  std::vector<int> tree, rank, _size;

public:
  UnionFind(const int n) : tree(n), rank(n), _size(n, 1) { iota(all(tree), 0); }

  int root(const int x) { return tree[x] == x ? x : tree[x] = root(tree[x]); }

  bool same(const int a, const int b) { return root(a) == root(b); }

  bool unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return false;
    if (rank[a] < rank[b]) std::swap(a, b);
    tree[b] = a;
    _size[a] += _size[b];
    if (rank[a] == rank[b]) rank[a]++;
    return true;
  }

  int sizeOf(int x) { return _size[root(x)]; }

  int size() { return tree.size(); }
};
