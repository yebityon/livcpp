template<typename T>
class SegTree {
private:
  vector<T> data;
  Monoid<T> monoid;
  int size = 1;

public:
  SegTree(const int &n, const Monoid<T> &m = Monoid<int>(INF, [](int a, int b) { return min(a, b); }))
    : monoid(m) {
    while (size < n) size *= 2;
    data = vector<T>(2 * size, monoid.id);
  }

  void update(int i, const T &x) {
    i += size;
    data[i]                = x;
    while (i /= 2) data[i] = monoid.op(data[i * 2], data[i * 2 + 1]);
  }

  // fold [a, b) by monoid.op
  T fold(const int &a, const int &b, const int &k = 1, const int &l = 0, int r = -1) {
    if (r == -1) r = size;
    if (r <= a || b <= l) return monoid.id;
    if (a <= l && r <= b) return data[k];
    return monoid.op(fold(a, b, k * 2, l, (l + r) / 2),
                     fold(a, b, k * 2 + 1, (l + r) / 2, r));
  }

  const T &operator[](const int &i) const {
    return data[i + size];
  }
};
