class RangeUnionFind {
  RangeUpdateSegTree<int> rust;

public:
  RangeUnionFind(const int n) {
    vector<int> ufInit(n);
    iota(all(ufInit), 0);
    rust = RangeUpdateSegTree<int>(all(ufInit));
  }

  int root(int x) {
    int a = rust[x];
    if (a == x) return x;
    int b = root(a);
    rust.update(x, x + 1, b);
    return b;
  }

  bool same(const int a, const int b) { return root(a) == root(b); }

  void unite(int a, int b) { // unite [a, b)
    int r = root(a);
    if (a == b) return;
    rust.update(a, b, r);
  }
};
