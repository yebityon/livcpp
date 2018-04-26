template<typename T> struct linearMonoid {
  using value_type = pair<T, T>;
  constexpr value_type id() { return {1, 0}; }
  constexpr value_type operator()(const value_type &a, const value_type &b) { return {b.first * a.first, b.first * a.second + b.second}; }
};
