template<typename T> struct RSQ_RAQ_Trait {
  using FoldMonoid = sumMonoid<T>;
  using ActionMonoid = sumMonoid<T>;
  typename FoldMonoid::value_type apply(typename FoldMonoid::value_type t, typename ActionMonoid::value_type q) { return t + q; }
};
