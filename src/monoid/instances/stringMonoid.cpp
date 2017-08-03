struct stringMonoid {
  using value_type = string;
  string id() const { return ""; }
  string operator()(const string &a, const string &b) const { return a + b; }
};
