vector<string> split(const string &s, const string &delim) {
  using string = string;
  vector<string> v;
  string::size_type pos = 0;
  while (pos != string::npos) {
    string::size_type p = s.find(delim, pos);
    if (p == string::npos) {
      v.push_back(s.substr(pos));
      break;
    }
    v.push_back(s.substr(pos, p - pos));
    pos = p + delim.size();
  }
  return v;
}
