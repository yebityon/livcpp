namespace livmath {
  // clang-format off
  constexpr double PI = acos(-1);
  constexpr bool odd(const int &n) { return n & 1; }
  constexpr bool even(const int &n) { return !odd(n); }
  constexpr int sgn(const int &x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }
  // clang-format on

  constexpr int gcd(int a, int b) {
    while (b) b ^= a ^= b ^= a %= b;
    return a;
  }

  constexpr int lcm(const int& a, const int& b) {
    return a * b / gcd(a, b);
  }

  constexpr bool isPrime(const int& n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
    }
    return true;
  }

  template<typename Integer = int>
  Integer factorial(const int& n) {
    static std::vector<Integer> dp(1, 1);
    if (dp.size() < n) dp.resize(n + 1);
    if (dp[n] != 0) return dp[n];
    dp[n] = factorial<Integer>(n - 1) * Integer(n);
    return dp[n];
  }

  constexpr int powint(int a, int b) {
    int c = 1;
    while (b) {
      if (odd(b)) c *= a;
      b >>= 1;
      a *= a;
    }
    return c;
  }

  std::vector<int> primeFactors(int n) {
    std::vector<int> v;
    int i = 2;
    while (i * i <= n) {
      if (n % i == 0) {
        v.push_back(i);
        n /= i;
      } else {
        i++;
      }
    }
    v.push_back(n);
    return v;
  }

  std::vector<int> divisors(int n) {
    std::vector<int> v;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        v.pb(i);
        if (n != 1 && i * i != n) v.push_back(n / i);
      }
    }
    std::sort(v.begin(), v.end());
    return v;
  }

  template<typename T>
  struct Monoid {
    T id;
    std::function<T(T, T)> op;
    Monoid(T e, std::function<T(T, T)> f)
      : id(e), op(f) {
    }
  };

  std::vector<int> eratosthenes(const int& n) {
    std::vector<int> v(n);
    std::iota(v.begin() + 2, v.end(), 2);
    for (int i = 2; i * i < n; i++) {
      if (v[i]) {
        for (int j = i * 2; j < n; j += i) {
          v[j] = false;
        }
      }
    }
    return v;
  }

  std::vector<int> genPrimes(const int& n) {
    std::vector<int> primes = eratosthenes(n);
    primes.erase(std::remove(all(primes), 0), primes.end());
    return primes;
  }

  // clang-format off
  template<int mod>
  struct modint {
    int v;
    modint(int a = 0) : v(((a % mod) + mod) % mod) { }
    modint operator+(const modint<mod>& b) const { return (v + b.v) % mod; }
    modint operator-(const modint<mod>& b) const { return (v - b.v + mod) % mod; }
    modint operator*(const modint<mod>& b) const { return (v * b.v) % mod; }
    modint operator/(const modint<mod>& b) const { return (v * b.inv().v) % mod; }
    modint<mod> inv() const { return pow(mod - 2); }
    modint<mod> pow(int t) const {
      modint e = v, c = 1;
      while (t) {
        if (odd(t)) c *= e;
        t >>= 1;
        e *= e;
      }
      return c;
    }
    explicit operator int() { return v; }
    friend bool operator==(const modint<mod>& a, const modint<mod>& b) { return a.v == b.v; }
    friend bool operator!=(const modint<mod>& a, const modint<mod>& b) { return a.v != b.v; }
    friend modint<mod>& operator+=(modint<mod>& a, const modint<mod>& b) { return a = a + b; }
    friend modint<mod>& operator-=(modint<mod>& a, const modint<mod>& b) { return a = a - b; }
    friend modint<mod>& operator*=(modint<mod>& a, const modint<mod>& b) { return a = a * b; }
    friend modint<mod>& operator/=(modint<mod>& a, const modint<mod>& b) { return a = a / b; }
    friend std::ostream& operator<<(std::ostream& os, const modint<mod>& a) { return os << a.v; }
    friend std::istream& operator>>(std::istream& is, modint<mod>& a) { int v; is >> v; a = modint<mod>(v); return is; }
  };
  // clang-format on
}
