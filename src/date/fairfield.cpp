int fairfield(int y, int m, const int d) {
  if (m == 1 || m == 2) y--, m += 12;
  return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 428;
}
