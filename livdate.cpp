namespace livdate {
  const std::array<int, 13> mdates = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  constexpr int fairfield(int y, int m, const int &d) {
    if (m == 1 || m == 2) y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 428;
  }

  constexpr int zeller(int y, int m, const int &d) {
    if (m == 1 || m == 2) y--, m += 12;
    int k = y % 100, j = y / 100;
    return (d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j + 6) % 7;
  }

  constexpr bool isLeapYear(const int &y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
  }

  void nextDate(int &y, int &m, int &d) {
    std::array<int, 13> _mdates = mdates;
    _mdates[2] += isLeapYear(y);
    d++;
    if (d == mdates[m] + 1) m++, d = 1;
    if (m == 13) y++, m            = 1;
  }
}
