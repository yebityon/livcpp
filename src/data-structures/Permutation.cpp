class Permutation {
  vector<int> data;

public:
  Permutation(int n) {
    data.resize(n);
    iota(data.begin(), data.end(), 0);
  }

  bool next() { return next_permutation(data.begin(), data.end()); }

  int operator[](int i) { return data[i]; }
};
