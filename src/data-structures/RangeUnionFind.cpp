class RangeUnionFind {
  LazySegTree<RMQ_RUQ_Trait<int>> lst;

public:
  RangeUnionFind(const int n) {
    vector<int> ufInit(n);
    iota(all(ufInit), 0);
    lst = LazySegTree<RMQ_RUQ_Trait<int>>(all(ufInit));
  }

  int root(int x) {
    int a = lst.fold(x, x + 1);
    if (a == x) return x;
    int b = root(a);
    lst.act(x, x + 1, {true, b});
    return b;
  }

  bool same(const int a, const int b) { return root(a) == root(b); }

  void unite(int a, int b) { // unite [a, b)
    int r = root(a);
    if (a == b) return;
    lst.act(a, b, {true, r});
  }
};
