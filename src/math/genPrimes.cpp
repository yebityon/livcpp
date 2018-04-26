vector<int> genPrimes(const int n) {
  vector<int> primes = eratosthenes(n);
  primes.erase(remove(all(primes), 0), primes.end());
  return primes;
}
