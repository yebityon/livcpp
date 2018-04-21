class KMP {
  int m;
  string pattern;
  vector<int> fail;

public:
  KMP(const string &pattern) : m(pattern.size()), pattern(pattern), fail(m + 1) {
    int j = fail[0] = -1;
    for (int i = 1; i <= m; ++i) {
      while (j >= 0 && pattern[j] != pattern[i - 1]) j = fail[j];
      fail[i] = ++j;
    }
  }

  vector<int> findAll(const string &target) { // matched substrs positions (0-indexed)
    int n = target.size();
    vector<int> indices;
    for (int i = 0, j = 0; i < n;) {
      if (target[i] == pattern[j]) {
        i++, j++;
      } else if (j == 0) {
        i++;
      } else {
        j = fail[j];
      }
      if (j == m) {
        indices.emplace_back(i - m);
        j = fail[j];
      }
    }
    return indices;
  }
};
