std::vector<std::string> split(const std::string &s, const char &delim) {
  std::istringstream ss(s);
  std::string got;
  std::vector<std::string> v;
  while (std::getline(ss, got, delim)) v.push_back(got);
  return v;
}
