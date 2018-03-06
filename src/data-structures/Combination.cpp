class Combination {
  std::vector<int> data;

public:
  Combination(int n, int r) {
    data.resize(n);
    std::fill(data.end() - (n - r), data.end(), 1);
  }

  bool next() { return std::next_permutation(data.begin(), data.end()); }

  int operator[](int i) { return !data[i]; }
};
