int gcd(int a, int b) {
  while (b) a %= b, std::swap(a, b);
  return a;
}
