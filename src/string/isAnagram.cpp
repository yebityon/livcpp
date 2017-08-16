template<typename String> bool isAnagram(String s, String t) {
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());
  return s == t;
}
