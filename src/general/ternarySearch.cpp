template<int precision = 400, typename F> double ternarySearch(const double &l, const double &r, const F &f) { return ternarySearch<precision>(l, r, f, less<double>()); }
template<int precision = 400, typename F, typename C> double ternarySearch(double l, double r, const F &f, const C &c) {
  rep(i, precision) {
    double m1 = (l * 2.0 + r) / 3.0, m2 = (l + r * 2.0) / 3.0;
    if (c(f(m1), f(m2))) {
      r = m2;
    } else {
      l = m1;
    }
  }
  return (l + r) / 2.0;
}
