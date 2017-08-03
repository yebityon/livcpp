template<typename Group> class FenwickTree {
  using T = typename Group::value_type;

  Group g;
  std::vector<T> tree; // 1-indexed
  int size;

public:
  FenwickTree(const int &n = 0) : size(n), g() { tree.assign(size + 1, g.id()); }

  T fold(int i) { // [0, i)
    T acc = g.id();
    for (; i; i -= i & -i) acc = g(acc, tree[i]);
    return acc;
  }

  T fold(const int &l, const int &r) { return g(fold(r), g.inv(fold(l))); } // [l, r)

  void add(int i, const T &x) {
    for (i++; i <= size; i += i & -i) tree[i] = g(tree[i], x);
  }

  void update(int i, const T &a) { add(i + 1, a - fold(i + 1, i + 2)); }
};
