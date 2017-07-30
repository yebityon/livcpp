constexpr int powint(int a, int b) {
  int c = 1;
  while (b) {
    if (b & 1) c *= a;
    b >>= 1;
    a *= a;
  }
  return c;
}
