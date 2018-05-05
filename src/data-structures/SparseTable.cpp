template<typename IdempotentCommutativeMonoid> class SparseTable {
  using T = typename IdempotentCommutativeMonoid::value_type;
  IdempotentCommutativeMonoid m;
  vector<int> logTable;
  vector<vector<T>> table;

public:
  template<typename InputIterator> SparseTable(InputIterator first, InputIterator last) {
    int n = distance(first, last);
    logTable.resize(n + 1);
    for (int i = 2; i <= n; i++) logTable[i] = logTable[i >> 1] + 1;
    int k = logTable[n];
    table.resize(k + 1, vector<T>(n));
    copy(first, last, table[0].begin());
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j + (1 << i) <= n; j++) {
        int left = table[i - 1][j], right = table[i - 1][j + (1 << (i - 1))];
        table[i][j] = m(left, right);
      }
    }
  }

  T fold(int l, int r) { // [l, r)
    if (l == r) return m.id();
    int i = logTable[r - l];
    return m(table[i][l], table[i][r - (1 << i)]);
  }
};
