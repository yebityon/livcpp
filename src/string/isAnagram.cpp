template<typename String> bool isAnagram(String s, String t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}
