namespace livstring {
  template<typename V>
  constexpr std::string join(const V &v, const std::string &sep) {
    std::stringstream ss;
    if (v.size()) ss << v[0];
    loop(i, 1, v.size()) ss << sep << v[i];
    return ss.str();
  }

  std::vector<std::string> split(const std::string &s, const char &delim) {
    std::istringstream ss(s);
    std::string got;
    std::vector<std::string> v;
    while (std::getline(ss, got, delim)) v.push_back(got);
    return v;
  }
}
