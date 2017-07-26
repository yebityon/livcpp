constexpr int powint(int a, int b) {
  int c = 1;
  while (b) {
    if (odd(b)) c *= a;
    b >>= 1;
    a *= a;
  }
  return c;
}
