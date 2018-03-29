template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) {
  auto inner = vectors(tail...);
  return vector<decltype(inner)>(x, inner);
}
