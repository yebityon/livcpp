namespace livbasic {
  // clang-format off
  using pii   = std::pair<int, int>;
  using vi    = std::vector<int>;
  using vd    = std::vector<double>;
  using vc    = std::vector<char>;
  using vb    = std::vector<bool>;
  using vs    = std::vector<std::string>;
  using vpii  = std::vector<pii>;
  using vvi   = std::vector<vi>;
  using vvb   = std::vector<vb>;
  using vvpii = std::vector<vpii>;
  template<typename A> using fn = std::function<A>;
  constexpr int INF   = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
  constexpr int MOD   = 1000000007;
  constexpr double PI = acos(-1);
  template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
  template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
  // clang-format on
}
