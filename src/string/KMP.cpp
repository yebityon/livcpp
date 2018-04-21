// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int n) { return n & 1; }
constexpr bool even(const int n) { return ~n & 1; }
template<typename T = int> T in() { T x; cin >> x; return x; }
template<typename T = int> T in(T &&x) { T z(forward<T>(x)); cin >> z; return z; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> istream &operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : "\n"); return os; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : " "); return os; }
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << ' ' << p.second; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
// clang-format on

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

main {
  string t, p;
  cin >> t >> p;
  KMP kmp(p);
  for (auto i : kmp.findAll(t)) cout << i << endl;
}
