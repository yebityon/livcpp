std::vector<int> genPrimes(const int &n) {
  std::vector<int> primes = eratosthenes(n);
  primes.erase(std::remove(all(primes), 0), primes.end());
  return primes;
}
