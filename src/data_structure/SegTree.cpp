template<typename Monoid> class SegTree {
  using T = typename Monoid::value_type;

  Monoid m;
  std::vector<T> data;
  int size = 1;

public:
  SegTree(const int &n = 0) {
    m = Monoid();
    while (size < n) size *= 2;
    data.assign(size * 2, m.id());
  }

  template<typename InputIterator> SegTree(InputIterator first, InputIterator last) {
    m = Monoid();
    int n = std::distance(first, last);
    while (size < n) size *= 2;
    data.resize(size * 2, m.id());
    std::copy(first, last, data.begin() + size);
    for (int i = size - 1; i >= 1; --i) data[i] = m(data[i * 2], data[i * 2 + 1]);
  }

  T fold(int l, int r) const { // [l, r)
    T acc = m.id();
    for (l += size, r += size; l < r; l /= 2, r /= 2) {
      if (l & 1) acc = m(acc, data[l++]);
      if (r & 1) acc = m(acc, data[--r]);
    }
    return acc;
  }

  void update(int i, const T &x) {
    data[i += size] = x;
    while (i /= 2) data[i] = m(data[i * 2], data[i * 2 + 1]);
  }

  const T &operator[](int i) const { return data[i + size]; }
};
