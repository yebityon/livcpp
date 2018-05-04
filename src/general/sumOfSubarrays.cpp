template<typename Integral = int> Integral sumOfSubarrays(const vector<Integral> &v) {
  size_t n = v.size();
  Integral s = 0;
  rep(i, n) s += v[i] * (i + 1) * (n - i);
  return s;
}
