namespace livbasic_cpp11 {
  // clang-format off
  typedef std::pair<int, int> pii;
  typedef std::vector<int> vi;
  typedef std::vector<double> vd;
  typedef std::vector<char> vc;
  typedef std::vector<bool> vb;
  typedef std::vector<std::string> vs;
  typedef std::vector<pii> vpii;
  typedef std::vector<vi> vvi;
  typedef std::vector<vb> vvb;
  typedef std::vector<vpii> vvpii;
  const int INF   = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
  const int MOD   = 1000000007;
  const double PI = acos(-1);
  template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
  template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
  // clang-format on
}
