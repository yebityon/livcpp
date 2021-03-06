bool canMakePalindromeBySwaps(const string &s) {
  map<char, int> m;
  for (char c : s) m[c]++;
  int odds = 0;
  for (auto &p : m) odds += p.second % 2;
  return odds <= 1;
}
