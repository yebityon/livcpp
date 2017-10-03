struct stringMonoid {
  using value_type = string;
  value_type id() const { return ""; }
  value_type operator()(const value_type &a, const value_type &b) const { return a + b; }
};
