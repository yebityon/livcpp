int modstr(const std::string &s, const int m) {
  int a = 0;
  for (auto &c : s) a = (c - '0' + a * 10) % m;
  return a;
}
