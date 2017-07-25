std::vector<int> divisors(int n) {
  std::vector<int> v;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (n != 1 && i * i != n) v.push_back(n / i);
    }
  }
  std::sort(v.begin(), v.end());
  return v;
}
