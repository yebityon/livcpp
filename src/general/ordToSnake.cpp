std::pair<int, int> ordToSnake(int n, int w) {
  int i = n / w;
  return {i, i & 1 ? w - n % w - 1 : n % w};
}
