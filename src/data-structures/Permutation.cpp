class Permutation {
  std::vector<int> data;

public:
  Permutation(int n) {
    data.resize(n);
    std::iota(data.begin(), data.end(), 0);
  }

  bool next() { return std::next_permutation(data.begin(), data.end()); }

  int operator[](int i) { return data[i]; }
};
