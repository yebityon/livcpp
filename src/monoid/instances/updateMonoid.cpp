template<typename T> struct updateMonoid {
  using value_type = pair<bool, T>;
  constexpr value_type id() { return {false, T()}; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return b.first ? b : a; }
};
