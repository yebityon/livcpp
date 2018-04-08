class RollingHash {
  int bases[2] = {1007, 1009}, mods[2] = {1000000009, 1000000007};
  vector<int> mul[2], hash[2];

public:
  using hash_type = pair<int, int>;

  RollingHash(const string &s) {
    int n = s.size();
    rep(i, 2) {
      hash[i] = vector<int>(n + 1, 0);
      mul[i] = vector<int>(n + 1, 1);
      rep(j, n) {
        hash[i][j + 1] = (hash[i][j] * bases[i] + s[j]) % mods[i];
        mul[i][j + 1] = (mul[i][j] * bases[i]) % mods[i];
      }
    }
  }

  hash_type get(int l, int r) { // [l, r)
    int &&h0 = ((hash[0][r] - hash[0][l] * mul[0][r - l]) % mods[0] + mods[0]) % mods[0];
    int &&h1 = ((hash[1][r] - hash[1][l] * mul[1][r - l]) % mods[1] + mods[1]) % mods[1];
    return {h0, h1};
  }
};
