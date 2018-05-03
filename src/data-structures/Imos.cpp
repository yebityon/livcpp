template<typename CommutativeGroup> class Imos {
  using T = typename CommutativeGroup::value_type;
  CommutativeGroup g;
  vector<T> v;

public:
  Imos(const int &n) : v(n, g.id()) {}

  void add(const int &l, const int &r, const int &x) { // [l, r)
    v[l] = g(v[l], x);
    if (r < v.size()) v[r] = g(v[r], g.inv(x));
  }

  vector<int> get() {
    int n = v.size();
    vector<int> a(n);
    a[0] = v[0];
    loop(i, 1, n) a[i] = g(a[i - 1], v[i]);
    return a;
  }
};
