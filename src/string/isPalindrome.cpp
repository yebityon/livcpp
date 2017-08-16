template<typename String> bool isPalindrome(const String &s) {
  int n = s.size();
  rep(i, n / 2) if (s[i] != s[n - 1 - i]) return false;
  return true;
}
