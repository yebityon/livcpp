template<typename Monoid> class Dim2SegTree {
  using T = typename Monoid::value_type;

  Monoid m;

  std::vector<std::vector<T>> tree; // 1-indexed
  int sizeH = 1, sizeW = 1;

public:
  Dim2SegTree(const int h = 0, const int w = 0) {
    while (sizeH < h) sizeH *= 2;
    while (sizeW < w) sizeW *= 2;
    tree.assign(sizeH * 2, std::vector<T>(sizeW * 2, m.id()));
  }

  template<typename InputIterator> Dim2SegTree(InputIterator first, InputIterator last) {
    int h = std::distance(first, last), w = first->size();
    while (sizeH < h) sizeH *= 2;
    while (sizeW < w) sizeW *= 2;
    tree.assign(sizeH * 2, std::vector<T>(sizeW * 2, m.id()));
    int i = 0;
    for (auto iter = first; iter != last; iter++, i++) {
      int j = 0;
      for (auto jter = iter->begin(); jter != iter->end(); jter++, j++) tree[sizeH + i][sizeW + j] = *jter;
    }
    rep(i, sizeH) for (int j = sizeW - 1; j >= 1; j--) tree[sizeH + i][j] = m(tree[sizeH + i][j * 2], tree[sizeH + i][j * 2 + 1]);
    for (int i = sizeH - 1; i >= 1; i--) loop(j, 1, 2 * sizeW) tree[i][j] = m(tree[i * 2][j], tree[i * 2 + 1][j]);
  }

  T foldW(const int i, int l, int r) { // [l, r)
    T accl = m.id(), accr = m.id();
    for (l += sizeW, r += sizeW; l < r; l /= 2, r /= 2) {
      if (l & 1) accl = m(accl, tree[i][l++]);
      if (r & 1) accr = m(tree[i][--r], accr);
    }
    return m(accl, accr);
  }

  T fold(int t, int b, const int l, const int r) { // [t, b), [l, r)
    T acct = m.id(), accb = m.id();
    for (t += sizeH, b += sizeH; t < b; t /= 2, b /= 2) {
      if (t & 1) acct = m(acct, foldW(t++, l, r));
      if (b & 1) accb = m(foldW(--b, l, r), accb);
    }
    return m(acct, accb);
  }

  void update(int i, int j, const T &x) {
    tree[i += sizeH][j += sizeW] = x;
    for (int _j = j / 2; _j; _j /= 2) tree[i][_j] = m(tree[i][_j * 2], tree[i][_j * 2 + 1]);
    for (int _i = i / 2; _i; _i /= 2) {
      for (int _j = j; _j; _j /= 2) tree[_i][_j] = m(tree[_i * 2][_j], tree[_i * 2 + 1][_j]);
    }
  }

  const T &get(int i, int j) const { return tree[sizeH + i][sizeW + j]; }
};
