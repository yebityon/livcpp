template<typename T> struct Monoid {
  T id;
  std::function<T(T, T)> op;
  Monoid(T e, std::function<T(T, T)> f) : id(e), op(f) {}
};
