constexpr int zeller(int y, int m, const int d) {
  if (m == 1 || m == 2) y--, m += 12;
  int k = y % 100, j = y / 100;
  return (d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j + 6) % 7;
}
