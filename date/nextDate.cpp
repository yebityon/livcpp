void nextDate(int &y, int &m, int &d) {
  std::array<int, 13> _mdates = mdates;
  _mdates[2] += isLeapYear(y);
  d++;
  if (d == mdates[m] + 1) m++, d = 1;
  if (m == 13) y++, m            = 1;
}
