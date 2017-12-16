int digitSum(int x) {
  int s = 0;
  while (x) {
    s += x % 10;
    x /= 10;
  }
  return s;
}