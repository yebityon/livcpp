/* Find the maximum x∈[low, up) such that f(x) is true
    ---*     (true)
        ---- (false)
*/
template<int precision = 100, typename F> double binarySearchD(double low, const double &up, const F &f) {
  double d = up - low;
  rep(i, precision) {
    d /= 2;
    if (f(low + d)) low += d;
  }
  return low;
}
