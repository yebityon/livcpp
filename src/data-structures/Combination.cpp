class Combination {
  int r;
  vector<int> data;

public:
  Combination(int n, int r) : r(r) {
    data.resize(n);
    fill(data.end() - (n - r), data.end(), 1);
  }

  bool next() { return next_permutation(data.begin(), data.end()); }

  vector<int> get() {
    vector<int> v;
    v.reserve(r);
    rep(i, data.size()) if ((*this)[i]) v.emplace_back(i);
    return v;
  }

  bool operator[](int i) { return !data[i]; }
};
