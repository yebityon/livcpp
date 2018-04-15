template<typename CommutativeGroup> class WeightedUnionFind {
  using T = typename CommutativeGroup::value_type;
  CommutativeGroup g;

  vector<int> tree, rank;
  vector<T> diffWeight;

public:
  WeightedUnionFind(const int &n) : tree(n), rank(n), diffWeight(n, g.id()) { iota(all(tree), 0); }

  int root(const int &x) {
    if (tree[x] == x) {
      return x;
    } else {
      int r = root(tree[x]);
      diffWeight[x] += diffWeight[tree[x]];
      return tree[x] = r;
    }
  }

  T weight(const int &x) {
    root(x);
    return diffWeight[x];
  }

  bool same(const int &a, const int &b) { return root(a) == root(b); }

  bool unite(int a, int b, T w) {
    w = g(w, g(weight(a), g.inv(weight(b))));
    a = root(a), b = root(b);
    if (a == b) return false;
    if (rank[a] < rank[b]) swap(a, b), w = g.inv(w);
    tree[b] = a;
    diffWeight[b] = w;
    if (rank[a] == rank[b]) ++rank[a];
    return true;
  }

  T diff(int x, int y) { return g(weight(y), g.inv(weight(x))); }
};
