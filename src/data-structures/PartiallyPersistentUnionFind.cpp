class PartiallyPersisitentUnionFind {
  vector<int> data, endTime;

public:
  int currentTime = 0;

  PartiallyPersisitentUnionFind(const int &n) : data(n, -1), endTime(n, std::numeric_limits<int>::max()) {}

  bool unite(int a, int b) {
    a = root(currentTime, a);
    b = root(currentTime, b);
    currentTime++;
    if (a == b) return false;
    if (data[a] < data[b]) std::swap(a, b);
    data[b] += data[a];
    data[a] = b;
    endTime[a] = currentTime;
    return true;
  }

  int root(const int &t, const int &x) { return t < endTime[x] ? x : root(t, data[x]); }

  bool same(const int &t, const int &a, const int &b) { return root(t, a) == root(t, b); }

  int sizeOf(const int &x) { return -data[x]; }

  int size() { return data.size(); }
};
