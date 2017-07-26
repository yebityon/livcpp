std::vector<int> primeFactors(int n) {
  std::vector<int> v;
  int i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      v.push_back(i);
      n /= i;
    } else {
      i++;
    }
  }
  v.push_back(n);
  return v;
}
