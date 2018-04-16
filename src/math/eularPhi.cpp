int eulerPhi(int n) {
  int cnt = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      cnt -= cnt / i;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) cnt -= cnt / n;
  return cnt;
}
