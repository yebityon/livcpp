template<typename Integral = int> Integral nHr(const int n, const int r) { return nCr<Integral>(n + r - 1, r); }
