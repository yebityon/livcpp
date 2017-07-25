constexpr int lcm(const int& a, const int& b) {
  return a * b / gcd(a, b);
}
