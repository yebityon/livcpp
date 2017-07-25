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
