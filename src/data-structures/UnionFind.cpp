class UnionFind {
  vector<int> tree, rank, setSize;

public:
  UnionFind(const int &n) : tree(n), rank(n), setSize(n, 1) { iota(all(tree), 0); }

  int root(const int &x) { return tree[x] == x ? x : tree[x] = root(tree[x]); }

  bool same(const int &a, const int &b) { return root(a) == root(b); }

  bool unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return false;
    if (rank[a] < rank[b]) swap(a, b);
    tree[b] = a;
    setSize[a] += setSize[b];
    if (rank[a] == rank[b]) rank[a]++;
    return true;
  }

  int setSizeOf(const int &x) { return setSize[root(x)]; }

  int size() { return tree.size(); }
};
