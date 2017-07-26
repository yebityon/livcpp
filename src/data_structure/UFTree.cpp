class UFTree {
  std::vector<int> data, rank, _size;

public:
  UFTree(const int &n)
    : data(n), rank(n), _size(n, 1) {
    iota(all(data), 0);
  }

  int root(const int &x) {
    return data[x] == x ? x : data[x] = root(data[x]);
  }

  bool same(const int &a, const int &b) {
    return root(a) == root(b);
  }

  void unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (rank[a] < rank[b]) std::swap(a, b);
    data[b] = a;
    _size[a] += _size[b];
    if (rank[a] == rank[b]) rank[a]++;
  }

  int sizeOf(int x) {
    return _size[root(x)];
  }
};
